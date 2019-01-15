import { Log } from "bblog";
import * as PromiseQueue from 'promise-queue';
import { GameDifficulty } from "../core/difficulty";
import { toHexString } from "../util/to.hex";
import { MapProcess } from './map.process';
import * as fs from 'fs';
import { D2Map } from "../core/map";
import { MapCache } from "./map.cache";

const CACHE_FILE = './cache.dat';

// Max one command at a time with 100 requests in queue
const commandQueue = new PromiseQueue(1, 100)
export type D2MapObj = { [key: string]: D2Map };
export class D2MapGenerator {
    cache = new MapCache();

    async getMaps(seed: number, difficulty: GameDifficulty, log: Log): Promise<D2MapObj> {
        const hasMap = await this.cache.hasMap(seed, difficulty, log);
        if (!hasMap) {
            await commandQueue.add(() => this.generateMap(seed, difficulty, log));
            const nowHasMap = await this.cache.hasMap(seed, difficulty, log);
            if (!nowHasMap) {
                log.fatal({ seed, difficulty }, 'Failed to make map')
                throw new Error('Failed to make map')
            }
        };

        const mapStorage = await this.cache.getMap(seed, difficulty, log);
        if (mapStorage == null) {
            return null;
        }
        return mapStorage.maps;
    }

    async generateMap(seed: number, difficulty: GameDifficulty, log: Log) {
        const mapId = MapCache.mapId(seed, difficulty);
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
        log.info({ mapId, maps: Object.keys(maps).length }, 'GotMaps');
        await this.cache.setMap(seed, difficulty, maps, log);
        return maps;
    }
}


export const MapGenerator = new D2MapGenerator();
