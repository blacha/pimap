import { GameServerPacket } from '../gs.packet';
import { GSPacket } from './game.server';
import { BitConverter } from '../../util/bit/bit.converter';
import { BitReader } from '../../util/bit/bit.reader';

export class GSPacketNPCStop extends GSPacket {
    life: number;
    y: number;
    x: number;
    uid: number;

    static id = GameServerPacket.NpcStop;

    constructor(bits: BitReader) {
        super(bits);

        this.uid = bits.uint32();
        this.x = bits.uint16();
        this.y = bits.uint16();
        this.life = bits.byte();
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


