import { Log } from 'bblog';
import { ActType } from '../../core/act';
import { AreaLevel } from '../../core/area';
import { BitConverter } from '../../util/bit/bit.converter';
import { GameServerPacket } from '../gs.packet';
import { GamePacket } from './game.server';
import { BitReader } from '../../util/bit/bit.reader';


export class GSPacketMapAdd extends GamePacket {
    static id = GameServerPacket.MapAdd;
    act: ActType;
    x: number;
    y: number;

    townId: AreaLevel;

    constructor(bits: BitReader) {
        super(bits);
        this.x = bits.uint16();
        this.y = bits.uint16();
        this.townId = <AreaLevel>bits.byte();
    }

    track() {
        // Logger.warn({ ... this.toJSON() }, 'MapAdd');
        // SessionState.currentGame.map.townId = this.townId;
        return Log.TRACE;
    }

    toJSON() {
        return {
            ...super.toJSON(),
            x: this.x,
            y: this.y,
            town: AreaLevel[this.townId],
            townId: this.townId
        };
    }
}
