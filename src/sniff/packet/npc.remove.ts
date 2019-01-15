import { UnitType } from '../../core/unit';
import { GameServerPacket } from '../gs.packet';
import { GSPacket } from './game.server';
import { BitConverter } from '../../util/bit/bit.converter';


export class GSPacketRemoveGroundUnit extends GSPacket {
    type: UnitType;
    uid: number;
    static id = GameServerPacket.RemoveGroundUnit;


    constructor(data: number[]) {
        super(GSPacketRemoveGroundUnit.id);
        this.type = <UnitType>data[1];
        this.uid = BitConverter.ToUInt32(data, 2);

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


