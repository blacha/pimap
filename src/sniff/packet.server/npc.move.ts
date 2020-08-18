import { UnitType } from '../../core/unit';
import { BitReader } from '../../util/bit/bit.reader';
import { GameServerPacket } from '../gs.packet';
import { SessionState } from '../state/session';
import { GamePacket } from './game.server';
import { Log } from 'bblog';

export enum NPCMoveFlags {
  None = 0,
  Stamina0x8000 = 1,
  X0x8000 = 2,
  Y0x8000 = 4,
}

export class GSPacketNPCMove extends GamePacket {
  type: UnitType;
  uid: number;
  x: number;
  y: number;
  static id = GameServerPacket.NpcMove;
  moveType: number; // 0x01 = walk 0x17 = run

  constructor(bits: BitReader) {
    super(bits);

    this.uid = bits.uint32();
    this.moveType = bits.byte();
    this.x = bits.uint16();
    this.y = bits.uint16();

    bits.skip(16); // Unk1
    bits.skip(8); // Unk1
    bits.skip(16); // Unk1
    bits.skip(8); // Unk1
  }

  track() {
    SessionState.current.npc.move(this.uid, this.x, this.y);
    return Log.TRACE;
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

export class GSPacketNPCMoveToTarget extends GamePacket {
  type: UnitType;
  uid: number;
  x: number;
  y: number;
  static id = GameServerPacket.NpcMoveToTarget;
  moveType: number;
  targetType: UnitType;
  targetUid: number;

  constructor(bits: BitReader) {
    super(bits);
    this.uid = bits.uint32();
    this.moveType = bits.byte();

    this.x = bits.uint16();
    this.y = bits.uint16();

    this.targetType = <UnitType>bits.byte();
    this.targetUid = bits.uint32();

    const a = bits.uint16();
    bits.skip(8);
    const b = bits.uint16();
    bits.skip(8);
  }

  track() {
    SessionState.current.npc.move(this.uid, this.x, this.y);
    return 10;
  }

  toJSON() {
    return {
      ...super.toJSON(),
      uid: this.uid,
      x: this.x,
      y: this.y,
      moveType: this.moveType,
      targetType: UnitType[this.targetType],
      targetUid: this.uid,
    };
  }
}

export class GSPacketNPCAttack extends GamePacket {
  uid: number;
  x: number;
  y: number;
  static id = GameServerPacket.NpcAttack;

  constructor(bits: BitReader) {
    super(bits);

    this.uid = bits.uint32();
    bits.uint16(); // attackType
    bits.uint32(); // targetUid
    bits.byte(); // targetType
    // this.AttackType = bits.uint16()(data, 5);
    // this.TargetUID = bits.uint32()(data, 7);
    // this.TargetType = (UnitType) data[11];
    this.x = bits.uint16();
    this.y = bits.uint16();
  }

  track() {
    SessionState.current.npc.move(this.uid, this.x, this.y);

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
