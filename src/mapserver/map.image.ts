import { createCanvas, Image, loadImage } from 'canvas';
import { MapRenderer } from "../maprender/map.render";
import { MapRoute } from "./map";
import { MapGenerator, D2MapGenerator } from "./map.generator";
import { PiMapRequest, PiMapResponse, PiMapRoute, PiMapRouteError } from "./route";
import * as fs from 'fs';
import { SpriteSheet } from '../maprender/sprite';
import { AreaLevel, AreaUtil } from '../core/area';
import { D2Map } from '../core/map';

const MAP_INFO_SIZE = 50;

export class MapImageRoute implements PiMapRoute {
    url = '/map/:seed/:difficulty/:levelCode.png';
    sprites: SpriteSheet;
    circle: Image;


    constructor() {
        const spritePng = fs.readFileSync('./assets/sprites.png');
        const image = new Image();
        image.src = spritePng;
        this.sprites = new SpriteSheet(image)
    }



    drawMapInfo(ctx: CanvasRenderingContext2D, map: D2Map) {
        ctx.fillStyle = 'white';
        ctx.fillRect(0, map.size.height, map.size.width, MAP_INFO_SIZE);

        ctx.fillStyle = 'rgba(0,0,0,0.87)';
        ctx.font = '30px Roboto'
        ctx.textBaseline = 'middle';
        ctx.textAlign = 'left';
        ctx.fillText(map.name, 16, map.size.height + MAP_INFO_SIZE / 2)

        ctx.textAlign = 'right';
        ctx.fillText(`${map.size.width}x${map.size.height}`, map.size.width - 16, map.size.height + MAP_INFO_SIZE / 2)
    }

    async process(req: PiMapRequest, res: PiMapResponse) {
        const { levelCode, seed, difficulty } = MapRoute.validateParams(req);
        const mapId = D2MapGenerator.mapId(seed, difficulty, levelCode);

        const maps = await MapGenerator.getMaps(seed, difficulty, req.log);

        if (maps == null || maps[levelCode] == null) {
            throw new PiMapRouteError(404, "Map Not Found");
        }

        const act = AreaUtil.getAct(levelCode);
        const map = maps[levelCode];

        const renderer = new MapRenderer(maps, map.size, this.sprites);
        renderer.act = act;
        renderer.center.x = map.offset.x + map.size.width / 2;
        renderer.center.y = map.offset.y + map.size.height / 2;

        req.log.info({ mapId, map: map.name, mapName: AreaLevel[map.id], ...map.size, extent: renderer.extent }, 'CreatingPng');
        const canvas = createCanvas(map.size.width, map.size.height + MAP_INFO_SIZE)
        // const canvas = createCanvas(renderer.extent.size.width, renderer.extent.size.height);
        const ctx: CanvasRenderingContext2D = canvas.getContext('2d');


        renderer.render(ctx)
        this.drawMapInfo(ctx, map);


        res.setHeader('Content-Type', 'image/png');
        canvas.pngStream().pipe(res);
        // return { id: req.id, levelCode, seed, difficulty: D2Difficulty[difficulty], map };
        return null;
    }

}
