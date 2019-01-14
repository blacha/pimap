import { Log } from "bblog";
import * as PromiseQueue from 'promise-queue';
import { GameDifficulty } from "../core/difficulty";
import { toHexString } from "../util/to.hex";
import { MapProcess } from './map.process';
import * as fs from 'fs';
import { D2Map } from "../core/map";

const CACHE_FILE = './cache.dat';

// Max one command at a time with 100 requests in queue
const commandQueue = new PromiseQueue(1, 100)
export type D2MapObj = { [key: string]: D2Map };
export class D2MapGenerator {
    maps: { [key: string]: D2MapObj } = {};

    constructor() { }

    async init(log: Log) {
        if (!fs.existsSync(CACHE_FILE)) {
            return;
        }
        try {
            this.maps = JSON.parse(fs.readFileSync(CACHE_FILE).toString())
        } catch (e) {
            // ignore
        }
        log.info({ mapCount: Object.keys(this.maps).length }, 'LoadedCache')
    }

    static mapId(seed: number, difficulty: GameDifficulty, levelCode?: number) {
        if (levelCode != null) {
            return `${toHexString(seed, 8)}_${difficulty}_${levelCode}`;
        }
        return `${toHexString(seed, 8)}_${difficulty}`;
    }

    async hasMap(seed: number, difficulty: GameDifficulty) {
        const mapId = D2MapGenerator.mapId(seed, difficulty);
        return this.maps[mapId] != null;
    }

    async getMaps(seed: number, difficulty: GameDifficulty, log: Log): Promise<D2MapObj> {
        const hasMap = await this.hasMap(seed, difficulty);
        if (!hasMap) {
            await commandQueue.add(() => this.generateMap(seed, difficulty, log));
            const nowHasMap = await this.hasMap(seed, difficulty);
            if (!nowHasMap) {
                log.fatal({ seed, difficulty }, 'Failed to make map')
                throw new Error('Failed to make map')
            }
        };

        const mapId = D2MapGenerator.mapId(seed, difficulty);
        return this.maps[mapId];

    }

    async generateMap(seed: number, difficulty: GameDifficulty, log: Log) {
        const mapId = D2MapGenerator.mapId(seed, difficulty);
        const seedResponse = await MapProcess.setSeed(seed, log);
        if (seedResponse.seed !== seed) {
            log.error({ mapId, response: seedResponse, seed, difficulty }, 'Invalid seed');
            throw new Error('Seed was not set.')
        }

        const diffResponse = await MapProcess.setDifficulty(difficulty, log);
        if (diffResponse.difficulty !== parseInt(GameDifficulty[difficulty])) {
            log.error({ mapId, response: seedResponse, seed, difficulty }, 'Invalid difficulty');
            throw new Error('difficulty was not set.')
        }

        const maps = await MapProcess.getMaps(log);
        log.info({ mapId, maps: Object.keys(maps).join(', ') }, 'GotMaps');
        this.maps[mapId] = maps;
        return maps;
    }
}


export const MapGenerator = new D2MapGenerator();
