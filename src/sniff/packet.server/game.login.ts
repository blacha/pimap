import { GameServerPacket } from '../gs.packet';
import { GamePacket } from './game.server';
import { Log } from 'bblog';
import { Logger } from '../../util/log';
import { GameDifficulty } from '../../core/difficulty';
import { SessionState } from '../state/session';
import { BitReader } from '../../util/bit/bit.reader';

export class GSPacketGameLogonReceipt extends GamePacket {
    hardcore: boolean;
    difficulty: GameDifficulty;
    static id = GameServerPacket.GameLogonReceipt;

    constructor(bits: BitReader) {
        super(bits);
        this.difficulty = <GameDifficulty>bits.byte();
        bits.skip(8);
        this.hardcore = (bits.byte() & 8) === 8 ? true : false;

    }

    track() {
        if (SessionState.current.map.difficulty == null) {
            SessionState.current.map.difficulty = this.difficulty;
            SessionState.current.map.hardcore = this.hardcore;
        } else {
            Logger.error({ ...this.toJSON() }, 'Game already in progress..');
        }

        return Log.WARN;
    }

    toJSON() {
        return {
            ...super.toJSON(),
            difficulty: GameDifficulty[this.difficulty],
            hardcore: this.hardcore
        };
    }
}

