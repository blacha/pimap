import m from 'mithril';
import { NpcJson } from '../../core/game.json';
import { State } from '../state.js';
import { NpcCode, NpcUtil } from '../../core/npc.js';
import { capFirstLetter } from '../util.js';
import { KillJson } from '@diablo2/core/build/state/json';

export const MonsterListView = {
  viewMonster(monster: NpcJson) {
    return m('div', { key: monster.uid }, monster.name);
  },

  view() {
    const units = State.game.units;
    const summary: { [key: string]: { count: number; code: NpcCode } } = {};

    for (const unit of units) {
      if (unit.type == 'player') continue;
      if (NpcUtil.isUseless(unit.code)) continue;
      if (NpcUtil.isTownFolk(unit.code)) continue;
      if (State.map && !State.map.inBoundsAbs(unit.x, unit.y)) continue;

      const summaryObj = {
        count: 0,
        code: unit.code,
      };

      if (unit.flags == null) {
        summary[unit.name] = summary[unit.name] || summaryObj;
        summary[unit.name].count++;
        continue;
      }

      if (unit.flags.isSuperUnique) {
        summary[unit.uniqueName + ':superUnique'] = summary[unit.uniqueName + ':superUnique'] || summaryObj;
        summary[unit.uniqueName + ':superUnique'].count++;
        continue;
      }

      for (const key of Object.keys(unit.flags)) {
        const subName = `${unit.name}:${key}`;
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

      if (NpcUtil.isUseless(value.code)) continue;

      const child = m('div', { className: 'MonsterList-Monster ' + extraClasses + ` Monster-${key}` }, [
        m('div', { className: 'MonsterList-MonsterName' }, key),
        m('div', { className: 'MonsterList-MonsterCount' }, String(value.count)),
      ]);
      children.push(child);
    }

    return m('div', { className: 'MonsterList' }, children);
  },
};

export const MonsterKillList = {
  viewMonster(monster: KillJson) {
    return m('div', { key: monster.code }, monster.name);
  },

  view() {
    const kills = State.game.kills.sort((a, b) => b.total - a.total);
    const superUniques = [];
    const children = [];

    for (const kill of kills) {
      if (kill.special) {
        superUniques.push(...kill.special.map((c) => m('div', { className: 'KillList-SuperUnique' }, c)));
      }

      const child = m('div', { className: `KillList-Monster Monster-${kill.code}` }, [
        m('div', { className: 'KillList-MonsterName' }, kill.name),
        m('div', { className: 'KillList-MonsterCount' }, String(kill.total)),
      ]);
      children.push(child);
    }

    return m('div', { className: 'KillList' }, [
      m('div', { className: 'KillList-Title' }, 'Kills'),
      superUniques,
      children,
    ]);
  },
};
