import { UnitType } from '../../core/unit';
import { BitReader } from '../../util/bit/bit.reader';
import { GameServerPacket } from '../gs.packet';
import { SessionState } from '../state/session';
import { GSPacket } from './game.server';

export enum NPCMoveFlags {
    None = 0,
    Stamina0x8000 = 1,
    X0x8000 = 2,
    Y0x8000 = 4
}

export class GSPacketNPCMove extends GSPacket {
    type: UnitType;
    uid: number;
    x: number;
    y: number;
    static id = GameServerPacket.NpcMove;


    constructor(bits: BitReader) {
        super(bits);

        this.uid = bits.uint32();
        bits.skipByte();
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
            y: this.y
        };
    }
}

export class GSPacketNPCMoveToTarget extends GSPacket {
    type: UnitType;
    uid: number;
    x: number;
    y: number;
    static id = GameServerPacket.NpcMoveToTarget;


    constructor(bits: BitReader) {
        super(bits);
    }

    track() {
        return 10;
    }

    toJSON() {
        return {
            ...super.toJSON(),
            uid: this.uid,
            x: this.x,
            y: this.y
        };
    }
}



export class GSPacketNPCAttack extends GSPacket {
    uid: number;
    x: number;
    y: number;
    static id = GameServerPacket.NpcAttack;


    constructor(bits: BitReader) {
        super(bits);

        this.uid = bits.uint32();
        bits.uint16() // attackType
        bits.uint32() // targetUid
        bits.byte() // targetType
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
            y: this.y
        };
    }
}
