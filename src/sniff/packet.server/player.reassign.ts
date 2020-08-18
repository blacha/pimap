import { Log } from 'bblog';
import { UnitType } from '../../core/unit';
import { GameServerPacket } from '../gs.packet';
import { GamePacket } from './game.server';
import { BitConverter } from '../../util/bit/bit.converter';
import { SessionState } from '../state/session';
import { BitReader } from '../../util/bit/bit.reader';

export class GSPacketPlayerReassign extends GamePacket {
  type: UnitType;
  uid: number;
  x: number;
  y: number;
  static id = GameServerPacket.PlayerReassign;
  isUpdate: boolean;

  constructor(bits: BitReader) {
    super(bits);

    this.type = <UnitType>bits.byte();
    this.uid = bits.uint32();
    this.x = bits.uint16();
    this.y = bits.uint16();

    this.isUpdate = bits.bit() === 1;
    bits.skip(7);
  }

  track() {
    SessionState.current.move(this.uid, this.x, this.y);
    return Log.INFO;
  }

  toJSON() {
    return {
      ...super.toJSON(),
      type: UnitType[this.type],
      uid: this.uid,
      x: this.x,
      y: this.y,
    };
  }
}
