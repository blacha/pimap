import { Log } from 'bblog';
import { GameServerPacket } from '../gs.packet';
import { BitReader } from '../../util/bit/bit.reader';

export type GSPacketMaker = (bytes: number[]) => GamePacket;

export class GamePacket {
    id: GameServerPacket;
    time: number;
    bits: BitReader;

    constructor(bits: BitReader) {
        this.bits = bits;
        this.id = bits.byte();
        this.time = Date.now();
    }

    toJSON() {
        return {
            id: GameServerPacket[this.id],
            time: this.time
        };
    }

    /** Update the session state with this packet */
    track(): boolean | number {
        return Log.TRACE;
    }
}


