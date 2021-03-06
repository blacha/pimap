import m from 'mithril';
import type { GameStateJson } from '@diablo2/core';
import { MapRenderer } from './maprender/map.render';
import { SpriteSheet } from './maprender/sprite';
import { Logger } from '../util/log';
import { WS } from './socket';

export class State {
  static mapSize = { width: 512, height: 512 };
  static scheduled: number;
  static ctx: CanvasRenderingContext2D;
  static canvas: HTMLCanvasElement;
  static map: MapRenderer;
  static sprites: SpriteSheet;

  static game: GameStateJson;

  static games = new Map<string, GameStateJson>();

  // static stats: Stats;

  static currentAct = null;

  static get hasMap(): boolean {
    return this.map != null;
  }

  static get isGameActive(): boolean {
    return this.game != null && this.game.map.id !== -1;
  }

  static setCanvas(c: HTMLCanvasElement): void {
    this.canvas = c;
    c.width = this.mapSize.width;
    c.height = this.mapSize.height;
    this.ctx = c.getContext('2d');
  }

  static render(): void {
    m.redraw();
    if (this.scheduled) return;

    this.scheduled = requestAnimationFrame(() => {
      if (this.map) {
        this.map.render(this.ctx);
        this.map.layerObject.renderNpcs(this.ctx, this.game.units);
        this.map.layerObject.renderItems(this.ctx, this.game.items);
        this.map.layerObject.renderPlayer(this.ctx);
      }
      this.scheduled = null;
    });
  }

  static update(game: GameStateJson): void {
    const lastGame = this.game;

    this.games.set(game.id, game);
    this.game = game;
    // console.log('State', { game });

    if (this.game == null) {
      this.ctx.clearRect(0, 0, this.canvas.width, this.canvas.height);
      return;
    }

    if (lastGame == null || game.map.id !== lastGame.map.id || game.map.difficulty !== lastGame.map.difficulty) {
      this.updateMaps();
    }

    this.render();
  }

  static async updateMaps(): Promise<void> {
    State.map = null;
    const mapRes = await WS.loadMaps(this.game.map.id, this.game.map.difficulty);
    if (mapRes == null) return;

    State.map = new MapRenderer(mapRes, { width: this.canvas.width, height: this.canvas.height }, this.sprites);
    State.map.log = Logger;
    Logger.warn('MapUpdated');
    this.render();

    setTimeout(() => this.render(), 100);
  }
}
