import { Log } from "bblog";
import * as fse from 'fs-extra';
import * as path from 'path';
import { promisify } from "util";
import { gunzip, gzip } from "zlib";
import { GameDifficulty } from "../core/difficulty";
import { toHexString } from "../util/to.hex";
import { D2MapObj } from "./map.generator";

const doGzip: (d: string | Buffer) => Promise<string> = promisify(gzip) as any;
const doGunzip: (d: string | Buffer) => Promise<string> = promisify(gunzip) as any;

export interface D2MapStorageObject {
    v: number;
    generatedAt: number;
    seed: number;
    difficulty: number;
    maps: D2MapObj;
}

const CACHE = './d2cache';
export class MapCache {

    static VERSION = 1;

    static mapId(seed: number, difficulty: GameDifficulty, levelCode?: number) {
        if (levelCode != null) {
            return `${toHexString(seed, 8, true)}_${difficulty}_${levelCode}`;
        }
        return `${toHexString(seed, 8, true)}_${difficulty}`;
    }

    async hasMap(seed: number, difficulty: GameDifficulty, log: Log): Promise<boolean> {
        const dataLocation = await this.getLocation(seed, difficulty);

        return await fse.pathExists(dataLocation);
    }

    async getLocation(seed: number, difficulty: GameDifficulty): Promise<string> {
        const mapId = MapCache.mapId(seed, difficulty);
        const dir = path.join(CACHE, mapId.substr(0, 2));
        await fse.ensureDir(dir);
        return path.join(dir, mapId + '.json.gz')
    }

    async getMap(seed: number, difficulty: GameDifficulty, log: Log): Promise<D2MapStorageObject> {
        const dataLocation = await this.getLocation(seed, difficulty);

        const exists = await fse.pathExists(dataLocation);
        if (!exists) {
            return null;
        }

        const buffer = await fse.readFile(dataLocation);
        if (buffer == null) {
            return null;
        }

        const bd: string = await doGunzip(buffer);
        const json = JSON.parse(bd);
        if (json['v'] === MapCache.VERSION) {
            return json;
        }
        return null;
    }

    async setMap(seed: number, difficulty: GameDifficulty, maps: D2MapObj, log: Log) {
        const setObject: D2MapStorageObject = {
            v: MapCache.VERSION,
            generatedAt: Date.now(),
            seed,
            difficulty,
            maps
        }

        const setStr = JSON.stringify(setObject);
        const gz = await doGzip(setStr);

        const dataLocation = await this.getLocation(seed, difficulty);
        log.info({ location: dataLocation, size: gz.length }, 'SetMapLocation');
        await fse.writeFile(dataLocation, gz);
    }
}
