import { Difficulty } from '@diablo2/data';
import { MessageType } from '../core/game.json';
import { D2MapObj } from '../core/map.js';
import { Logger } from '../util/log.js';
import { State } from './state.js';

const MAP_SERVER = 'http://localhost:8899';
export class WS {
  static error: Error;
  static closed = true;
  static start(websocketServerLocation: string): void {
    WS.error = null;
    const ws = new WebSocket(websocketServerLocation);

    ws.onmessage = function (ev) {
      WS.closed = false;
      WS.error = null;
      const message = JSON.parse(ev.data);
      if (message.type === MessageType.STATE) {
        State.update(message.data);
      } else {
      }
    };
    ws.onerror = function (e) {
      WS.error = new Error(e as any);
    };
    ws.onclose = function () {
      WS.closed = true;
      setTimeout(() => WS.start(websocketServerLocation), 5000);
    };
  }

  static async loadMaps(seed: number, difficulty: Difficulty): Promise<D2MapObj> {
    if (seed == null) return null;
    if (difficulty == null) return null;
    const mapUrl = `${MAP_SERVER}/v1/map/${seed}/${Difficulty[difficulty]}.json`;
    Logger.info({ mapUrl }, 'GetMaps');

    try {
      const res = await fetch(mapUrl);
      const mapRes = await res.json();
      return mapRes['maps'];
    } catch (e) {
      return null;
    }
  }
}
