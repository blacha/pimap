import { GameObject, GameObjectInteractType, GameObjectMode } from '../../core/object';
import { GameServerPacket } from '../gs.packet';
import { GSPacket } from './game.server';
import { BitConverter } from '../../util/bit/bit.converter';
import { SessionState } from '../state/session';


export class GSPacketAssignGameObject extends GSPacket {
    mode: GameObjectMode;
    type: GameObjectInteractType;
    obj: GameObject;
    x: number;
    y: number;
    uid: number;
    static id = GameServerPacket.GameObjectAssign;


    constructor(data: number[]) {
        super(GSPacketAssignGameObject.id);

        this.uid = BitConverter.ToUInt32(data, 2);
        this.obj = <GameObject>BitConverter.ToUInt16(data, 6);
        this.x = BitConverter.ToUInt16(data, 8);
        this.y = BitConverter.ToUInt16(data, 10);
        this.mode = <GameObjectMode>data[12];
        this.type = <GameObjectInteractType>data[13];
    }

    track() {
        const name = GameObject[this.obj];
        if (name == null) {
            return false;
        }
        // Logger.info({ obj: this.toJSON() });


        if (name.indexOf('Waypoint') === -1 && (this.mode === GameObjectMode.Opened || this.mode === GameObjectMode.Operating)) {
            SessionState.current.object.remove(this.uid);
            return 10;
        }

        const _t = Date.now();
        // console.log(name, GameObjectMode[this.mode], GameObjectInteractType[this.type]);

        // if (name.indexOf('Waypoint') > -1) {
        //     SessionState.current.object.set(this.uid, { _t, uid: this.uid, type: 'Waypoint', x: this.x, y: this.y, name });
        // } else if (name.indexOf('Shrine') > -1 || name.endsWith('Well')) {
        //     SessionState.current.object.set(this.uid, { _t, uid: this.uid, type: 'Shrine', x: this.x, y: this.y, name });
        // } else if (name.indexOf('CairnStone') > -1) {
        //     SessionState.current.object.set(this.uid, { _t, uid: this.uid, type: 'Stone', x: this.x, y: this.y, name });
        // } else if (isChest(this.obj, this.mode)) {
        //     const isBig = isBigChest(this.obj);
        //     SessionState.current.object.set(this.uid, { _t, uid: this.uid, type: 'Chest', x: this.x, y: this.y, name });
        // } else {
        return 10;
        // }
        // Logger.info({ obj: this.toJSON() });
        // return 20;
    }

    toJSON() {
        return {
            ...super.toJSON(),
            uid: this.uid,
            type: GameObjectInteractType[this.type],
            mode: GameObjectMode[this.mode],
            object: GameObject[this.obj],
            x: this.x,
            y: this.y
        };
    }
}



export class GSPacketSetGameObjectMode extends GSPacket {
    mode: GameObjectMode;

    uid: number;
    static id = GameServerPacket.SetGameObjectMode;


    constructor(data: number[]) {
        super(GSPacketSetGameObjectMode.id);

        this.uid = BitConverter.ToUInt32(data, 2);
        this.mode = <GameObjectMode>data[8];

    }

    track() {
        const name = GameObject[this.mode];
        const obj = SessionState.current.object.get(this.uid);

        console.log('SetMode', this.uid, GameObjectMode[this.mode], obj);

        if (this.mode === GameObjectMode.Opened || this.mode === GameObjectMode.Operating) {
            SessionState.current.object.remove(this.uid);
            return 10;
        }

        return 10;
    }

    toJSON() {
        return {
            ...super.toJSON(),
            uid: this.uid,
            mode: this.mode,
            nameName: GameObjectMode[this.mode]

        };
    }
}


export class GSPacketGameObjectModeChange extends GSPacket {
    mode: GameObjectMode;

    uid: number;
    static id = GameServerPacket.GameObjectModeChange;


    constructor(data: number[]) {
        super(GSPacketGameObjectModeChange.id);

        this.uid = BitConverter.ToUInt32(data, 2);
        this.mode = <GameObjectMode>data[8];

    }

    track() {
        const obj = SessionState.current.object.get(this.uid);
        if (obj == null) {
            return 0;
        }
        if (obj.type === 'Warp') {
            return 0;
        }

        if (this.mode === GameObjectMode.Opened || this.mode === GameObjectMode.Operating) {
            SessionState.current.object.remove(this.uid);
            return 10;
        }

        return 10;
    }

    toJSON() {
        return {
            ...super.toJSON(),
            uid: this.uid,
            mode: this.mode,
            modeName: GameObjectMode[this.mode]
        };
    }
}

