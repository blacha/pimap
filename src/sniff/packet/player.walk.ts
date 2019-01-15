import { Log } from 'bblog';

import { GameServerPacket } from '../gs.packet';
import { GSPacket } from './game.server';
import { BitConverter } from '../../util/bit/bit.converter';
import { SessionState } from '../state/session';

export enum WalkVerifyFlags {
    None = 0,
    Stamina0x8000 = 1,
    X0x8000 = 2,
    Y0x8000 = 4
}

export class GSPacketWalkVerify extends GSPacket {

    x: number;
    y: number;
    static id = GameServerPacket.WalkVerify;


    constructor(data: number[]) {
        super(GSPacketWalkVerify.id);

        this.x = BitConverter.ToUInt16(data, 3);
        if ((this.x & 0x8000) === 0x8000) {
            this.x ^= 0x8000;
        }
        this.x = this.x * 2;

        this.y = BitConverter.ToUInt16(data, 5);
        if ((this.y & 0x8000) === 0x8000) {
            this.y ^= 0x8000;
        }
        this.y = this.y * 2;

    }

    track() {
        SessionState.current.move(SessionState.current.player.uid, this.x, this.y);
        return Log.DEBUG;
    }

    toJSON() {
        return {
            ...super.toJSON(),
            x: this.x,
            y: this.y
        };
    }
}


