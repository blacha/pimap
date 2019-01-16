
import { NPCState } from './game.npc';
import { XpState } from './game.xp';
import { ActType } from '../../core/act';
import { AreaLevel } from '../../core/area';
import { GameDifficulty } from '../../core/difficulty';
import { Logger } from '../../util/log';
import { ItemJson, MapJson, ObjectJson, GameStateJson } from '../../core/game.json';

export class GameState {
    lastPlayerMove: number;
    player: {
        uid: number;
        name: string;
        x: number;
        y: number;
        level: number;
        mercId: number;
    };

    startTime: Date = null;
    endTime: Date = null;

    playerXp: XpState = new XpState();
    mercXp: XpState = new XpState();
    npc: NPCState = new NPCState();
    object: ObjectState = new ObjectState();
    item: ItemState = new ItemState();
    items = [];

    map: {
        id: number;
        act: ActType;
        town: AreaLevel;
        difficulty: GameDifficulty;
        hardcore: boolean;
    } = {} as any;

    maps: MapJson[];


    killCount: { [key: string]: number } = {};

    constructor() {
        this.startTime = new Date();
        this.player = { uid: null, name: '??', x: 0, y: 0, level: 0, mercId: -1 };
    }


    isMe(uid: number) {
        if (this.player.uid == null) {
            this.player.uid = 1;
            Logger.info('Guessing playerId as 1');
        }
        if (this.player.uid === uid) {
            return true;
        }
        return false;
    }

    addPlayer(uid: number, name: string) {
        if (this.player.uid == null) {
            this.player.uid = uid;
            this.player.name = name;
        }
    }

    setPlayerLevel(uid: number, level: number) {
        if (this.isMe(uid)) {
            this.player.level = level;
        }
    }

    trackPlayerXp(exp: number) {
        this.playerXp.track(exp);
    }

    trackMercXp(exp: number) {
        this.mercXp.track(exp);
    }

    move(uid: number, x: number, y: number) {
        if (this.isMe(uid)) {
            this.lastPlayerMove = Date.now();
            this.player.x = x;
            this.player.y = y;
        }
    }

    moveMaybe(x: number, y: number) {
        const diff = Math.abs(this.lastPlayerMove - Date.now());
        if (diff > 2000) {
            this.player.x = x;
            this.player.y = y;
        }
    }

    kills(uid: number, count: number) {
        this.killCount[uid] = count;
    }

    close() {
        this.endTime = new Date();
        this.npc.empty();
    }

    get closed() {
        return this.endTime != null;
    }

    toJSON(): GameStateJson {
        return {
            startTime: this.startTime.toISOString(),
            endTime: this.endTime ? this.endTime.toISOString() : null,
            player: {
                uid: this.player.uid,
                name: this.player.name,
                x: this.player.x,
                y: this.player.y,
                level: this.player.level,
                xp: this.playerXp.toJson(),
                mercId: this.player.mercId
            },
            map: {
                difficulty: this.map.difficulty,
                hardcore: this.map.hardcore,
                act: this.map.act,
                town: this.map.town,
                id: this.map.id
            },
            merc: {
                uid: 1,
                xp: this.mercXp.toJson()
            },
            object: this.object.toJson(),
            npc: this.npc.toJson(),
            item: this.item.toJson(),
            kill: this.kills[1]
        };
    }
}


interface TimeObject {
    _t: number;
}

function filterByTime<T extends TimeObject>(x: { [key: string]: T }, maxAge = 60 * 1000): T[] {
    const now = Date.now();
    const values = Object.entries(x);
    const output: T[] = [];
    for (const [key, value] of values) {
        if (Math.abs(value._t - now) > maxAge) {
            delete x[key];
            continue;
        }
        output.push(value);
    }
    return output;
}

class ItemState {
    items: { [key: string]: ItemJson } = {};
    stat(item: ItemJson) {

        if (this.items[item.uid]) {
            return;

        }
        this.items[item.uid] = item;
        item._t = Date.now();

        // console.log(item.uid, item);
    }

    toJson() {
        return filterByTime(this.items, 5 * 60 * 1000).sort((a, b) => b._t - a._t);
    }
}

class ObjectState {
    objects: { [key: string]: ObjectJson } = {};
    set(uid: number, object: ObjectJson) {
        object._t = Date.now();
        this.objects[uid] = object;
    }
    remove(uid: number) {
        delete this.objects[uid];
    }

    toJson() {
        return filterByTime(this.objects, 5 * 60 * 1000);
    }

    get(uid: number): ObjectJson {
        return this.objects[uid];
    }
    empty() {
        this.objects = {};
    }
}
