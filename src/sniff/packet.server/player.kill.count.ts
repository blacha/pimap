import { GameServerPacket } from '../gs.packet';
import { GamePacket } from './game.server';
import { BitConverter } from '../../util/bit/bit.converter';
import { SessionState } from '../state/session';
import { BitReader } from '../../util/bit/bit.reader';


export class GSPacketPlayerKillCount extends GamePacket {
    static id = GameServerPacket.PlayerKillCount;

    uid: number;
    count: number;
    constructor(bits: BitReader) {
        super(bits);

        this.uid = bits.uint32();
        this.count = bits.uint16();
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


