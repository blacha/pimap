import { Log } from 'bblog';
import { GameServerPacket } from '../gs.packet';
import { GSPacket } from './game.server';
import { BitConverter } from '../../util/bit/bit.converter';
import { BitReader } from '../../util/bit/bit.reader';
import { SessionState } from '../state/session';

export class GSPacketExpGain extends GSPacket {
    exp: number;

    constructor(id: GameServerPacket) {
        super(id);
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

    constructor(data: number[]) {
        super(GSPacketByteToExperience.id);
        this.exp = data[1];
    }
}


export class GSPacketWordToExperience extends GSPacketExpGain {
    static id = GameServerPacket.WordToExperience;

    constructor(data: number[]) {
        super(GSPacketWordToExperience.id);
        this.exp = BitConverter.ToUInt16(data, 1);
    }
}

let lastDWordXp = 0;

export class GSPacketDWordToExperience extends GSPacketExpGain {
    static id = GameServerPacket.DWordToExperience;

    expUpdate: number;
    constructor(data: number[]) {
        super(GSPacketDWordToExperience.id);
        const br = new BitReader(data, 8);
        this.expUpdate = br.bits(32);
    }

    track() {
        SessionState.current.playerXp.set(this.expUpdate);
        return Log.INFO;
    }

}



export class GSPacketMercExpGain extends GSPacket {
    exp: number;

    constructor(id: GameServerPacket) {
        super(id);
    }

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

    constructor(data: number[]) {
        super(GSPacketMercByteToExperience.id);
        this.exp = data[1];
    }
}


export class GSPacketMercWordToExperience extends GSPacketExpGain {
    static id = GameServerPacket.MercWordToExperience;

    constructor(data: number[]) {
        super(GSPacketMercWordToExperience.id);
        this.exp = BitConverter.ToUInt16(data, 1);
    }
}
