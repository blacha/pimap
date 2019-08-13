import { MessageType } from "../core/game.json";
import { State } from "./state.js";
// import * as jsondiffpatch from 'jsondiffpatch';
import { GameDifficulty } from "../core/difficulty.js";
import { D2MapObj } from "../mapserver/map.generator.js";
import { Logger } from "../util/log.js";

const MAP_SERVER = 'http://localhost:8899'
export class WS {
    static error: Error;
    static closed: boolean = true;
    static start(websocketServerLocation) {
        WS.error = null;
        const ws = new WebSocket(websocketServerLocation);

        ws.onmessage = function(ev) {
            WS.closed = false;
            WS.error = null;
            const message = JSON.parse(ev.data);
            if (message.type === MessageType.STATE) {
                State.update(message.data);
            } else {

            }
        };
        ws.onerror = function(e) {
            WS.error = new Error(e as any);
        };
        ws.onclose = function() {
            WS.closed = true;
            setTimeout(function() { WS.start(websocketServerLocation); }, 5000);
        };
    }

    static async loadMaps(seed: number, difficulty: GameDifficulty): Promise<D2MapObj> {
        if (seed == null) {
            return null;
        }
        if (difficulty == null) {
            return null;
        }
        const mapUrl = `${MAP_SERVER}/map/${seed}/${GameDifficulty[difficulty]}.json`;
        Logger.info({ mapUrl }, 'GetMaps');

        const res = await fetch(mapUrl);
        const mapRes = await res.json();
        return mapRes['maps'];
    }
}
