import { Log } from 'bblog';
import { GameServerPacket } from '../gs.packet';
import { BitReader } from '../../util/bit/bit.reader';

export type GSPacketMaker = (bytes: number[]) => GamePacket;

export class GamePacket {
    id: GameServerPacket;
    time: Date;

    constructor(bits: BitReader) {
        this.id = bits.byte();
        this.time = new Date();
    }

    toJSON() {
        return {
            id: GameServerPacket[this.id],
            time: this.time.toISOString()
        };
    }

    /** Update the session state with this packet */
    track(): boolean | number {
        return Log.TRACE;
    }
}


