// http://localhost:5000/act/2/683484276/1
import { AreaUtil } from '../core/area';
import { D2Map, D2MapObject } from '../core/map';
import { MapExtents, MapRenderer } from './map.render';

export class MapLayerCollision {
  base: MapRenderer;

  constructor(base: MapRenderer) {
    this.base = base;
  }

  render(ctx: CanvasRenderingContext2D, extent: MapExtents): D2MapObject[] {
    const objects = [];
    for (const map of Object.values(this.base.maps)) {
      const startTime = Date.now();

      const act = AreaUtil.getAct(map.id);
      if (act !== this.base.act) continue;

      if (!this.base.isMapInBounds(map, extent)) continue;

      this.renderMap(map, ctx, extent, objects);
      this.base.log.info({ mapName: map.name, duration: Date.now() - startTime, mapId: map.id }, 'RenderMap');
    }
    return objects;
  }

  renderMap(mapInfo: D2Map, ctx: CanvasRenderingContext2D, extent: MapExtents, objects: D2MapObject[]) {
    ctx.fillStyle = 'white';
    const map = mapInfo.map;

    const size = 1;
    for (let yOffset = 0; yOffset < map.length; yOffset++) {
      const line = map[yOffset];
      let fill = false;
      if (line.length === 0) continue;

      if (mapInfo.offset.y + yOffset < extent.min.y) continue;

      let x = mapInfo.offset.x - extent.min.x;
      const y = mapInfo.offset.y - extent.min.y + yOffset;

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
      objects.push({
        ...object,
        x: object.x + mapInfo.offset.x,
        y: object.y + mapInfo.offset.y,
      });
    }
    // console.timeEnd('RenderMap:' + toHexString(mapInfo.id)); // tslint:disable-line
  }
}
