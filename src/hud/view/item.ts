import * as m from 'mithril';
import { State } from '../state';
import { ItemQuality } from '../../core/item';
import { timeAgo } from '../util';

function viewLevel(level: number) {
    if (level > 0) {
        return ` [L${level}]`;
    }
    return '';
}
export const ItemListView = {

    view() {
        const summary: { [key: string]: number } = {};
        const items = State.game.item;
        const children = [];
        for (const item of items) {
            const className = `Item Item-${ItemQuality[item.quality]} Item-${item.code}`;
            const child = m('div', { className }, [
                m('div', `${item.name} ${viewLevel(item.level)} (${item.x},${item.y})`),
                m('div', timeAgo(item._t))
            ]);
            children.push(child);
        }

        return m('div', { className: 'ItemList' },
            children
        );
    }
};

