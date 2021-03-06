// //tslint: disable-no-console

import m from 'mithril';
import { State } from './state';
import { ItemListView } from './view/item';
import { MonsterListView } from './view/monster';
import { PlayerView } from './view/player';
import { WS } from './socket';
import { SpriteSheet } from './maprender/sprite';
import { Logger } from '../util/log';

export const HtmlView = {
  view() {
    if (State.game == null) {
      return m('div', 'Loading...');
    }

    return [PlayerView.view(), ItemListView.view(), MonsterListView.view()];
  },
};

document.addEventListener('DOMContentLoaded', async () => {
  Logger.info('---Loading...');
  State.setCanvas(document.getElementById('map-layer') as HTMLCanvasElement);

  // Load the sprite sheet
  const spriteImage = new Image();
  spriteImage.src = '/assets/sprites.png';
  await new Promise((res) => (spriteImage.onload = res));
  State.sprites = new SpriteSheet(spriteImage);

  // State.game = { map: { id: 1240694333, difficulty: 0 } };
  m.mount(document.getElementById('main'), HtmlView);
  WS.start('ws://localhost:40510');
});

Logger['streams'] = [];
