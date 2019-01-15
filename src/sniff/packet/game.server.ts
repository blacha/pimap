import { Log } from 'bblog';
import { GameServerPacket } from '../gs.packet';

export type GSPacketMaker = (bytes: number[]) => GSPacket;

export class GSPacket {
    id: GameServerPacket;
    time: Date;

    constructor(id: GameServerPacket) {
        this.id = id;
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


