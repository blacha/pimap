import { Log } from 'bblog';
import { ActType } from '../../core/act';
import { AreaLevel } from '../../core/area';
import { GameServerPacket } from '../gs.packet';
import { GamePacket } from './game.server';
import { BitReader } from '../../util/bit/bit.reader';
import { SessionState } from '../state/session';

export class GSPacketLoadAct extends GamePacket {
  static id = GameServerPacket.LoadAct;
  act: ActType;
  mapId: number;
  townArea: AreaLevel;

  constructor(br: BitReader) {
    super(br);
    this.act = <ActType>br.byte();
    this.mapId = br.uint32();
    this.townArea = <AreaLevel>br.uint16();
    br.skip(32); // Unknown;
  }

  track() {
    SessionState.current.map.id = this.mapId;
    SessionState.current.map.act = this.act;
    SessionState.current.map.town = this.townArea;

    SessionState.current.npc.empty();
    SessionState.current.object.empty();
    return Log.WARN;
  }

  toJSON() {
    return {
      ...super.toJSON(),
      mapId: this.mapId,
      act: ActType[this.act],
      town: AreaLevel[this.townArea],
    };
  }
}
