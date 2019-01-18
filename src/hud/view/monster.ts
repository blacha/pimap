import * as m from 'mithril';
import { NpcJson } from '../../core/game.json';
import { State } from '../state.js';
import { NpcCode, NpcUtil } from '../../core/npc.js';
import { capFirstLetter } from '../util.js';

export const MonsterListView = {

    viewMonster(monster: NpcJson) {
        return m('div', { key: monster.uid }, monster.name);
    },

    view() {
        const npcs = State.game.npc;
        const summary: { [key: string]: { count: number, code: NpcCode } } = {};

        for (const npc of npcs) {
            if (NpcUtil.isUseless(npc.code) || NpcUtil.isTownFolk(npc.code)) {
                continue;
            }

            if (State.map && !State.map.inBoundsAbs(npc.x, npc.y)) {
                continue;
            }

            const summaryObj = {
                count: 0,
                code: npc.code
            };

            if (npc.flags == null) {
                summary[npc.name] = summary[npc.name] || summaryObj;
                summary[npc.name].count++;
                continue;
            }

            if (npc.flags.superUnique) {
                summary[npc.uniqueName + ':superUnique'] = summary[npc.uniqueName + ':superUnique'] || summaryObj;
                summary[npc.uniqueName + ':superUnique'].count++;
                continue;
            }

            for (const key of Object.keys(npc.flags)) {
                const subName = `${npc.name}:${key}`;
                summary[subName] = summary[subName] || summaryObj;
                summary[subName].count++;
            }
        }
        const children = [];
        const entries = Object.entries(summary).sort((a, b) => b[1].count - a[1].count);
        for (const [key, value] of entries) {
            let extraClasses = key.split(':')[1] || '';
            if (extraClasses !== '') {
                extraClasses = 'Monster-Flag-' + capFirstLetter(extraClasses);
            }

            if (NpcUtil.isTownFolk(value.code)) {
                extraClasses += ' Monster-TownsFolk';
            }

            if (NpcUtil.isUseless(value.code)) {
                continue;
            }

            const child = m('div', { className: 'MonsterList-Monster ' + extraClasses + ` Monster-${key}` }, [
                m('div', { className: 'MonsterList-MonsterName' }, key),
                m('div', { className: 'MonsterList-MonsterCount' }, String(value.count))
            ]);
            children.push(child);
        }

        return m('div', { className: 'MonsterList' },
            children
        );
    }
};
