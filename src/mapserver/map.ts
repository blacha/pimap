import { GameDifficulty } from "../core/difficulty";
import { MapGenerator } from "./map.generator";
import { PiMapRequest, PiMapRoute, PiMapRouteError } from "./route";

const isInLevelRange = (levelCode: number) => levelCode > 0 && levelCode < 150;
const isInSeedRange = (seed: number) => seed > 0 && seed < 0xffffffff

export class MapRoute implements PiMapRoute {
    url = '/map/:seed/:difficulty/:levelCode.json';


    async process(req: PiMapRequest) {
        const { levelCode, seed, difficulty } = MapRoute.validateParams(req);
        const maps = await MapGenerator.getMaps(seed, difficulty, req.log);
        return { id: req.id, levelCode, seed, difficulty: GameDifficulty[difficulty], map: maps[levelCode] };
    }

    static validateParams(req: PiMapRequest) {
        const levelCode = parseInt(req.params.levelCode, 10);
        if (isNaN(levelCode) || !isInLevelRange(levelCode)) {
            throw new PiMapRouteError(422, 'Invalid level code');
        }

        const seed = parseInt(req.params.seed, 10)
        if (isNaN(seed) || !isInSeedRange(seed)) {
            throw new PiMapRouteError(422, 'Invalid seed');
        }

        const difficulty = req.params.difficulty as GameDifficulty;
        if (GameDifficulty[difficulty] == null) {
            throw new PiMapRouteError(422, 'Invalid difficulty');
        }

        return { levelCode, seed, difficulty }
    }
}
