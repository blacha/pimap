import m from 'mithril';
import { ActType } from '../../core/act';
import { GameDifficulty } from '../../core/difficulty';
import { XpUtil } from '../../core/xp';
import { State } from '../state';
import { nFormatter, prettyTimeSince } from '../util';

export const PlayerView = {
  view() {
    const player = State.game.player;
    const map = State.game.map;

    const playerStats = [
      m('div', { className: 'PlayerLocation' }, [
        m(
          'div',
          { className: 'PlayerLocation-Info' },
          ActType[map.act] + ' ' + GameDifficulty[map.difficulty] + ' (' + map.difficulty + ')',
        ),
        m('div', { className: 'PlayerLocation-XY' }, player.x + ', ' + player.y),
      ]),
    ];

    const header = m('div', { className: 'PlayerStats' }, playerStats);
    if (isNaN(player.xp.current)) return header;

    const currentLevel = XpUtil.getCurrentLevel(player.xp.current);
    const lastLevel = XpUtil.getXpToNextLevel(currentLevel - 1);
    const nextLevel = XpUtil.getXpToNextLevel(currentLevel);

    const xpToNextLevel = nextLevel - lastLevel;
    const xpRemaining = nextLevel - player.xp.current;
    const xpIntoLevel = player.xp.current - lastLevel;
    const xpPercent = (xpIntoLevel / xpToNextLevel) * 100;

    const xpGain = player.xp.current - player.xp.start;
    const startTime = new Date(State.game.createdAt);

    const seconds = Math.floor((Date.now() - startTime.getTime()) / 1000);
    const xpPerSecond = xpGain / seconds;
    const playerXp = m('div', { className: 'PlayerXp' }, [
      m(
        'div',
        {
          className: 'PlayerXp-title',
          style: { display: 'flex', 'align-items': 'baseline', 'justify-content': 'space-between' },
        },
        [
          m('div', { className: 'PlayerXp-Name', style: { 'font-size': '140%' } }, 'PlayerName'),
          m('div', { style: { 'font-weight': 'bold' } }, `L${currentLevel}`),
        ],
      ),

      m(
        'div',
        {
          className: 'PlayerXp-Current',
          style: { display: 'flex', 'justify-content': 'space-between' },
        },
        [
          m('div', 'Xp: ' + nFormatter(player.xp.current, 4)),
          m('div', { className: 'PlayerXp-Gain' }, `+${nFormatter(xpGain, 4)}`),
        ],
      ),
      m('div', { className: 'PlayerXp-ToGo', style: { 'text-align': 'center' } }, [
        m('div', `${nFormatter(xpIntoLevel, 4)}  /  ${nFormatter(xpToNextLevel, 4)} - ${nFormatter(xpRemaining, 4)}`),
      ]),
      m(
        'div',
        {
          className: 'PlayerXp-Bar PlayerXp-Bar--background',
          style: { width: '100%', position: 'relative' },
        },
        [
          m(
            'div',
            {
              className: 'PlayerXp-Bar PlayerXp-Bar--filled',
              style: { width: Math.floor(xpPercent * 100) / 100 + '%' },
            },
            '',
          ),
          m(
            'div',
            { style: { position: 'absolute', width: '100%', top: 0, left: 0, 'text-align': 'center' } },
            `${nFormatter(xpPercent, 2)}%`,
          ),
        ],
      ),
      m(
        'div',
        {
          className: 'PlayerXp-Time',
        },
        [m('div', {}, `Time ${prettyTimeSince(startTime)}`), m('div', {}, `Xp/m ${nFormatter(xpPerSecond * 60, 2)}`)],
      ),
    ]);

    playerStats.push(playerXp);

    return header;
  },
};
