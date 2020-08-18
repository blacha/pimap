import { GameServerPacket } from '../gs.packet';
import { GamePacket } from './game.server';
import { BitConverter } from '../../util/bit/bit.converter';
import { BitReader } from '../../util/bit/bit.reader';
import { SessionState } from '../state/session';

export enum LifeManaFlags {
  None = 0,
  Life0x8000 = 1,
  Mana0x8000 = 2,
  Mana0x4000 = 4,
}
export class GSPacketPlayerLifeManaChange extends GamePacket {
  static id = GameServerPacket.PlayerLifeManaChange;

  life: number;
  mana: number;
  flags: LifeManaFlags = 0;
  x: number;
  y: number;
  stamina: number;

  constructor(bits: BitReader) {
    super(bits);

    // Why are these 15 bit numbers?
    this.life = bits.bits(15);
    this.mana = bits.bits(15);
    this.stamina = bits.bits(15);

    this.x = bits.bits(15);
    bits.skip(1); // Unknown
    this.y = bits.bits(15);

    bits.skip(20);
  }

  track() {
    if (this.x > 0 && this.y > 0) {
      SessionState.current.move(SessionState.current.player.uid, this.x, this.y);
      return 10;
    }
    return 0;
  }

  toJSON() {
    return {
      ...super.toJSON(),
      life: this.life,
      mana: this.mana,
      x: this.x,
      y: this.y,
    };
  }
}
