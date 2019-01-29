import { UnitType } from '../../core/unit';
import { BitReader } from '../../util/bit/bit.reader';
import { GameServerPacket } from '../gs.packet';
import { GamePacket } from './game.server';


export class GSPacketAddUnit extends GamePacket {
    type: UnitType;
    uid: number;

    static id = GameServerPacket.AddUnit;

    constructor(bits: BitReader) {
        super(bits);
        this.type = bits.byte();
        this.uid = bits.uint32()
    }

    track() {
        return 10;
    }

    toJSON() {
        return {
            ...super.toJSON(),
            uid: this.uid,
            type: UnitType[this.type]
        };
    }
}


