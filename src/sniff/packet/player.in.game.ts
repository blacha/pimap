import { Log } from 'bblog';
import { GameServerPacket } from '../gs.packet';
import { GSPacket } from './game.server';
import { SessionState } from '../state/session';
import { BitConverter } from '../../util/bit/bit.converter';
import { BitReader } from '../../util/bit/bit.reader';


export class GSPacketPlayerInGame extends GSPacket {
    level: number;
    uid: number;
    static id = GameServerPacket.PlayerInGame;


    constructor(bits: BitReader) {
        super(bits);

        bits.skipByte(1);
        this.uid = bits.uint32() // (data, 3);
        // TODO
        this.level = bits.uint16() // (data, 24);
    }

    track() {
        SessionState.current.setPlayerLevel(this.uid, this.level);
        return Log.INFO;
    }


    toJSON() {
        return {
            ...super.toJSON(),
            uid: this.uid,
            playerLevel: this.level
        };
    }
}

