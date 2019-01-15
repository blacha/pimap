import { UnitType } from '../../core/unit';
import { GameServerPacket } from '../gs.packet';
import { GSPacket } from './game.server';
import { BitConverter } from '../../util/bit/bit.converter';
import { SessionState } from '../state/session';

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


    constructor(data: number[]) {
        super(GSPacketNPCMove.id);

        this.uid = BitConverter.ToUInt32(data, 1);
        this.x = BitConverter.ToUInt16(data, 6);
        this.y = BitConverter.ToUInt16(data, 8);

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


    constructor(data: number[]) {
        super(GSPacketNPCMoveToTarget.id);


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


    constructor(data: number[]) {
        super(GSPacketNPCAttack.id);

        this.uid = BitConverter.ToUInt32(data, 1);
        // this.AttackType = BitConverter.ToUInt16(data, 5);
        // this.TargetUID = BitConverter.ToUInt32(data, 7);
        // this.TargetType = (UnitType) data[11];
        this.x = BitConverter.ToUInt16(data, 12);
        this.y = BitConverter.ToUInt16(data, 14);
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
