import { GameServerPacket } from '../gs.packet';
import { GamePacket } from './game.server';
import { SessionState } from '../state/session';
import { BitReader } from '../../util/bit/bit.reader';

export class GSPacketGameOver extends GamePacket {
  static id = GameServerPacket.GameOver;

  track() {
    SessionState.closeGame();
    return true;
  }
}
