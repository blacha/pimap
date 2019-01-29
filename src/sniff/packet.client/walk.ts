import { GamePacket } from "../packet.server/game.server";
import { ClientPackets } from "../cs.packet";

abstract class WalkToPacket extends GamePacket {
    static id = ClientPackets.WalkToUnit;
}


export class WalkToUnit extends WalkToPacket {
    static id = ClientPackets.WalkToUnit;
}

export class WalkToCoord extends WalkToPacket {
    static id = ClientPackets.WalkToCoord;
}
