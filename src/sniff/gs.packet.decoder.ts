import { GameServerPacket } from './gs.packet';
import { GamePacket, GSPacketMaker } from './packet.server/game.server';
import { GAME_SERVER_PACKETS } from './packet.server';
import { BitReader } from '../util/bit/bit.reader';

export class GSPacketBuilder {
    static packetMap: { [key: string]: GSPacketMaker } = {};


    static register(packetId: GameServerPacket, constructor: GSPacketMaker) {
        this.packetMap[packetId] = constructor;
    }

    static packet(packetId: GameServerPacket, bytes: number[]): null | GamePacket {
        const packetMaker = this.packetMap[packetId];
        if (packetMaker == null) {
            return null;
        }

        return packetMaker(bytes);
    }
}


for (const PacketType of GAME_SERVER_PACKETS) {
    GSPacketBuilder.register(PacketType.id, bytes => new PacketType(new BitReader(bytes)));
}

