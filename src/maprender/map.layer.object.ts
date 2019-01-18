import { AreaLevel } from '../core/area';
import { D2MapObject, D2Map } from '../core/map';
import { MapExtents, MapRenderer } from './map.render';
import { GameObjectClasses, GameObjectClass } from '../core/object.type';
import { GameObject } from '../core/object';
import { Sprites, SpriteSheet } from './sprite';
import { NpcCode, NpcUtil } from '../core/npc';
import { NpcJson } from '../core/game.json';
import { NpcName } from '../core/npc.name';

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
        const drawX = obj.x - extent.min.x;
        const drawY = obj.y - extent.min.y;

        if (!this.base.inBounds(drawX, drawY)) {
            if (this.isGoodExit(obj)) {
                const bWp = this.getBoundedDraw(drawX, drawY);
                this.drawObject(ctx, extent, bWp.x, bWp.y, obj);
            }
        }

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

        if (NpcName[obj.id] == null) {
            return;
        }

        const drawX = obj.x - extent.min.x;
        const drawY = obj.y - extent.min.y;

        this.base.log.info({ npcName: NpcCode[obj.id], npcId: obj.id }, 'RenderNpc');
        if (!this.base.inBounds(drawX, drawY)) {

            if (obj.id === NpcCode.Summoner || obj.id === NpcCode.Izual) {
                const bWp = this.getBoundedDraw(drawX, drawY);
                Sprites.MonsterBoss.draw(ctx, this.sheet, bWp.x, bWp.y, 18);
            }
            return;
        }
        console.log('Draw', obj, NpcName[obj.id]);
        Sprites.Unkown.draw(ctx, this.sheet, drawX, drawY, 18);
    }

    renderObject(ctx: CanvasRenderingContext2D, extent: MapExtents, obj: D2MapObject) {
        const objType = GameObjectClasses[obj.id];
        if (objType === GameObjectClass.USELESS) {
            return;
        }
        if (typeof objType !== 'string') {
            return;
        }
        const drawX = obj.x - extent.min.x;
        const drawY = obj.y - extent.min.y;
        if (this.base.inBounds(drawX, drawY)) {
            this.drawObject(ctx, extent, drawX, drawY, obj);
        } else {
            const objType = GameObjectClasses[obj.id];
            if (objType === GameObjectClass.QUEST) {
                const bWp = this.getBoundedDraw(drawX, drawY);
                Sprites.MonsterBoss.draw(ctx, this.sheet, bWp.x, bWp.y, 18);
            }
            // console.log('NotInBounds', drawX, drawY, objType);
        }
    }
    getBoundedDraw(drawX: number, drawY: number) {
        let newX = drawX;
        let newY = drawY;

        if (drawX < 0) {
            newX = 8;
        } else if (drawX > this.base.size.width) {
            newX = this.base.size.width - 8;
        }

        if (drawY < 0) {
            newY = 8;
        } else if (drawY > this.base.size.height) {
            newY = this.base.size.height - 8;
        }
        return { x: newX, y: newY };
    }

    drawObject(ctx: CanvasRenderingContext2D, extent: MapExtents, drawX: number, drawY: number, obj: D2MapObject) {
        const objType = GameObjectClasses[obj.id];
        if (objType === GameObjectClass.SHRINE) {
            return Sprites.Shrine.draw(ctx, this.sheet, drawX, drawY, 16);
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

    renderPlayer(ctx: CanvasRenderingContext2D) {
        Sprites.Player.draw(ctx, this.sheet, this.base.size.width / 2, this.base.size.height / 2)
    }

    renderNpcs(ctx: CanvasRenderingContext2D, npcs: NpcJson[]) {
        const extent = this.base.extent;
        const lastDraw: NpcJson[] = [];
        for (const npc of npcs) {
            if (NpcUtil.isUseless(npc.code)) {
                continue;
            }
            if (NpcUtil.isTownFolk(npc.code)) {
                continue;
            }
            const npcRet = this.drawPacketNpc(ctx, npc, extent)
            if (npcRet != null) {
                lastDraw.push(npcRet);
            }
        }

        for (const npc of lastDraw) {
            if (npc.flags.unique) {
                Sprites.MonsterUnique.draw(ctx, this.sheet, npc.x - extent.min.x, npc.y - extent.min.y);
            } else {
                Sprites.MonsterBoss.draw(ctx, this.sheet, npc.x - extent.min.x, npc.y - extent.min.y);
            }
        }
    }

    drawPacketNpc(ctx: CanvasRenderingContext2D, npc: NpcJson, extent: MapExtents): NpcJson | null {
        const drawX = npc.x - extent.min.x;
        const drawY = npc.y - extent.min.y;

        // if (npc.uid === State.game.player.mercId) {
        // Sprites.Merc.draw(ctx, this.sheet, drawX, drawY, 12);
        // } else
        if (npc.name === 'Hydra') {
            Sprites.PlayerHydra.draw(ctx, this.sheet, drawX, drawY, 12);
        } else if (NpcUtil.isDoll(npc.code)) {
            Sprites.MonsterEvil.draw(ctx, this.sheet, drawX, drawY, 24);
        } else if (NpcUtil.isSoul(npc.code)) {
            Sprites.MonsterLightning.draw(ctx, this.sheet, drawX, drawY, 24);
        } else if (npc.flags == null || Object.keys(npc.flags).length === 0) {
            Sprites.MonsterNormal.draw(ctx, this.sheet, drawX, drawY, 16);
        } else if (npc.flags.champion) {
            Sprites.MonsterChampion.draw(ctx, this.sheet, drawX, drawY, 16);
        } else if (npc.flags.minion) {
            Sprites.MonsterMinion.draw(ctx, this.sheet, drawX, drawY, 16);
        } else if (npc.flags.superUnique || npc.flags.unique) {
            return npc;
        } else {
            Sprites.Unkown.draw(ctx, this.sheet, drawX, drawY);
        }
        // Sprites.MonsterNormal.draw(ctx,this.sheet, this.sheet, drawX, drawY);
    }

}

