import { Log } from 'bblog';
import { GameServerPacket } from '../gs.packet';
import { GSPacket } from './game.server';
import { BitConverter } from '../../util/bit/bit.converter';
import { SessionState } from '../state/session';
import { BitReader } from '../../util/bit/bit.reader';

export class GSPacketPlayerAssign extends GSPacket {
    name: string;
    type: number;
    uid: number;
    x: number;
    y: number;
    static id = GameServerPacket.PlayerAssign;


    constructor(bits: BitReader) {
        super(bits);

        this.uid = bits.uint32();
        this.type = bits.byte();
        this.name = bits.string(16);
        this.x = bits.uint16();
        this.y = bits.uint16();
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

