import { WarpType } from '../../core/object';
import { UnitType } from '../../core/unit';
import { GameServerPacket } from '../gs.packet';
import { GSPacket } from './game.server';
import { BitConverter } from '../../util/bit/bit.converter';
import { SessionState } from '../state/session';
import { BitReader } from '../../util/bit/bit.reader';


export class GSPacketAssignWarp extends GSPacket {
    type: UnitType;
    warp: WarpType;
    x: number;
    y: number;
    uid: number;
    static id = GameServerPacket.AssignWarp;

    constructor(bits: BitReader) {
        super(bits);

        this.type = <UnitType>bits.byte();
        this.uid = bits.uint32()
        this.warp = <WarpType>bits.byte();
        this.x = bits.uint16();
        this.y = bits.uint16();
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


