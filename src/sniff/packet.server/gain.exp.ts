import { Log } from 'bblog';
import { BitReader } from '../../util/bit/bit.reader';
import { GameServerPacket } from '../gs.packet';
import { SessionState } from '../state/session';
import { GamePacket } from './game.server';
import { toHexString } from '../../util/to.hex';

export class GSPacketExpGain extends GamePacket {
    exp: number;

    constructor(bits: BitReader) {
        super(bits);
    }

    track() {
        SessionState.current.playerXp.track(this.exp);
        return 0;
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

    toJSON() {
        return {
            ...super.toJSON(),
            expUpdate: this.expUpdate
        }
    }

}



export class GSPacketMercExpGain extends GamePacket {
    exp: number;
    uid: number;
    unkn: number;

    constructor(bits: BitReader) {
        super(bits);
        this.unkn = bits.byte();
        this.uid = bits.uint32();

    }
    track() {
        SessionState.current.mercXp.track(this.exp);
        return 0;
    }


    toJSON() {
        return {
            ...super.toJSON(),
            experience: this.exp,
            uid: this.uid,
            unkn: this.unkn
        };
    }
}


export class GSPacketMercByteToExperience extends GSPacketMercExpGain {
    static id = GameServerPacket.MercByteToExperience;
    constructor(bits: BitReader) {
        super(bits);
        this.exp = bits.byte();
    }

}


export class GSPacketMercWordToExperience extends GSPacketMercExpGain {
    static id = GameServerPacket.MercWordToExperience;

    constructor(bits: BitReader) {
        super(bits);
        this.exp = bits.uint16();
    }
}
