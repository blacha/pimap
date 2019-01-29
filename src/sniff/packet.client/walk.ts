import { GamePacket } from "../packet.server/game.server";
import { ClientPackets } from "../cs.packet";
import { BitReader } from "../../util/bit/bit.reader";

abstract class MoveToPacket extends GamePacket {
    static id = ClientPackets.WalkToUnit;
}


export class WalkToUnit extends MoveToPacket {
    static id = ClientPackets.WalkToUnit;
}

export class WalkToCoord extends MoveToPacket {
    static id = ClientPackets.WalkToCoord;
    x: number;
    y: number;
    constructor(bits: BitReader) {
        super(bits);
        this.x = bits.uint16();
        this.y = bits.uint16();
    }
}

export class RunToCoord extends MoveToPacket {
    static id = ClientPackets.RunToCoord;
    x: number;
    y: number;
    constructor(bits: BitReader) {
        super(bits);
        this.x = bits.uint16();
        this.y = bits.uint16();
    }
}
