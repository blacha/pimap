import { UnitType } from '../../core/unit';
import { GameServerPacket } from '../gs.packet';
import { GamePacket } from './game.server';
import { BitConverter } from '../../util/bit/bit.converter';
import { BitReader } from '../../util/bit/bit.reader';


export class GSPacketRemoveGroundUnit extends GamePacket {
    type: UnitType;
    uid: number;
    static id = GameServerPacket.RemoveGroundUnit;

    constructor(bits: BitReader) {
        super(bits);
        this.type = <UnitType>bits.byte();
        this.uid = bits.uint32();

    }

    track() {
        // SessionState.current.npc.remove(this.uid);
        return 10;
    }

    toJSON() {
        return {
            ...super.toJSON(),
            uid: this.uid,
            type: this.type
        };
    }
}


