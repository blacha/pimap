import m from 'mithril';
// import { NpcJson } from '../../core/game.json';
import { State } from '../state.js';
import { NpcCode, NpcUtil } from '../../core/npc.js';
import { capFirstLetter } from '../util.js';
import { KillJson, NpcJson } from '@diablo2/core';

export const MonsterListView = {
  viewMonster(monster: NpcJson) {
    return m('div', { key: monster.id }, monster.name);
  },

  view() {
    const units = State.game.units;
    const summary: Map<string, { count: number; npc: NpcJson }> = new Map();

    const uniques: NpcJson[] = [];

    for (const unit of units) {
      if (unit.type == 'player') continue;
      if (NpcUtil.isUseless(unit.code)) continue;
      if (NpcUtil.isTownFolk(unit.code)) continue;
      if (State.map && !State.map.inBoundsAbs(unit.x, unit.y)) continue;

      const flagKeys = Object.keys(unit.flags);
      if (unit.flags == null || flagKeys.length == 0) {
        const current = summary.get(unit.name) ?? { count: 0, npc: unit };
        summary.set(unit.name, current);
        current.count++;
        continue;
      }

      if (unit.flags.isSuperUnique || unit.flags.isUnique) {
        uniques.push(unit);
        continue;
      }

      for (const key of Object.keys(unit.flags)) {
        const subName = `${unit.name}:${key}`;
        const current = summary.get(subName) ?? { count: 0, npc: unit };
        summary.set(subName, current);

        current.count++;
      }
    }

    const children = [m('div', { className: 'MonsterList-Title' }, 'Nearby Monsters')];
    for (const mon of uniques) {
      const child = m('div', { className: `MonsterList-Monster  Monster-Flag-SuperUnique Monster-${mon.id}` }, [
        m('div', { className: 'MonsterList-MonsterName' }, mon.name),
        m(
          'div',
          { className: 'MonsterList-MonsterCount' },
          mon.enchants?.map((c) =>
            m('div', { className: `MonsterList-Enchant MonsterList-Enchant-${c.name}` }, c.name),
          ),
        ),
      ]);
      children.push(child);
    }
    const entries = [...summary.entries()].sort((a, b) => b[1].count - a[1].count);
    for (const [key, value] of entries) {
      let extraClasses = key.split(':')[1] || '';
      if (extraClasses !== '') {
        extraClasses = 'Monster-Flag-' + capFirstLetter(extraClasses);
      }
      if (NpcUtil.isUseless(value.npc.code)) continue;
      if (NpcUtil.isTownFolk(value.npc.code)) extraClasses += ' Monster-TownsFolk';

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
