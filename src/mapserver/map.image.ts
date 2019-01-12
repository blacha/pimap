import { createCanvas, Image } from 'canvas';
import { MapRenderer } from "../maprender/map.render";
import { MapRoute } from "./map";
import { MapGenerator, D2MapGenerator } from "./map.generator";
import { PiMapRequest, PiMapResponse, PiMapRoute, PiMapRouteError } from "./route";
import * as fs from 'fs';
import { SpriteSheet } from '../maprender/sprite';


export class MapImageRoute implements PiMapRoute {
    url = '/map/:seed/:difficulty/:levelCode.png';
    sprites: SpriteSheet;


    constructor() {
        const spritePng = fs.readFileSync('./assets/sprites.png');
        const image = new Image();
        image.src = spritePng;
        this.sprites = new SpriteSheet(image)
    }


    async process(req: PiMapRequest, res: PiMapResponse) {
        const { levelCode, seed, difficulty } = MapRoute.validateParams(req);
        const mapId = D2MapGenerator.mapId(seed, difficulty, levelCode);

        const map = await MapGenerator.getMap(seed, difficulty, levelCode, req.log);

        if (map == null) {
            throw new PiMapRouteError(404, "Map Not Found");
        }

        const renderer = new MapRenderer([map], map.size, this.sprites);

        req.log.info({ mapId, map: map.name, ...map.size }, 'CreatingPng');
        const canvas = createCanvas(map.size.width, map.size.height)
        const ctx = canvas.getContext('2d');

        renderer.render(ctx)

        // ctx.font = '30px Impact';
        // ctx.rotate(0.1);
        // ctx.fillText('Awesome!', 50, 100);


        res.setHeader('Content-Type', 'image/png');
        canvas.pngStream().pipe(res);
        // return { id: req.id, levelCode, seed, difficulty: D2Difficulty[difficulty], map };
        return null;
    }


}
