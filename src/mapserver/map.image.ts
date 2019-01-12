import { GameDifficulty } from "../core/difficulty";
import { MapGenerator } from "./map.generator";
import { PiMapRequest, PiMapRoute, PiMapRouteError, PiMapResponse } from "./route";
import { MapRoute } from "./map";
import { createCanvas, loadImage } from 'canvas';
import { D2MapLayerBase } from "../maprender/map.layer.base";



export class MapImageRoute implements PiMapRoute {
    url = '/map/:seed/:difficulty/:levelCode.png';


    async process(req: PiMapRequest, res: PiMapResponse) {
        const { levelCode, seed, difficulty } = MapRoute.validateParams(req);


        const map = await MapGenerator.getMap(seed, difficulty, levelCode, req.log);

        if (map == null) {
            throw new PiMapRouteError(404, "Map Not Found");
        }

        console.log(map);
        const mapLayer = new D2MapLayerBase([map]);

        req.log.info({ size: map.size }, 'CreatingPng');
        const canvas = createCanvas(map.size.width, map.size.height)
        const ctx = canvas.getContext('2d');

        mapLayer.render(ctx, mapLayer.extent)

        // ctx.font = '30px Impact';
        // ctx.rotate(0.1);
        // ctx.fillText('Awesome!', 50, 100);


        res.setHeader('Content-Type', 'image/png');
        canvas.pngStream().pipe(res);
        // return { id: req.id, levelCode, seed, difficulty: D2Difficulty[difficulty], map };
        return null;
    }


}
