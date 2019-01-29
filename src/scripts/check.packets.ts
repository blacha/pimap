import { readFileSync } from "fs";
import { D2PacketSniffer } from "../sniff/sniffer";

// const packets = JSON.parse(readFileSync('./packet/2019-01-04T21:15-packets.json') as any)

const bigPacket = '2018-03-06T07:01-packets.json';
const smallPacket = '2019-01-04T21:15-packets.json';
const packets = JSON.parse(readFileSync(`./packet/${smallPacket}`) as any)

const sniffer = new D2PacketSniffer(null, null);
for (const packet of packets) {
    // console.log(packet.seqno)

    // console.log(Object.keys(packet));
    sniffer.onPacket(packet.data);
}
