// //tslint: disable-no-console

import m from 'mithril';
import { State } from './state';
import { ItemListView } from './view/item';
import { MonsterKillList, MonsterListView } from './view/monster';
import { PlayerView } from './view/player';
import { WS } from './socket';
import { SpriteSheet } from './maprender/sprite';
import { Logger } from '../util/log';
import { GameStateJson } from '@diablo2/core';
import { LogMessage } from 'bblog';

export const HtmlView = {
  view() {
    if (!State.isGameActive) return m('div', 'Loading...');
    return [PlayerView.view(), ItemListView.view(), MonsterListView.view(), MonsterKillList.view()];
  },
};

document.addEventListener('DOMContentLoaded', async () => {
  (window as any).State = State;
  State.setCanvas(document.getElementById('map-layer') as HTMLCanvasElement);

  // Load the sprite sheet
  const spriteImage = new Image();
  spriteImage.src = '/assets/sprites.png';
  await new Promise((res) => (spriteImage.onload = res));
  State.sprites = new SpriteSheet(spriteImage);

  // State.game = { map: { id: 1240694333, difficulty: 0 } };
  m.mount(document.getElementById('main'), HtmlView);
  WS.start('ws://localhost:40510');

  // const state: GameStateJson = {
  //   id: '01f169wned4dz0zg7pc2fx636x',
  //   createdAt: 1616193148365,
  //   player: {
  //     id: 1,
  //     type: 'player',
  //     name: 'SomeNameHere',
  //     x: 4620,
  //     y: 5582,
  //     updatedAt: 1616193224167,
  //     life: -1,
  //     xp: { current: 428059834, start: 428059834, diff: 0 },
  //     level: 74,
  //   },
  //   map: { id: 1711250936, act: 0, difficulty: 0, isHardcore: true },
  //   objects: [],
  //   units: [
  //     {
  //       type: 'npc',
  //       id: 1,
  //       name: 'Guard',
  //       life: 128,
  //       x: 4829,
  //       y: 5681,
  //       code: 338,
  //       flags: {},
  //       updatedAt: 1616195136956,
  //       enchants: [],
  //     },
  //     {
  //       type: 'npc',
  //       id: 7,
  //       name: 'Charsi',
  //       life: 128,
  //       x: 4824,
  //       y: 5644,
  //       code: 154,
  //       flags: {},
  //       updatedAt: 1616195138558,
  //       enchants: [],
  //     },
  //     {
  //       type: 'npc',
  //       id: 5,
  //       name: 'Gheed',
  //       life: 128,
  //       x: 4825,
  //       y: 5706,
  //       code: 147,
  //       flags: {},
  //       updatedAt: 1616195143356,
  //       enchants: [],
  //     },
  //     {
  //       type: 'npc',
  //       id: 13,
  //       name: 'Warriv',
  //       life: 128,
  //       x: 4865,
  //       y: 5660,
  //       code: 155,
  //       flags: {},
  //       updatedAt: 1616195144715,
  //       enchants: [],
  //     },
  //   ],
  //   items: [],
  //   kills: [
  //     { name: 'Zombie', code: 5, total: 2 },
  //     { name: 'Quill Rat', code: 63, total: 1 },
  //   ],
  // };
  // Logger.addStream({
  //   setLevel(level) {
  //     this.level = level;
  //   },
  //   write(msg: LogMessage) {
  //     const mObj = { ...msg };
  //     delete mObj.pid;
  //     delete mObj.msg;
  //     delete mObj.time;
  //     delete mObj.hostname;
  //     delete mObj.v;

  //     console.log(msg.time.toISOString(), msg.msg, JSON.stringify(mObj));
  //   },
  // });
  // State.update(state);
});

Logger['streams'] = [];
