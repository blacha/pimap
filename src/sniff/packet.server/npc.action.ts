import { GameServerPacket } from '../gs.packet';
import { GamePacket } from './game.server';
import { BitConverter } from '../../util/bit/bit.converter';
import { BitReader } from '../../util/bit/bit.reader';

export class GSPacketNPCAction extends GamePacket {
  y: number;
  x: number;
  uid: number;

  static id = GameServerPacket.NpcAction;

  constructor(bits: BitReader) {
    super(bits);

    this.uid = bits.uint32();
    bits.skipByte(7);
    this.x = bits.uint16();
    this.y = bits.uint16();
  }

  track() {
    // console.log('NPCAction', this.uid, this.x, this.y);
    // SessionState.current.npc.move(this.uid, this.x, this.y);
    return 10;
  }

  toJSON() {
    return {
      ...super.toJSON(),
      uid: this.uid,
      x: this.x,
      y: this.y,
    };
  }
}
