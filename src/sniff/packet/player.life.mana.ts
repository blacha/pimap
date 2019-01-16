import { GameServerPacket } from '../gs.packet';
import { GSPacket } from './game.server';
import { BitConverter } from '../../util/bit/bit.converter';
import { BitReader } from '../../util/bit/bit.reader';


export enum LifeManaFlags {
    None = 0,
    Life0x8000 = 1,
    Mana0x8000 = 2,
    Mana0x4000 = 4
}
export class GSPacketPlayerLifeManaChange extends GSPacket {
    static id = GameServerPacket.PlayerLifeManaChange;

    life: number;
    mana: number;
    flags: LifeManaFlags = 0;

    constructor(bits: BitReader) {
        super(bits);

        this.life = bits.uint16() & 0x7FFF;
        this.mana = (2 * bits.uint16()) & 0x7FFF;

    }
    track() {
        return 0;
    }

    toJSON() {
        return {
            ...super.toJSON(),
            life: this.life,
            mana: this.mana
        };
    }
}


