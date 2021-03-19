import { ItemJson } from '@diablo2/core';
import m from 'mithril';
import { State } from '../state';
import { timeAgo } from '../util';

function sortDate(a: ItemJson, b: ItemJson) {
  return b.updatedAt - a.updatedAt;
}
function viewLevel(level: number) {
  if (level > 0) return ` [L${level}]`;
  return '';
}

export const ItemListView = {
  view() {
    const items = State.game.items.sort(sortDate).slice(0, 15);
    const children = [m('div', { className: 'Item-Title' }, 'Item Drops')];
    for (const item of items) {
      let className = `Item  Item-${item.code.slice(0, 3)}`;
      if (item.code.startsWith('r') && item.name.includes('Rune')) className += ` Item-Rune`;
      else if (item.quality) className += ` Item-${item.quality.name}`;

      if (item.name.startsWith('Ã¿c')) item.name = item.name.substr(4);

      const child = m('div', { className }, [
        m('div', `${item.name} ${viewLevel(item.level)} (${item.x},${item.y})`),
        m('div', timeAgo(item.updatedAt)),
      ]);
      children.push(child);
    }

    return m('div', { className: 'ItemList' }, children);
  },
};
