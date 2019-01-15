import { Log } from 'bblog';
import { UnitType } from '../../core/unit';
import { GameServerPacket } from '../gs.packet';
import { GSPacket } from './game.server';
import { BitConverter } from '../../util/bit/bit.converter';
import { SessionState } from '../state/session';

export class GSPacketPlayerReassign extends GSPacket {
    type: UnitType;
    life: number;
    uid: number;
    x: number;
    y: number;
    static id = GameServerPacket.PlayerReassign;


    constructor(data: number[]) {
        super(GSPacketPlayerReassign.id);

        this.type = <UnitType>data[1];
        this.uid = BitConverter.ToUInt32(data, 2);
        this.x = BitConverter.ToUInt16(data, 6);
        this.y = BitConverter.ToUInt16(data, 8);
        // this.life = data[12];

    }

    track() {
        SessionState.current.move(this.uid, this.x, this.y);
        return Log.INFO;
    }

    toJSON() {
        return {
            ...super.toJSON(),
            life: this.life,
            type: UnitType[this.type],
            uid: this.uid,
            x: this.x,
            y: this.y
        };
    }
}

