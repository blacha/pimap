import { Log } from 'bblog';
import { GameServerPacket } from '../gs.packet';
import { GSPacket } from './game.server';
import { BitConverter } from '../../util/bit/bit.converter';
import { SessionState } from '../state/session';
import { BitReader } from '../../util/bit/bit.reader';

export class GSPacketMercAssignment extends GSPacket {
    mercId: number;
    uid: number;

    static id = GameServerPacket.MercAssignment;


    constructor(bits: BitReader) {
        super(bits);
        bits.skipByte(3);
        this.uid = bits.uint32();
        this.mercId = bits.uint16();
    }

    track() {
        if (SessionState.current.isMe(this.uid)) {
            SessionState.current.player.mercId = this.mercId;
        }
        return Log.WARN;
    }

    toJSON() {
        return {
            ...super.toJSON(),
            uid: this.uid,
            mercId: this.mercId
        };
    }
}

