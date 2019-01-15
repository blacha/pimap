import { GameServerPacket } from '../gs.packet';
import { GSPacket } from './game.server';
import { BitConverter } from '../../util/bit/bit.converter';

export class GSPacketNPCAction extends GSPacket {
    y: number;
    x: number;
    uid: number;

    static id = GameServerPacket.NpcAction;

    constructor(data: number[]) {
        super(GSPacketNPCAction.id);

        this.uid = BitConverter.ToUInt32(data, 1);
        this.x = BitConverter.ToUInt16(data, 12);
        this.y = BitConverter.ToUInt16(data, 14);
    }

    track() {
        // console.log('NPCAction', this.uid, this.x, this.y);
        // SessionState.current.npc.move(this.uid, this.x, this.y);
        return 10;
    }

    toJSON() {
        return {
            ...super.toJSON(),
            uid: this.uid,
            x: this.x,
            y: this.y
        };
    }
}


