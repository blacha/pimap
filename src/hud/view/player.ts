import * as m from 'mithril';
import { State } from '../state';
import { XpUtil } from '../../core/xp';
import { nFormatter } from '../util';
import { ActType } from '../../core/act';
import { GameDifficulty } from '../../core/difficulty';

export const PlayerView = {
    view() {
        const player = State.game.player;
        const map = State.game.map;
        let playerXp = null;
        if (!isNaN(player.xp.current)) {
            const currentLevel = XpUtil.getCurrentLevel(player.xp.current);
            const lastLevel = XpUtil.getXpToNextLevel(currentLevel - 1)
            const nextLevel = XpUtil.getXpToNextLevel(currentLevel);
            const xpToNextLevel = nextLevel - lastLevel
            const xpRemaining = nextLevel - player.xp.current;
            const xpIntoLevel = player.xp.current - lastLevel;
            const xpPercent = (xpIntoLevel / xpToNextLevel) * 100
            playerXp = m('div', { className: 'PlayerXp' }, [
                m('div', { className: 'PlayerXp-title', style: { 'display': 'flex', 'align-items': 'baseline', 'justify-content': 'space-between' } }, [
                    m('div', { className: 'PlayerXp-Name', style: { 'font-size': '140%' } }, player.name),
                    m('div', { style: { 'font-weight': 'bold' } }, `L${currentLevel}`)
                ]),

                m('div', {
                    className: 'PlayerXp-Current', style: { 'display': 'flex', 'justify-content': 'space-between' }
                }, [
                        m('div', 'Xp: ' + nFormatter(player.xp.current, 4)),
                        m('div', { className: 'PlayerXp-Gain' }, '+' + nFormatter(player.xp.current - player.xp.start, 4))
                    ]),
                m('div', { className: 'PlayerXp-ToGo', style: { 'text-align': 'center' } }, [
                    m('div', '' + nFormatter(xpIntoLevel, 4) + ' / ' + nFormatter(xpToNextLevel, 4))
                ]),
                m('div', {
                    className: 'PlayerXp-Bar PlayerXp-Bar--background', style: { width: '100%', position: 'relative' },
                }, [
                        m('div', { className: 'PlayerXp-Bar PlayerXp-Bar--filled', style: { width: (Math.floor(xpPercent * 100) / 100) + '%' }),
                        m('div', { style: { position: 'absolute', width: '100%', top: 0, left: 0, 'text-align': 'center' } }, `${nFormatter(xpPercent, 2)}%`)
                    ])
            ]);
        }

        return m('div', { className: 'PlayerStats' }, [
            m('div', { className: 'PlayerLocation' }, [
                m('div', { className: 'PlayerLocation-Info' }, (ActType[map.act]) + ' ' + (GameDifficulty[map.difficulty]) + ' (' + map.id + ')'),
                m('div', { className: 'PlayerLocation-XY' }, player.x + ', ' + player.y)
            ]),
            playerXp
        ]);
    }
};

