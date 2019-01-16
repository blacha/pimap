import { Log } from 'bblog';
import { GameServerPacket } from '../gs.packet';
import { GSPacket } from './game.server';
import { BitConverter } from '../../util/bit/bit.converter';
import { SessionState } from '../state/session';
import { BitReader } from '../../util/bit/bit.reader';

export class GSPacketAboutPlayer extends GSPacket {
    level: number;
    uid: number;

    static id = GameServerPacket.AboutPlayer;

    constructor(bits: BitReader) {
        super(bits);

        this.uid = bits.uint32();
        bits.skipByte(2);
        this.level = bits.uint16();
    }

    track() {
        SessionState.current.setPlayerLevel(this.uid, this.level);
        return Log.DEBUG;
    }

    toJSON() {
        return {
            ...super.toJSON(),
            uid: this.uid,
            level: this.level
        };
    }
}

