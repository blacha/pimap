import { GamePacket } from './game.server';
import { GameObjectMode } from '../../core/object';
import { GameServerPacket } from '../gs.packet';
import { BitReader } from '../../util/bit/bit.reader';
import { SessionState } from '../state/session';
import { UnitType } from '../../core/unit';

export class GSPacketGameObjectModeChange extends GamePacket {
  mode: GameObjectMode;

  uid: number;
  static id = GameServerPacket.GameObjectModeChange;
  unitType: UnitType;
  isReversable: boolean;

  constructor(bits: BitReader) {
    super(bits);

    this.unitType = <UnitType>bits.byte();
    this.uid = bits.uint32(); //(data, 2);
    bits.skip(8);
    this.isReversable = bits.byte() === 0x01;
    this.mode = <GameObjectMode>bits.uint32();
  }

  track() {
    const obj = SessionState.current.object.get(this.uid);
    if (obj == null) {
      return 0;
    }
    if (obj.type === 'Warp') {
      return 0;
    }

    if (this.mode === GameObjectMode.Opened || this.mode === GameObjectMode.Operating) {
      SessionState.current.object.remove(this.uid);
      return 10;
    }

    return 10;
  }

  toJSON() {
    return {
      ...super.toJSON(),
      uid: this.uid,
      mode: this.mode,
      modeName: GameObjectMode[this.mode],
      unitType: UnitType[this.unitType],
      isReversable: this.isReversable,
    };
  }
}
