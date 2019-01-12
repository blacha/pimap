import { Point } from "./size";

export interface D2Map {
    id: number;
    name: string;
    size: { width: number; height: number; };
    offset: Point;
    objects: D2MapObject[];
    map: number[][];
}

export interface D2MapObject extends Point {
    id: number;
    type: 'chest' | 'waypoint' | 'npc'
}
