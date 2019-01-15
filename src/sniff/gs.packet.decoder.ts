import { GameServerPacket } from './gs.packet';
import { GSPacket, GSPacketMaker } from './packet/game.server';
import { PACKETS } from './packet';

export class GSPacketBuilder {
    static packetMap: { [key: string]: GSPacketMaker } = {};


    static register(packetId: GameServerPacket, constructor: GSPacketMaker) {
        this.packetMap[packetId] = constructor;
    }

    static packet(packetId: GameServerPacket, bytes: number[]): null | GSPacket {
        const packetMaker = this.packetMap[packetId];
        if (packetMaker == null) {
            return null;
        }

        return packetMaker(bytes);
    }
}


for (const PacketType of PACKETS) {
    GSPacketBuilder.register(PacketType.id, bytes => new PacketType(bytes));
}

