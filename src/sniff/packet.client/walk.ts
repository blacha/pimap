import { GamePacket } from "../packet.server/game.server";
import { ClientPackets } from "../cs.packet";
import { BitReader } from "../../util/bit/bit.reader";

abstract class MoveToPacket extends GamePacket {
    static id = ClientPackets.WalkToUnit;
}


export class WalkToUnit extends MoveToPacket {
    static id = ClientPackets.WalkToUnit;
}

export class WalkToCoOrd extends MoveToPacket {
    static id = ClientPackets.WalkToCoOrd;
    x: number;
    y: number;
    constructor(bits: BitReader) {
        super(bits);
        this.x = bits.uint16();
        this.y = bits.uint16();
    }
}

export class RunToCoOrd extends MoveToPacket {
    static id = ClientPackets.RunToCoOrd;
    x: number;
    y: number;
    constructor(bits: BitReader) {
        super(bits);
        this.x = bits.uint16();
        this.y = bits.uint16();
    }
}
