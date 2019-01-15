import { WarpType } from '../../core/object';
import { UnitType } from '../../core/unit';
import { GameServerPacket } from '../gs.packet';
import { GSPacket } from './game.server';
import { BitConverter } from '../../util/bit/bit.converter';
import { SessionState } from '../state/session';


export class GSPacketAssignWarp extends GSPacket {
    type: UnitType;
    warp: WarpType;
    x: number;
    y: number;
    uid: number;
    static id = GameServerPacket.AssignWarp;


    constructor(data: number[]) {
        super(GSPacketAssignWarp.id);

        this.uid = BitConverter.ToUInt32(data, 2);
        this.x = BitConverter.ToUInt16(data, 7);
        this.y = BitConverter.ToUInt16(data, 9);
        this.type = <UnitType>data[1];
        this.warp = <WarpType>data[6];

    }

    track() {
        const name = WarpType[this.warp];
        if (name == null) {
            return false;
        }

        SessionState.current.object.set(this.uid, { _t: Date.now(), uid: this.uid, type: 'Warp', x: this.x, y: this.y, name });
        return 10;
    }

    toJSON() {
        return {
            ...super.toJSON(),
            uid: this.uid,
            type: this.type,
            name: WarpType[this.warp],
            x: this.x,
            y: this.y
        };
    }
}


