import { Log } from 'bblog';
import { BitReader } from '../../util/bit/bit.reader';
import { GameServerPacket } from '../gs.packet';
import { SessionState } from '../state/session';
import { GamePacket } from './game.server';


export class GSPacketPlayerInGame extends GamePacket {
    level: number;
    uid: number;
    static id = GameServerPacket.PlayerInGame;


    constructor(bits: BitReader) {
        super(bits);

        bits.skipByte(2);
        this.uid = bits.uint32() // (data, 3);
        // TODO
        bits.skipByte(17)
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

