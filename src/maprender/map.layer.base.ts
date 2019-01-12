// http://localhost:5000/act/2/683484276/1
import { GameDifficulty } from '../core/difficulty';
import { NpcCode } from '../core/npc';
import { GameObject, GameObjectType } from '../core/object';
import { Point, Size } from '../core/size';
import { toHexString } from '../util/to.hex';
import { D2Map, D2MapObject } from '../core/map';
import { GameObjectClasses, GameObjectClass } from '../core/object.type';

interface MapExtents {
    min: Point;
    max: Point;
    size?: Size;
}

export class D2MapLayerBase {
    static MAP_SIZE = 500;
    static MAP_SIZE_HALF = D2MapLayerBase.MAP_SIZE / 2;
    // canvas: HTMLCanvasElement;
    // ctx: CanvasRenderingContext2D;
    _extent: MapExtents;
    maps: D2Map[];

    constructor(maps: D2Map[]) {
        this.maps = maps;
    }

    render(ctx: CanvasRenderingContext2D, extent: MapExtents): D2MapObject[] {
        const objects = [];
        console.time('RenderAllMaps'); // tslint:disable-line
        for (const map of this.maps) {
            this.renderMap(map, ctx, extent, objects);
        }
        console.timeEnd('RenderAllMaps'); // tslint:disable-line
        return objects;
    }

    isMapInBounds(mapInfo: D2Map, extent: MapExtents) {
        if (mapInfo.offset.x + mapInfo.size.width < extent.min.x) {
            return false;
        }
        if (mapInfo.offset.y + mapInfo.size.height < extent.min.y) {
            return false;
        }
        if (mapInfo.offset.x > extent.max.x) {
            return false;
        }
        if (mapInfo.offset.y > extent.max.y) {
            return false;
        }
        return true;
    }

    renderMap(mapInfo: D2Map, ctx: CanvasRenderingContext2D, extent: MapExtents, objects: D2MapObject[]) {
        ctx.fillStyle = 'white';
        const map = mapInfo.map;

        if (!this.isMapInBounds(mapInfo, extent)) {
            return;
        }

        console.time('RenderMap:' + toHexString(mapInfo.id)); // tslint:disable-line

        let size = 1;
        for (var yOffset = 0; yOffset < map.length; yOffset++) {
            const line = map[yOffset];
            let fill = false;
            if (line.length === 0) {
                continue;
            }

            if (mapInfo.offset.y + yOffset < extent.min.y) {
                continue;
            }

            let x = mapInfo.offset.x - extent.min.x;
            let y = mapInfo.offset.y - extent.min.y + yOffset;


            for (let i = 0; i < line.length; i++) {
                const xCount = line[i];

                fill = !fill;
                if (!fill) {

                    // for (let xOffset = 0; xOffset <= xCount; xOffset++) {
                    ctx.fillRect(x, y, xCount, size);

                }
                x = x + xCount;
            }
            const xMax = mapInfo.offset.x - extent.min.x + mapInfo.size.width;
            if (fill && x < xMax) {
                ctx.fillRect(x, y, xMax - x, size);
            }


        }
        for (const object of mapInfo.objects) {
            const objectType = GameObjectClasses[object.id] == GameObjectClass.USELESS;
            console.log('Object', object.id, GameObject[object.id], GameObjectClasses[object.id]);

            objects.push({
                id: object.id,
                x: object.x + mapInfo.offset.x,
                y: object.y + mapInfo.offset.y,
                type: object.type
            });
        }
        console.timeEnd('RenderMap:' + toHexString(mapInfo.id)); // tslint:disable-line
    }

    get extent(): MapExtents {
        const min: Point = { x: Number.MAX_SAFE_INTEGER, y: Number.MAX_SAFE_INTEGER };
        const max: Point = { x: -1, y: -1 };
        for (const map of this.maps) {
            min.x = Math.min(min.x, map.offset.x);
            min.y = Math.min(min.y, map.offset.y);

            max.x = Math.max(max.x, map.offset.x + map.size.width);
            max.y = Math.max(max.y, map.offset.y + map.size.width);
        }

        this._extent = {
            min,
            max,
            size: {
                width: max.x - min.x,
                height: max.y - min.y
            }
        };
        console.log('Extents', this._extent);
        return this._extent;
    }

    relToAbs(r: Point, map: D2Map): Point {
        return {
            x: r.x + map.offset.x,
            y: r.y + map.offset.y
        };
    }

    getMap(p: Point): D2Map {
        const { x, y } = p;
        for (const map of this.maps) {
            if (map == null) {
                continue;
            }
            if (map.offset == null) {
                continue;
            }
            if (x < map.offset.x) {
                continue;
            }
            if (y < map.offset.y) {
                continue;
            }
            if (x > map.offset.x + map.size.width) {
                continue;
            }
            if (y > map.offset.y + map.size.height) {
                continue;
            }
            return map;
        }
        return null;
    }
}


