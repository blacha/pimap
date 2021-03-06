import m from 'mithril';
import { State } from '../state';
import { ItemQuality } from '@diablo2/data';
import { timeAgo } from '../util';

function viewLevel(level: number) {
  if (level > 0) return ` [L${level}]`;
  return '';
}

export const ItemListView = {
  view() {
    const items = State.game.item;
    const children = [];
    for (const item of items) {
      let className = `Item  Item-${item.code}`;
      if (item.code.startsWith('r') && item.name.includes('Rune')) className += ` Item-Rune`;
      if (item.quality) className += ` Item-${item.quality.name}`;

      const child = m('div', { className }, [
        m('div', `${item.name} ${viewLevel(item.level)} (${item.x},${item.y})`),
        m('div', timeAgo(item.updatedAt)),
      ]);
      children.push(child);
    }

    return m('div', { className: 'ItemList' }, children);
  },
};
