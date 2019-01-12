import { AreaLevel } from '../core/area';
import { D2MapObject } from '../core/map';
import { MapExtents, MapRenderer } from './map.render';
import { GameObjectClasses, GameObjectClass } from '../core/object.type';
import { GameObject } from '../core/object';
import { Sprites, SpriteSheet } from './sprite';
import { NpcCode } from '../core/npc';

export class ObjectRenderShrine {
    type = GameObjectClass.SHRINE;
    constructor() { }

    render(ctx: CanvasRenderingContext2D, extent: MapExtents, object: D2MapObject) {

    }
}

export class MapLayerObject {

    base: MapRenderer;
    sheet: SpriteSheet;

    constructor(base: MapRenderer, sheet: SpriteSheet) {
        this.base = base;
        this.sheet = sheet;
    }

    static isGoodExit(obj: D2MapObject) {
        switch (obj.id) {
            case AreaLevel.RuinedTemple:
            case AreaLevel.DuranceOfHateLevel3:
                return true;
            default:
                return false;
        }
    }

    render(ctx: CanvasRenderingContext2D, extent: MapExtents, objects: D2MapObject[]) {
        console.log('Render', extent);

        for (const obj of objects) {
            // console.log(obj);
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
        console.log('Exit', obj, AreaLevel[obj.id]);
        const drawX = obj.x - extent.min.x;
        const drawY = obj.y - extent.min.y;

        ctx.fillStyle = "purple";
        ctx.fillRect(drawX, drawY, 16, 16);
    }

    renderNpc(ctx: CanvasRenderingContext2D, extent: MapExtents, obj: D2MapObject) {
        console.log('Npc', obj, NpcCode[obj.id]);

        const drawX = obj.x - extent.min.x;
        const drawY = obj.y - extent.min.y;

        ctx.fillStyle = "pink";
        ctx.fillRect(drawX, drawY, 16, 16);
    }

    renderObject(ctx: CanvasRenderingContext2D, extent: MapExtents, obj: D2MapObject) {
        const objType = GameObjectClasses[obj.id];
        if (objType === GameObjectClass.USELESS) {
            return;
        }
        if (typeof objType !== 'string') {
            console.log('Skipping', obj.id, GameObjectClasses[obj.id], GameObject[obj.id]);

            return;
        }
        const drawX = obj.x - extent.min.x;
        const drawY = obj.y - extent.min.y;
        console.log('Drawing', obj.id, GameObjectClasses[obj.id], GameObject[obj.id], `@ ${drawX}x${drawY}`);
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

