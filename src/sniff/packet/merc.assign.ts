import { Log } from 'bblog';
import { GameServerPacket } from '../gs.packet';
import { GSPacket } from './game.server';
import { BitConverter } from '../../util/bit/bit.converter';
import { SessionState } from '../state/session';

export class GSPacketMercAssignment extends GSPacket {
    mercId: number;
    uid: number;

    static id = GameServerPacket.MercAssignment;


    constructor(data: number[]) {
        super(GSPacketMercAssignment.id);
        this.uid = BitConverter.ToUInt32(data, 4);
        this.mercId = BitConverter.ToUInt16(data, 8);
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

