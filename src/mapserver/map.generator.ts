import { D2Difficulty } from "../util/d2/d2.difficulty";
import { toHexString } from "../util/to.hex";
import { Log } from "bblog";
import { D2_PATH, PI_MAP_COMMAND } from "./config";
import * as PromiseQueue from 'promise-queue';
import { runCommand } from "../util/process";

// Max one command at a time with 100 requests in queue
const commandQueue = new PromiseQueue(1, 100)
export class D2MapGenerator {
    maps = {};

    constructor() { }

    mapId(seed: number, difficulty: D2Difficulty) {
        return `${toHexString(seed, 8)}_${difficulty}`;
    }

    hasMap(seed: number, difficulty: D2Difficulty) {
        const mapId = this.mapId(seed, difficulty);
        return this.maps[mapId] != null;
    }

    async getMap(seed: number, difficulty: D2Difficulty, levelCode: number, log: Log): Promise<D2MapData> {
        if (!this.hasMap(seed, difficulty)) {
            await commandQueue.add(() => this.generateMap(seed, difficulty, log));
        };

        return null;
    }

    async generateMap(seed: number, difficulty: D2Difficulty, log: Log) {

        const args = [PI_MAP_COMMAND, D2_PATH, seed, D2Difficulty[difficulty]];
        log.info({ args: args.join(' ') }, 'Generate map');


        try {
            const result = await runCommand('wine', args);
            console.log(result);

        } catch (e) {
            console.log('error', e);
        }

        // await new Promise(resolve => setTimeout(resolve, 1000));
    }
}

export interface Point {
    x: number;
    y: number;
}

export interface D2MapData {
    id: number;
    name: string;
    size: { width: number; height: number; };
    origin: Point;
    objects: D2MapObject[];
    map: number[][];
}

export interface D2MapObject extends Point {
    id: number;
    type: 'chest' | 'waypoint' | 'npc'
}


export const MapGenerator = new D2MapGenerator();
