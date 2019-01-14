import { AreaLevel } from '../core/area';
import { D2MapObject, D2Map } from '../core/map';
import { MapExtents, MapRenderer } from './map.render';
import { GameObjectClasses, GameObjectClass } from '../core/object.type';
import { GameObject } from '../core/object';
import { Sprites, SpriteSheet } from './sprite';
import { NpcCode, NpcUtil } from '../core/npc';

export class ObjectRenderShrine {
    type = GameObjectClass.SHRINE;
    constructor() { }

    render(ctx: CanvasRenderingContext2D, extent: MapExtents, object: D2MapObject) {

    }
}

export class MapLayerObject {

    /** should we render the words for exits */
    isExitTextEnabled = true;

    base: MapRenderer;
    sheet: SpriteSheet;
    correctTombId: number;

    constructor(base: MapRenderer, sheet: SpriteSheet) {
        this.base = base;
        this.sheet = sheet;
    }

    isGoodExit(obj: D2MapObject) {
        switch (obj.id) {
            case AreaLevel.RuinedTemple:
            case AreaLevel.DuranceOfHateLevel3:
                return true;
            case AreaLevel.TalRashasTomb1:
            case AreaLevel.TalRashasTomb2:
            case AreaLevel.TalRashasTomb3:
            case AreaLevel.TalRashasTomb4:
            case AreaLevel.TalRashasTomb5:
            case AreaLevel.TalRashasTomb6:
            case AreaLevel.TalRashasTomb7:
                return this.isCorrectTomb(this.base.getMapById(obj.id))
            default:
                return false;
        }
    }

    // TODO could just calculate this at the start
    isCorrectTomb(map: D2Map) {
        if (this.correctTombId == null) {
            const isTomb = map.objects.find(f => f.type === 'object' && f.id === GameObject.HoradricOrifice) != null;
            if (isTomb) {
                this.correctTombId = map.id;
            }
        }

        return this.correctTombId == map.id;
    }

    render(ctx: CanvasRenderingContext2D, extent: MapExtents, objects: D2MapObject[]) {

        for (const obj of objects) {
            if (obj.type === 'exit') {
                this.renderExit(ctx, extent, obj);
            } else if (obj.type === 'npc') {
                this.renderNpc(ctx, extent, obj);
            } else {
                this.renderObject(ctx, extent, obj);
            }
        }
    }

    renderExit(ctx: CanvasRenderingContext2D, extent: MapExtents, obj: D2MapObject) {
        // console.log('Exit', obj, AreaLevel[obj.id]);
        const drawX = obj.x - extent.min.x;
        const drawY = obj.y - extent.min.y;

        if (this.isExitTextEnabled) {
            ctx.lineWidth = 1;
            ctx.strokeStyle = 'rgba(0,0,0,0.87)';
            ctx.fillStyle = 'rgba(255,255,255,0.87)';
            ctx.font = '18px Impact';
            ctx.textBaseline = 'middle';
            ctx.textAlign = 'center';
        }

        ctx.fillText(AreaLevel[obj.id], drawX, drawY + 16);
        ctx.strokeText(AreaLevel[obj.id], drawX, drawY + 16);

        if (this.isGoodExit(obj)) {
            Sprites.ExitGood.draw(ctx, this.sheet, drawX, drawY, 24);
        } else {
            Sprites.Exit.draw(ctx, this.sheet, drawX, drawY, 24);
        }


    }



    renderNpc(ctx: CanvasRenderingContext2D, extent: MapExtents, obj: D2MapObject) {
        if (NpcUtil.isUseless(obj.id)) {
            return;
        }
        if (NpcUtil.isTownFolk(obj.id)) {
            return;
        }

        const drawX = obj.x - extent.min.x;
        const drawY = obj.y - extent.min.y;

        console.log('Npc', obj, NpcCode[obj.id]);

        Sprites.Unkown.draw(ctx, this.sheet, drawX, drawY, 24);
    }

