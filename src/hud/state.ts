import * as m from 'mithril';
import { Point } from '../core/size';
import { GameStateJson } from '../core/game.json';
import { MapRenderer } from '../maprender/map.render';
import { WS } from './socket';
import { SpriteSheet } from '../maprender/sprite';
import { Logger } from '../util/log';

export class State {
    static mapSize = {
        width: 500,
        height: 500
    }
    static scheduled: number;
    static ctx: CanvasRenderingContext2D;
    static canvas: HTMLCanvasElement;
    static map: MapRenderer;
    static sprites: SpriteSheet;

    static game: GameStateJson;

    static currentAct = null;

    static get hasMap() {
        return this.map != null;
    }

    static setCanvas(c: HTMLCanvasElement) {
        this.canvas = c;
        c.width = this.mapSize.width;
        c.height = this.mapSize.height;
        this.ctx = c.getContext('2d');
    }

    static render() {
        m.redraw();
        if (this.scheduled) {
            return;
        }

        this.scheduled = requestAnimationFrame(_ => {
            if (this.map) {
                this.map.render(this.ctx);
                this.map.layerObject.renderNpcs(this.ctx, this.game.npc)
                this.map.layerObject.renderPlayer(this.ctx);
            }
            this.scheduled = null;
        });
    }


    static update(game: GameStateJson) {
        const lastGame = this.game;
        this.game = game;

        if (this.game == null) {
            this.ctx.clearRect(0, 0, this.canvas.width, this.canvas.height);
            return;
        }

        if (lastGame == null || game.map.id !== lastGame.map.id || game.map.difficulty !== lastGame.map.difficulty) {
            this.updateMaps();
        }

        if (State.map) {
            State.map.center = { x: this.game.player.x, y: this.game.player.y };
            State.map.act = this.game.map.act;
        }

        this.render();
    }

    static async updateMaps() {
        State.map = null;
        const mapRes = await WS.loadMaps(this.game.map.id, this.game.map.difficulty);
        if (mapRes == null) {
            return;
        }
        State.map = new MapRenderer(mapRes, { width: this.canvas.width, height: this.canvas.height }, this.sprites);
        State.map.log = Logger;
        this.render();
    }
}


