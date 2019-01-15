import { GameServerPacket } from '../gs.packet';
import { GSPacket } from './game.server';
import { BitConverter } from '../../util/bit/bit.converter';
import { SessionState } from '../state/session';


export class GSPacketPlayerKillCount extends GSPacket {
    static id = GameServerPacket.PlayerKillCount;

    uid: number;
    count: number;
    constructor(data: number[]) {
        super(GSPacketPlayerKillCount.id);

        this.uid = BitConverter.ToUInt32(data, 1);
        this.count = BitConverter.ToUInt16(data, 5);
    }

    track() {
        SessionState.current.kills(this.uid, this.count);
        return false;
    }
    toJSON() {
        return {
            ...super.toJSON(),
            uid: this.uid,
            count: this.count
        };
    }
}


