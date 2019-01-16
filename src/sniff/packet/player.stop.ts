import { Log } from 'bblog';
import { UnitType } from '../../core/unit';
import { GameServerPacket } from '../gs.packet';
import { GSPacket } from './game.server';
import { BitConverter } from '../../util/bit/bit.converter';
import { SessionState } from '../state/session';
import { BitReader } from '../../util/bit/bit.reader';

export class GSPacketPlayerStop extends GSPacket {
    type: UnitType;
    life: number;
    uid: number;
    x: number;
    y: number;
    static id = GameServerPacket.PlayerStop;


    constructor(bits: BitReader) {
        super(bits);

        this.type = <UnitType>bits.byte();
        this.uid = bits.uint32();
        bits.skipByte();
        this.x = bits.uint16();
        this.y = bits.uint16();
        bits.skipByte();
        this.life = bits.byte();
    }

    track() {
        SessionState.current.move(this.uid, this.x, this.y);
        return Log.DEBUG;
    }


    toJSON() {
        return {
            ...super.toJSON(),
            life: this.life,
            type: UnitType[this.type],
            uid: this.uid,
            x: this.x,
            y: this.y
        };
    }
}