    renderObject(ctx: CanvasRenderingContext2D, extent: MapExtents, obj: D2MapObject) {
        const objType = GameObjectClasses[obj.id];
        if (objType === GameObjectClass.USELESS) {
            return;
        }
        if (typeof objType !== 'string') {
            // console.log('Skipping', obj.id, GameObjectClasses[obj.id], GameObject[obj.id]);
            return;
        }
        const drawX = obj.x - extent.min.x;
        const drawY = obj.y - extent.min.y;
        // console.log('Drawing', obj.id, GameObjectClasses[obj.id], GameObject[obj.id], `@ ${drawX}x${drawY}`);
        if (this.base.inBounds(drawX, drawY)) {
            this.drawObject(ctx, extent, drawX, drawY, obj);
        } else {
            // console.log('NotInBounds', drawX, drawY);
        }
    }

    drawObject(ctx: CanvasRenderingContext2D, extent: MapExtents, drawX: number, drawY: number, obj: D2MapObject) {
        const objType = GameObjectClasses[obj.id];
        if (objType === GameObjectClass.SHRINE) {
            return Sprites.Shrine.draw(ctx, this.sheet, drawX, drawY, 24);
        }

        if (objType === GameObjectClass.WAYPOINT) {
            return Sprites.Waypoint.draw(ctx, this.sheet, drawX, drawY);
        }

        if (objType === GameObjectClass.CHEST) {
            return Sprites.Chest.draw(ctx, this.sheet, drawX, drawY, 16);
        }

        if (objType === GameObjectClass.QUEST) {
            return Sprites.Quest.draw(ctx, this.sheet, drawX, drawY, 16);
        }

        ctx.fillStyle = "orange";
        ctx.fillRect(drawX, drawY, 16, 16);
    }
    // const mapObjects = State.map.getObjects(State.extent);
    // console.log('rendering-objects', objects, );
    //     for (const obj of objects) {
    //         const drawX = obj.x - extent.min.x;
    //         const drawY = obj.y - extent.min.y;
    //         if (!this.inBounds(drawX, drawY)) {


    //             if (obj.type === 'Waypoint') {
    //                 const bWp = this.getBoundedDraw(drawX, drawY);
    //                 Sprites.Waypoint.draw(State.ctx, bWp.x, bWp.y, this.SpriteSize);
    //             } else if (obj.type === 'Exit') {
    //                 const bExit = this.getBoundedDraw(drawX, drawY);
    //                 if (this.isGoodExit(obj)) {
    //                     Sprites.ExitGood.draw(State.ctx, bExit.x, bExit.y, 24);
    //                 } else {
    //                     Sprites.Exit.draw(State.ctx, bExit.x, bExit.y, 24);
    //                 }
    //             } else if (obj.type === 'NPC' && NpcName[obj.id] === 'Summoner') {
    //                 const bNPC = this.getBoundedDraw(drawX, drawY);
    //                 Sprites.MonsterBoss.draw(State.ctx, bNPC.x, bNPC.y, 24);
    //             }
    //             continue;
    //         }
    //         const objectName = GameObject[obj.id] || '';

    //         if (obj.type === 'Waypoint') {
    //             Sprites.Waypoint.draw(State.ctx, drawX, drawY, this.SpriteSize);
    //         } else if (obj.type === 'Exit') {
    //             if (this.isGoodExit(obj)) {
    //                 Sprites.ExitGood.draw(State.ctx, drawX, drawY, 24);
    //             } else {
    //                 Sprites.Exit.draw(State.ctx, drawX, drawY, 24);
    //             }
    //         } else if (objectName.indexOf('CairnStone') === 0) {
    //             Sprites.MonsterSuperUnique.draw(State.ctx, drawX, drawY, 8);
    //         } else if (obj.type === 'NPC' && NpcName[obj.id] === 'Summoner') {
    //             Sprites.MonsterBoss.draw(State.ctx, drawX, drawY, 24);
    //         } else if (objectName.indexOf('Shrine') > -1) {
    //             Sprites.Cross.draw(State.ctx, drawX, drawY, 16);
    //         } else {
    //             continue;
    //         }

    //     }
    // }
}

