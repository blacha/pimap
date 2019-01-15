import { GameServerPacket } from '../gs.packet';
import { GSPacket } from './game.server';
import { BitConverter } from '../../util/bit/bit.converter';

export class GSPacketNPCStop extends GSPacket {
    life: number;
    y: number;
    x: number;
    uid: number;

    static id = GameServerPacket.NpcStop;

    constructor(data: number[]) {
        super(GSPacketNPCStop.id);

        this.uid = BitConverter.ToUInt32(data, 1);
        this.x = BitConverter.ToUInt16(data, 5);
        this.y = BitConverter.ToUInt16(data, 7);
        this.life = data[9];
    }

    track() {
        // SessionState.current.npc.move(this.uid, this.x, this.y);
        return 10;
    }

    toJSON() {
        return {
            ...super.toJSON(),
            uid: this.uid,
            x: this.x,
            y: this.y,
            life: this.life
        };
    }
}


