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
            const nextLevel = XpUtil.getXpToNextLevel(currentLevel);
            const xpRemaining = nextLevel - player.xp.current;
            playerXp = m('div', { className: 'PlayerXp' }, [
                m('div', { className: 'PlayerXp-Name' }, player.name + ` (L${currentLevel}) `),
                m('div', { className: 'PlayerXp-Current' }, [
                    m('div', 'Current: ' + nFormatter(player.xp.current, 4)),
                    m('div', { className: 'PlayerXp-Gain' }, '+' + nFormatter(player.xp.current - player.xp.start, 4))
                ]),
                m('div', { className: 'PlayerXp-ToGo' }, [
                    m('div', 'Remaining: ' + nFormatter(xpRemaining, 4))
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

