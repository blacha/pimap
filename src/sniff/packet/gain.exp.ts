import { Log } from 'bblog';
import { GameServerPacket } from '../gs.packet';
import { GSPacket } from './game.server';
import { BitConverter } from '../../util/bit/bit.converter';
import { BitReader } from '../../util/bit/bit.reader';
import { SessionState } from '../state/session';

export class GSPacketExpGain extends GSPacket {
    exp: number;

    constructor(bits: BitReader) {
        super(bits);
    }

    track() {
        SessionState.current.playerXp.track(this.exp);
        return Log.TRACE;
    }

    toJSON() {
        return {
            ...super.toJSON(),
            experience: this.exp
        };
    }
}

export class GSPacketByteToExperience extends GSPacketExpGain {
    static id = GameServerPacket.ByteToExperience;

    constructor(bits: BitReader) {
        super(bits);
        this.exp = bits.byte();
    }
}


export class GSPacketWordToExperience extends GSPacketExpGain {
    static id = GameServerPacket.WordToExperience;

    constructor(bits: BitReader) {
        super(bits);
        this.exp = bits.uint16();
    }
}

let lastDWordXp = 0;

export class GSPacketDWordToExperience extends GSPacketExpGain {
    static id = GameServerPacket.DWordToExperience;

    expUpdate: number;
    constructor(bits: BitReader) {
        super(bits);
        this.expUpdate = bits.uint32();
    }

    track() {
        SessionState.current.playerXp.set(this.expUpdate);
        return Log.INFO;
    }

}



export class GSPacketMercExpGain extends GSPacket {
    exp: number;


    track() {
        SessionState.current.mercXp.track(this.exp);
        return true;
    }


    toJSON() {
        return {
            ...super.toJSON(),
            experience: this.exp
        };
    }
}


export class GSPacketMercByteToExperience extends GSPacketExpGain {
    static id = GameServerPacket.MercByteToExperience;

    constructor(bits: BitReader) {
        super(bits);
        this.exp = bits.byte();
    }
}


export class GSPacketMercWordToExperience extends GSPacketExpGain {
    static id = GameServerPacket.MercWordToExperience;

    constructor(bits: BitReader) {
        super(bits);
        this.exp = bits.uint16();
    }
}
