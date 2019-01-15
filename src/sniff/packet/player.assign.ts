import { Log } from 'bblog';
import { GameServerPacket } from '../gs.packet';
import { GSPacket } from './game.server';
import { BitConverter } from '../../util/bit/bit.converter';
import { SessionState } from '../state/session';

export class GSPacketPlayerAssign extends GSPacket {
    name: string;
    type: number;
    uid: number;
    x: number;
    y: number;
    static id = GameServerPacket.PlayerAssign;


    constructor(data: number[]) {
        super(GSPacketPlayerAssign.id);

        this.uid = BitConverter.ToUInt32(data, 1);
        this.type = data[5];
        this.name = BitConverter.getNullString(data, 6, 16);
        this.x = BitConverter.ToUInt16(data, 22);
        this.y = BitConverter.ToUInt16(data, 24);
    }

    track() {
        SessionState.current.addPlayer(this.uid, this.name);
        SessionState.current.move(this.uid, this.x, this.y);
        return Log.DEBUG;
    }


    toJSON() {
        return {
            ...super.toJSON(),
            uid: this.uid,
            x: this.x,
            y: this.y,
            name: this.name
        };
    }
}

