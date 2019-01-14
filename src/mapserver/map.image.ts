import { createCanvas, Image, loadImage } from 'canvas';
import { MapRenderer } from "../maprender/map.render";
import { MapRoute } from "./map";
import { MapGenerator, D2MapGenerator } from "./map.generator";
import { PiMapRequest, PiMapResponse, PiMapRoute, PiMapRouteError } from "./route";
import * as fs from 'fs';
import { SpriteSheet } from '../maprender/sprite';
import { AreaLevel } from '../core/area';

// const MakiIcons = require('@mapbox/maki');

// console.log(MakiIcons.layouts);

export class MapImageRoute implements PiMapRoute {
    url = '/map/:seed/:difficulty/:levelCode.png';
    sprites: SpriteSheet;
    circle: Image;


    constructor() {
        const spritePng = fs.readFileSync('./assets/sprites.png');
        const image = new Image();
        image.src = spritePng;
        this.sprites = new SpriteSheet(image)

        // this.init();
        // this.circle = new Image();
        // this.circle.src = `<svg viewBox="0 0 11 11" height="11" width="11"><title>circle-stroked-11.svg</title><rect fill="none" x="0" y="0" width="11" height="11"></rect><path fill="#333" transform="translate(0 0)" d="M5.5,0C8.5376,0,11,2.4624,11,5.5S8.5376,11,5.5,11S0,8.5376,0,5.5
        // S2.4624,0,5.5,0z M5.5,1.2222c-2.3626,0-4.2778,1.9152-4.2778,4.2778S3.1374,9.7778,5.5,9.7778S9.7778,7.8626,9.7778,5.5
        // S7.8626,1.2222,5.5,1.2222z"></path></svg>`;
    }

    // async init() {
    //     this.circle = await loadImage(`assets/test.svg`)
    // }


    async process(req: PiMapRequest, res: PiMapResponse) {
        const { levelCode, seed, difficulty } = MapRoute.validateParams(req);
        const mapId = D2MapGenerator.mapId(seed, difficulty, levelCode);

        const map = await MapGenerator.getMap(seed, difficulty, levelCode, req.log);

        if (map == null) {
            throw new PiMapRouteError(404, "Map Not Found");
        }

        const renderer = new MapRenderer([map], map.size, this.sprites);

        req.log.info({ mapId, map: map.name, mapName: AreaLevel[map.id], ...map.size }, 'CreatingPng');
        const canvas = createCanvas(map.size.width, map.size.height)
        const ctx = canvas.getContext('2d');

        renderer.render(ctx)


        res.setHeader('Content-Type', 'image/png');
        canvas.pngStream().pipe(res);
        // return { id: req.id, levelCode, seed, difficulty: D2Difficulty[difficulty], map };
        return null;
    }

}
