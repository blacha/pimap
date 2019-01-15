import { ActType } from './act';
import { AreaLevel } from './area';
import { GameDifficulty } from './difficulty';
import { ItemCategory, ItemQuality } from './item';
import { NpcCode } from './npc';

export interface NpcJson {
    _t: number;
    // type: UnitType;
    uid: number;
    code: NpcCode;
    name: string;
    uniqueName?: string;
    x: number;
    y: number;
    flags: {
        champion: boolean,
        minion: boolean,
        unique: boolean;
        superUnique: boolean;
        ghostly: boolean;
    };
}

export interface ObjectJson {
    _t: number;
    uid: number;
    type: string;
    name: string;
    x: number;
    y: number;
}

export interface XpJson {
    start: number;
    current: number;
}

export interface GameStateJson {
    startTime: string;
    endTime: string;
    kill: {
        count: number;
    };
    // maps: MapJSON[];
    map: {
        act: ActType;
        town: AreaLevel;
        difficulty: GameDifficulty;
        hardcore: boolean;
        id: number;
    };
    player: {
        uid?: number;
        name: string;
        x: number;
        y: number;
        level: number;
        xp: XpJson;
        mercId: number;
    };
    merc: {
        uid: number;
        xp: XpJson
    };
    npc: NpcJson[];
    object: ObjectJson[];
    item: ItemJson[];
}


export interface ItemJson {
    _t: number;
    uid: number;
    x: number;
    y: number;
    code: string;
    name: string;
    category: ItemCategory;
    quality: ItemQuality;
    level: number;
}


export interface MapStateJson {
    act: number;
    seed: number;
    maps: MapJson[];
}

export interface MapJson {
    name: string;
    origin: { x: number, y: number };
    size: { width: number, height: number };
    id: number;
    npcs: { id: number, x: number, y: number }[];
    objects: { id: number, x: number, y: number, type: 'Waypoint' | 'Exit' }[];
    map: number[][];
}


export enum MessageType {
    STATE,
    STATE_PATCH,
    MAPS
}
