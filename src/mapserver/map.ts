import { D2Difficulty } from "../util/d2/d2.difficulty";
import { MapGenerator } from "./map.generator";
import { PiMapRequest, PiMapRoute, PiMapRouteError } from "./route";

const isInLevelRange = (levelCode: number) => levelCode > 0 && levelCode < 100;
const isInSeedRange = (seed: number) => seed > 0 && seed < 0xffffffff

export class MapRoute implements PiMapRoute {
    url = '/map/:seed/:difficulty/:levelCode.json';


    async process(req: PiMapRequest) {
        const { levelCode, seed, difficulty } = this.validateParams(req);


        const map = await MapGenerator.getMap(seed, difficulty, levelCode, req.log);
        return { id: req.id, levelCode, seed, difficulty: D2Difficulty[difficulty], map };
    }

    validateParams(req: PiMapRequest) {
        const levelCode = parseInt(req.params.levelCode, 10);
        if (isNaN(levelCode) || !isInLevelRange(levelCode)) {
            throw new PiMapRouteError(422, 'Invalid level code');
        }

        const seed = parseInt(req.params.seed, 16)
        if (isNaN(seed) || !isInSeedRange(seed)) {
            throw new PiMapRouteError(422, 'Invalid seed');
        }

        const difficulty = req.params.difficulty as D2Difficulty;
        if (D2Difficulty[difficulty] == null) {
            throw new PiMapRouteError(422, 'Invalid difficulty');
        }

        return { levelCode, seed, difficulty }
    }
}
