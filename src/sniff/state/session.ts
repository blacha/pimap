import { GameState } from './game';

export class SessionStore {
    cb: Function;
    games: GameState[] = [];
    currentGame: GameState = null;

    lastUpdate: Date = null;


    get current(): GameState {
        if (this.currentGame == null) {
            this.currentGame = new GameState();
            this.games.push(this.currentGame);
        }

        return this.currentGame;
    }

    closeGame() {
        if (this.currentGame) {
            // this.currentGame.npc.empty();
            this.currentGame.close();
            this.currentGame = null;
        }
    }


    dirty() {
        this.lastUpdate = new Date();
        if (this.cb) {
            this.cb();
        }
    }

    onDirty(cb: Function) {
        this.cb = cb;
    }
}

export const SessionState = new SessionStore();
