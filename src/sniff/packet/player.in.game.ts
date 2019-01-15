import { Log } from 'bblog';
import { GameServerPacket } from '../gs.packet';
import { GSPacket } from './game.server';
import { SessionState } from '../state/session';
import { BitConverter } from '../../util/bit/bit.converter';


export class GSPacketPlayerInGame extends GSPacket {
    level: number;
    uid: number;
    static id = GameServerPacket.PlayerInGame;


    constructor(data: number[]) {
        super(GSPacketPlayerInGame.id);

        this.uid = BitConverter.ToUInt32(data, 3);
        this.level = BitConverter.ToUInt16(data, 24);
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

