import { Log } from 'bblog';
import { GameServerPacket } from '../gs.packet';
import { BitReader } from '../../util/bit/bit.reader';

export type GSPacketMaker = (bytes: number[]) => GSPacket;

export class GSPacket {
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

    track(): boolean | number {
        return Log.TRACE;
    }
}


