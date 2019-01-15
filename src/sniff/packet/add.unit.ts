import { UnitType } from '../../core/unit';
import { GameServerPacket } from '../gs.packet';
import { GSPacket } from './game.server';
import { BitConverter } from '../../util/bit/bit.converter';


export class GSPacketAddUnit extends GSPacket {
    type: UnitType;
    uid: number;

    static id = GameServerPacket.AddUnit;


    constructor(data: number[]) {
        super(GSPacketAddUnit.id);

        this.uid = BitConverter.ToUInt32(data, 2);
        this.type = <UnitType>data[1];
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


