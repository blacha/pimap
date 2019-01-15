import { Log } from 'bblog';
import { ActType } from '../../core/act';
import { AreaLevel } from '../../core/area';
import { BitConverter } from '../../util/bit/bit.converter';
import { GameServerPacket } from '../gs.packet';
import { GSPacket } from './game.server';


export class GSPacketMapAdd extends GSPacket {
    static id = GameServerPacket.MapAdd;
    act: ActType;
    x: number;
    y: number;

    townId: AreaLevel;

    constructor(data: number[]) {
        super(GSPacketMapAdd.id);
        this.x = BitConverter.ToUInt16(data, 1);
        this.y = BitConverter.ToUInt16(data, 3);
        this.townId = <AreaLevel>data[5];
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
