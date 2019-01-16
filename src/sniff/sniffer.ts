import { writeFileSync } from 'fs';
import { GameServerPacket } from './gs.packet';
import { GSPacketBuilder } from './gs.packet.decoder';
import { Huffman } from './huffman';
import { IGNORE } from './packet.ignore';
import { GSPacketSize } from './packet.size';
import { GSPacket } from './packet/game.server';
import { BitConverter } from '../util/bit/bit.converter';
import { Logger } from '../util/log';
import { toHexString } from '../util/to.hex';
import { SessionState } from './state/session';
import * as pcap from 'pcap2';

let skipped = 0;
const TRACE = {
    // 0x1: true, 0x0: true, 0x2: true
};
export class D2PacketSniffer {

    trace: boolean = false;
    buffer: number[];
    bufferCount: number = 0;
    localIp: string;
    networkAdapter: string;

    constructor(localIp: string, networkAdapter: string) {
        this.localIp = localIp;
        this.networkAdapter = networkAdapter
    }

    resetBuffer() {
        this.bufferCount = 0;
        this.buffer = null;
    }
    getBytes(bytes: number[]) {
        if (this.bufferCount > 5) {
            this.resetBuffer();
            return bytes;
        }

        if (this.buffer) {
            this.bufferCount++;
            return this.buffer.concat(bytes);
        }
        return bytes;
    }

    packetCount = 0;
    onPacket(inBytes: number[], attemptCount = 0) {
        if (attemptCount > 100) {
            return;
        }
        this.packetCount++;
        const log = Logger.child({ $in: this.packetCount });

        if (inBytes.length > 1 && inBytes[0] === 0xAF && inBytes[1] === 0x01) {
            return;
        }

        const bytes = this.getBytes(inBytes);

        const packetInfo = Huffman.getPacketInfo(bytes);
        const packetInfoSize = packetInfo.offset + packetInfo.length;
        // console.log(packetInfo, bytes.length, bytes.length - packetInfoSize);

        if (packetInfoSize > bytes.length) {
            this.buffer = bytes;
            log.info({ ...packetInfo, have: bytes.length }, 'Buffering packets');
            return;
        }

        // log.info({ ...packetInfo, bytes: bytes.length }, 'Packet..');
        const compressedData = bytes.slice(packetInfo.offset, packetInfo.length + packetInfo.offset);

        let extraData = [];
        if (bytes.length > packetInfoSize) {
            extraData = bytes.slice(packetInfo.length + packetInfo.offset);
            log.warn({ data: extraData.length }, 'Extra data');
        }
        let packetData = Huffman.decompress(compressedData);

        const packetsMade: GSPacket[] = [];
        let packetsInside = 0;
        while (packetData.length > 0) {
            let $si = packetsInside === 0 ? undefined : packetsInside;
            const packetId = packetData[0] as GameServerPacket;

            const packetName = GameServerPacket[packetId];
            let packetSize = GSPacketSize.getPacketSize(packetData);

            if (packetSize == null) {
                const packets = packetData.map(c => c.toString(16));
                log.error({ packetName, packetId, length: packets.length, data: packetData.join(',') }, 'Invalid packet size "' + packetName + '"');
                this.resetBuffer();
                return;
            }

            if (packetSize === 0) {
                log.error({ packetId: toHexString(packetId, 2) }, 'Unkown Packet..');
                this.resetBuffer();
                return;
            }

            const packet = packetData.slice(0, packetSize);
            packetData = packetData.slice(packetSize);
            packetsInside++;


            const packetMade = GSPacketBuilder.packet(packetId, packet);

            if (packetMade == null) {
                if (IGNORE[packetId] == null) {
                    log.info({ $si, packetName, packetId: toHexString(packetId, 2) }, 'SkipType');
                }
                continue;
            }
            packetsMade.push(packetMade);
        }


        let dirty = false;
        for (const packet of packetsMade) {
            const level = packet.track();
            const packetName = GameServerPacket[packet.id];
            if (level > 0) {
                dirty = true;
            }

            if (level >= 20) {
                log.info({ ...packet.toJSON(), level }, packetName);
            }
            const pkt = packet.toJSON()
            delete pkt.time;
            console.log(JSON.stringify(pkt));
        }
        if (dirty) {
            SessionState.dirty();
        }

        if (extraData && extraData.length > 0) {
            this.onPacket(extraData, attemptCount + 1);
        }
    }

    listen(net?: string) {
        const pcapSession = new pcap.Session(this.networkAdapter, {
            filter: `port 4000`,
            timeout: 150
        });
        const sniffId = new Date().toISOString().substr(0, 16);
        let packetWriteTimeout = null;
        function writePackets() {
            if (packetWriteTimeout != null) {
                return;
            }
            packetWriteTimeout = setTimeout(_ => {
                Logger.info({ packets: packets.length }, 'Write packets');
                writeFileSync(`${sniffId}-packets.json`, JSON.stringify(packets));
                packetWriteTimeout = null;
            }, 2500);

        }
        Logger.info('Sniffing...');

        const packets = [];
        let lastSeq = 0;

        function checkLocalPacket(data: number[]) {
            const packetId = data[0];
            // Walking / Running
            if (packetId === 0x01 || packetId === 0x02 || packetId === 0x03) {
                const x = BitConverter.ToUInt16(data, 1);
                const y = BitConverter.ToUInt16(data, 3);

                SessionState.current.moveMaybe(x, y);
                SessionState.dirty();
            }
        }

        pcapSession.on('packet', rawPacket => {
            var packet = pcap.decode.packet(rawPacket);
            // tcpTracker.track_packet(packet);
            // const data = packet.payload.payload.payload.data;

            const ipv4 = packet.payload.payload;
            const isLocal = ipv4.saddr.addr.join('.') === this.localIp;

            if (isLocal) {
                if (ipv4.payload.data == null) {
                    return;
                }
                checkLocalPacket(ipv4.payload.data.toJSON().data);
                return;
            }

            const payload = ipv4.payload;
            if (payload.data == null) {
                return;
            }
            const buffer = payload.data.toJSON().data;

            const output = {
                time: new Date().toISOString(),
                seqno: payload.seqno,
                data: buffer
            };

            if (lastSeq > packet.seqno) {
                Logger.fatal('Out of order');
            }

            lastSeq = packet.seqno;
            if (this.trace) {
                packets.push(output);
                writePackets();
            }
            this.onPacket(buffer);
        });
    }
}
