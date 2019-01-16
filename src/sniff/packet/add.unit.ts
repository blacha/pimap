import { UnitType } from '../../core/unit';
import { GameServerPacket } from '../gs.packet';
import { GSPacket } from './game.server';
import { BitConverter } from '../../util/bit/bit.converter';
import { BitReader } from '../../util/bit/bit.reader';


export class GSPacketAddUnit extends GSPacket {
    type: UnitType;
    uid: number;

    static id = GameServerPacket.AddUnit;

    constructor(bits: BitReader) {
        super(bits);
        this.type = bits.byte();
        this.uid = bits.uint32()
        // console.log('NPCAdd', this.uid, UnitType[this.type], data.slice(3));
    }

    track() {
        // SessionState.current.npc.report(this.uid, this.type);
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


