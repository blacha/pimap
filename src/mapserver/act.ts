import { PiMapRequest, PiMapRoute, PiMapRouteError } from "./route";
import { MapGenerator } from "./map.generator";
import { GameDifficulty } from "../core/difficulty";
import { isInSeedRange } from "./map";
import { MapCache } from "./map.cache";

export class MapDifficultyRoute implements PiMapRoute {
    url = '/map/:seed/:difficulty.json';


    async process(req: PiMapRequest, res) {
        const { seed, difficulty } = MapDifficultyRoute.validateParams(req);
        const maps = await MapGenerator.getMaps(seed, difficulty, req.log);
        res.setHeader('Content-Disposition', 'attachment; filename=' + MapCache.mapId(seed, difficulty) + '.json');
        return { id: req.id, seed, difficulty: GameDifficulty[difficulty], maps: maps };
    }

    static validateParams(req: PiMapRequest) {
        const seed = parseInt(req.params.seed, 10)
        if (isNaN(seed) || !isInSeedRange(seed)) {
            throw new PiMapRouteError(422, 'Invalid seed');
        }

        const difficulty = req.params.difficulty as GameDifficulty;
        if (GameDifficulty[difficulty] == null) {
            throw new PiMapRouteError(422, 'Invalid difficulty');
        }

        return { seed, difficulty }
    }
}
