import { NpcUtil } from "../../core/npc";
import { NpcJson } from "../../core/game.json";
import { Logger } from "../../util/log";


export class NPCState {
    npcs: { [key: string]: NpcJson } = {};

    add(uid: number, monster: NpcJson) {
        monster._t = Date.now();

        this.npcs[uid] = monster;
    }

    report(uid: number, type, x, y) {
        // noop
    }

    move(uid: number, x: number, y: number) {
        let npc = this.npcs[uid];
        // console.log('uid', npc, uid)
        if (npc == null) {
            Logger.error({ uid }, 'Missing npc');
            if (uid == null) {
                console.trace('uid is null')
            }
            // console.trace('g');
            npc = this.npcs[uid] = {
                _t: Date.now(),
                uid,
                x,
                y,
                code: -1,
                name: 'Unkown',
                flags: null
            };
        }

        npc.x = x;
        npc.y = y;
        npc._t = Date.now();
    }
    remove(uid: number) {
        const monster = this.npcs[uid];
        if (monster == null) {
            return;
        }
        // console.trace('remove', uid, monster.name);

        delete this.npcs[uid];
    }
    empty() {
        this.npcs = {};
    }

    toJson(): NpcJson[] {
        const maxAge = 5 * 60 * 1000;
        const now = Date.now();
        const values = Object.entries(this.npcs);
        const output: NpcJson[] = [];
        for (const [key, npc] of values) {
            if (Math.abs(npc._t - now) > maxAge) {
                delete this.npcs[key];
                continue;
            }
            if (NpcUtil.isUseless(npc.code)) {
                continue;
            }
            output.push(npc);
        }
        return output;

    }
}
