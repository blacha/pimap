import { Act } from '@diablo2/data';
import { Log } from 'bblog';
import { AreaUtil } from '../../core/area';
import { D2Map } from '../../core/map';
import { Point, Size } from '../../core/size';
import { Logger } from '../../util/log';
import { MapLayerCollision } from './map.layer.collision';
import { MapLayerObject } from './map.layer.object';
import { SpriteSheet } from './sprite';

export interface MapExtents {
  min: Point;
  max: Point;
  size?: Size;
}

export class MapRenderer {
  center = { x: 0, y: 0 };
  size = { width: 768, height: 768 };
  act: Act = null;

  maps: { [key: string]: D2Map };

  layerCollision: MapLayerCollision;
  layerObject: MapLayerObject;

  log: Log;

  constructor(maps: { [key: string]: D2Map }, size: Size, sprites: SpriteSheet) {
    this.maps = maps;
    this.size = size;

    this.layerCollision = new MapLayerCollision(this);
    this.layerObject = new MapLayerObject(this, sprites);
  }

  /** List of maps currently in view */
  get currentMaps(): D2Map[] {
    const extent = this.extent;
    const maps = [];
    for (const map of Object.values(this.maps)) {
      const act = AreaUtil.getAct(map.id);
      if (act !== this.act) continue;
      if (this.isMapInBounds(map, extent)) maps.push(map);
    }
    return maps;
  }

  getMapById(id: number): D2Map {
    return this.maps[id];
  }

  render(ctx: CanvasRenderingContext2D): void {
    const extent = this.extent;
    Logger.info({ extent, act: this.act }, 'Render..');

    ctx.clearRect(0, 0, this.size.width, this.size.height);

    const objects = this.layerCollision.render(ctx, extent);
    this.layerObject.render(ctx, extent, objects);
  }

  isMapInBounds(mapInfo: D2Map, extent: MapExtents): boolean {
    if (mapInfo.offset.x + mapInfo.size.width < extent.min.x) return false;
    if (mapInfo.offset.y + mapInfo.size.height < extent.min.y) return false;
    if (mapInfo.offset.x > extent.max.x) return false;
    if (mapInfo.offset.y > extent.max.y) return false;
    return true;
  }

  getBoundedDraw(drawX: number, drawY: number): Point {
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

  inBounds(drawX: number, drawY: number): boolean {
    if (drawX < 0 || drawY < 0 || drawX > this.size.width || drawY > this.size.height) {
      return false;
    }
    return true;
  }
  /** Convert to a drawX/drawY then check bounds */
  inBoundsAbs(x: number, y: number): boolean {
    const extent = this.extent;
    const drawX = x - extent.min.x;
    const drawY = y - extent.min.y;
    return this.inBounds(drawX, drawY);
  }

  get extent(): MapExtents {
    const centerX = this.center.x;
    const centerY = this.center.y;
    const halfMapWidth = this.size.width / 2;
    const halfMapHeight = this.size.height / 2;
    return {
      min: { x: centerX - halfMapWidth, y: centerY - halfMapHeight },
      max: { x: centerX + halfMapWidth, y: centerY + halfMapHeight },
    };
  }

  relToAbs(r: Point, map: D2Map): Point {
    return {
      x: r.x + map.offset.x,
      y: r.y + map.offset.y,
    };
  }

  getMap(p: Point): D2Map {
    const { x, y } = p;
    for (const map of Object.values(this.maps)) {
      if (map == null) {
        continue;
      }
      if (map.offset == null) continue;
      if (x < map.offset.x) continue;
      if (y < map.offset.y) continue;
      if (x > map.offset.x + map.size.width) continue;
      if (y > map.offset.y + map.size.height) continue;
      return map;
    }
    return null;
  }
}
