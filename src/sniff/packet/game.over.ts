import { GameServerPacket } from '../gs.packet';
import { GSPacket } from './game.server';
import { SessionState } from '../state/session';

export class GSPacketGameOver extends GSPacket {
    static id = GameServerPacket.GameOver;

    constructor(data: number[]) {
        super(GSPacketGameOver.id);
    }

    track() {
        SessionState.closeGame();
        return true;
    }
}

