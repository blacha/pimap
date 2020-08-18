import { GameServerPacket } from './gs.packet';
import { GamePacket, GSPacketMaker } from './packet.server/game.server';
import { GameServerPackets } from './packet.server';
import { BitReader } from '../util/bit/bit.reader';

export class GSPacketBuilder {
  static packetMap: { [key: string]: GSPacketMaker } = {};

  static register(packetId: GameServerPacket, constructor: GSPacketMaker): void {
    this.packetMap[packetId] = constructor;
  }

  static packet(packetId: GameServerPacket, bytes: number[]): null | GamePacket {
    const packetMaker = this.packetMap[packetId];
    if (packetMaker == null) return null;
    return packetMaker(bytes);
  }
}

for (const PacketType of GameServerPackets) {
  GSPacketBuilder.register(PacketType.id, (bytes) => new PacketType(new BitReader(bytes)));
}
