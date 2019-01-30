import { GameServerPacket } from '../gs.packet';
import { GamePacket } from './game.server';
import { BitConverter } from '../../util/bit/bit.converter';
import { SessionState } from '../state/session';
import { BitReader } from '../../util/bit/bit.reader';


export class GSPacketNPCUpdate extends GamePacket {
    uid: number;
    x: number;
    y: number;
    life: number;
    static id = GameServerPacket.NpcUpdate;

    constructor(bits: BitReader) {
        super(bits);
        this.uid = bits.uint32();
        const state = bits.byte();
        this.x = bits.uint16();
        this.y = bits.uint16();
        this.life = bits.byte();
        if (state === 0x09 || state === 0x08) {
            this.life = 0;
        }

        bits.skip(8) // Unknown
    }

    track() {
        if (this.life === 0) {
            SessionState.current.npc.remove(this.uid);
        } else {
            SessionState.current.npc.move(this.uid, this.x, this.y);
        }
        // console.log('NPCUpdate', this.uid);
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


