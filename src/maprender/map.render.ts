import { MapLayerCollision } from "./map.layer.collision";
import { D2Map } from "../core/map";
import { Point, Size } from "../core/size";
import { MapLayerObject } from "./map.layer.object";
import { SpriteSheet } from "./sprite";

export interface MapExtents {
    min: Point;
    max: Point;
    size?: Size;
}

export class MapRenderer {
    size = { width: 500, height: 500 };

    _extent: MapExtents;
    maps: D2Map[];
    layerCollision: MapLayerCollision;
    layerObject: MapLayerObject;

    constructor(maps: D2Map[], size: Size, sprites: SpriteSheet) {
        this.maps = maps;
        this.size = size;

        this.layerCollision = new MapLayerCollision(this);
        this.layerObject = new MapLayerObject(this, sprites);
    }

    render(ctx) {
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
