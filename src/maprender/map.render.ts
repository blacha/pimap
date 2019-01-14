import { MapLayerCollision } from "./map.layer.collision";
import { D2Map } from "../core/map";
import { Point, Size } from "../core/size";
import { MapLayerObject } from "./map.layer.object";
import { SpriteSheet } from "./sprite";
import { ActType } from "../core/act";

export interface MapExtents {
    min: Point;
    max: Point;
    size?: Size;
}

export class MapRenderer {
    center = { x: 0, y: 0 }
    size = { width: 500, height: 500 };
    act: ActType = null;

    _extent: MapExtents;
    maps: { [key: string]: D2Map };

    layerCollision: MapLayerCollision;
    layerObject: MapLayerObject;

    constructor(maps: { [key: string]: D2Map }, size: Size, sprites: SpriteSheet) {
        this.maps = maps;
        this.size = size;

        this.layerCollision = new MapLayerCollision(this);
        this.layerObject = new MapLayerObject(this, sprites);
    }

    getMapById(id: number): D2Map {
        console.log('get-map', id, this.maps[id] == null)
        return this.maps[id];
    }

    render(ctx: CanvasRenderingContext2D) {
        const extent = this.extent;
        const objects = this.layerCollision.render(ctx, extent);
        this.layerObject.render(ctx, extent, objects)
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

    getBoundedDraw(drawX: number, drawY: number) {
        let newX = drawX;
        let newY = drawY;

        if (drawX < 0) {
            newX = 8;
        } else if (drawX > this.size.width) {
            newX = this.size.width - 8;
        }

        if (drawY < 0) {
            newY = 8;
        } else if (drawY > this.size.height) {
            newY = this.size.height - 8;
        }
        return { x: newX, y: newY };
    }

    inBounds(drawX: number, drawY: number) {
        if (drawX < 0 || drawY < 0 || drawX > this.size.width || drawY > this.size.height) {
            return false;
        }
        return true;
    }

    get extent(): MapExtents {
        const centerX = this.center.x;
        const centerY = this.center.y;
        const halfMapWidth = this.size.width / 2;
        const halfMapHeight = this.size.height / 2;
        console.log('center', centerX, centerY, 'size', this.size)
        return {
            min: { x: centerX - halfMapWidth, y: centerY - halfMapHeight },
            max: { x: centerX + halfMapWidth, y: centerY + halfMapHeight }
        }
    }

    relToAbs(r: Point, map: D2Map): Point {
        return {
            x: r.x + map.offset.x,
            y: r.y + map.offset.y
        };
    }

    getMap(p: Point): D2Map {
        const { x, y } = p;
        for (const map of Object.values(this.maps)) {
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
