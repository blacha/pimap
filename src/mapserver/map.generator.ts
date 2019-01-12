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
export class D2MapGenerator {
    maps = {};

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

    hasMap(seed: number, difficulty: GameDifficulty) {
        const mapId = D2MapGenerator.mapId(seed, difficulty);
        return this.maps[mapId] != null;
    }

    async getMap(seed: number, difficulty: GameDifficulty, levelCode: number, log: Log): Promise<D2Map> {
        if (!this.hasMap(seed, difficulty)) {
            await commandQueue.add(() => this.generateMap(seed, difficulty, log));
            if (!this.hasMap(seed, difficulty)) {
                log.fatal({ seed, difficulty }, 'Failed to make map')
                throw new Error('Failed to make map')
            }

            fs.writeFileSync(CACHE_FILE, JSON.stringify(this.maps));
        };

        const mapId = D2MapGenerator.mapId(seed, difficulty);
        return this.maps[mapId][levelCode];

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
