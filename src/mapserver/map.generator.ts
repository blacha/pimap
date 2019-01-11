import { Log } from "bblog";
import * as PromiseQueue from 'promise-queue';
import { D2Difficulty } from "../util/d2/d2.difficulty";
import { toHexString } from "../util/to.hex";
import { MAP_PROCESS } from './map.process';

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
        // if (!this.hasMap(seed, difficulty)) {
        await commandQueue.add(() => this.generateMap(seed, difficulty, log));
        if (!this.hasMap(seed, difficulty)) {
            log.fatal({ seed, difficulty }, 'Failed to make map')
            throw new Error('Failed to make map')
        }
        // };

        const mapId = this.mapId(seed, difficulty);
        return this.maps[mapId][levelCode];

    }

    async generateMap(seed: number, difficulty: D2Difficulty, log: Log) {
        const mapId = this.mapId(seed, difficulty);
        const seedResponse = await MAP_PROCESS.setSeed(seed, log);
        if (seedResponse.seed !== seed) {
            log.error({ mapId, response: seedResponse, seed, difficulty }, 'Invalid seed');
            throw new Error('Seed was not set.')
        }

        const diffResponse = await MAP_PROCESS.setDifficulty(difficulty, log);
        if (diffResponse.difficulty !== parseInt(D2Difficulty[difficulty])) {
            log.error({ mapId, response: seedResponse, seed, difficulty }, 'Invalid difficulty');
            throw new Error('difficulty was not set.')
        }

        const maps = await MAP_PROCESS.getMaps(log);
        log.info({ mapId, maps: Object.keys(maps).join(', ') }, 'GotMaps');
        this.maps[mapId] = maps;
        return maps;
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
