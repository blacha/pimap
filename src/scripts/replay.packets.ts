import { D2PacketSniffer } from "../sniff/sniffer";
import { readFileSync } from "fs";
import { Logger } from "../util/log";
import { SniffingWebServer } from "../sniff/server";
import { SessionState } from "../sniff/state/session";

const smallPacket = '2019-01-04T21:15-packets.json';
const packets = JSON.parse(readFileSync(`./packet/${smallPacket}`) as any)

const wait = time => new Promise(resolve => setTimeout(resolve, time));
const SPEED = 10;

// console.log = console.trace;
const server = new SniffingWebServer();
server.start();

SessionState.onDirty(_ => server.updateState());

let lastSeq = 0;
let maxPackets = -1;
async function runMe() {
    const sniff = new D2PacketSniffer(null, null);

    let lastTime = null;
    let packetCount = 0;
    for (const packet of packets) {
        packetCount++;
        if (maxPackets > 0 && packetCount > maxPackets) {
            break;
        }
        const time = new Date(packet.time);
        if (lastTime == null) {
            lastTime = time;
        } else {
            const timeDiff = time.getTime() - lastTime;
            lastTime = time;

            if (timeDiff > 50) {
                await wait(timeDiff / SPEED);
            }
        }
        if (lastSeq > packet.seqno) {
            Logger.fatal('Out of order');
        }
        lastSeq = packet.seqno;
        sniff.onPacket(packet.data);
    }

    // console.log(JSON.stringify(SessionState.games, null, 2));
    console.log('Done');
    setTimeout(_ => process.exit(), 60000);
}

runMe()
    .catch(e => console.log(e))
    .then(_ => server.stop());


export interface TCPPacket {
    time: string;
    seqno: number;
    data: number[];
}
