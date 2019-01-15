import { Log } from 'bblog';
import { ActType } from '../../core/act';
import { AreaLevel } from '../../core/area';
import { GameServerPacket } from '../gs.packet';
import { GSPacket } from './game.server';
import { BitReader } from '../../util/bit/bit.reader';
import { SessionState } from '../state/session';

export class GSPacketLoadAct extends GSPacket {
    static id = GameServerPacket.LoadAct;
    act: ActType;
    mapId: number;
    townArea: AreaLevel;

    constructor(data: number[]) {
        super(GSPacketLoadAct.id);
        const br = new BitReader(data, 8);
        this.act = <ActType>br.bits(8);
        this.mapId = br.bits(32); //BitConverter.ToUInt32(data, 2);
        this.townArea = <AreaLevel>br.bits(16); //.ToUInt16(data, 6);
    }

    track() {
        SessionState.current.map.id = this.mapId;
        SessionState.current.map.act = this.act;
        SessionState.current.map.town = this.townArea;

        SessionState.current.npc.empty();
        SessionState.current.object.empty();
        // Logger.warn({ ... this.toJSON() }, 'LoadAct');
        return Log.WARN;
    }

    toJSON() {
        return {
            ...super.toJSON(),
            mapId: this.mapId,
            act: ActType[this.act],
            town: AreaLevel[this.townArea]
        };
    }
}
