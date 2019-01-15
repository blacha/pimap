import { BitReader } from "../util/bit/bit.reader";
import { CubeMain } from "./bin.cube.main";
import { BinItem } from "./bin.item";

export enum BinFileType {
    CubeMain = 'CubeMain.bin',
    Misc = 'Misc.bin',
    Armor = 'Armor.bin',
    Weapon = 'Weapons.bin'
}

export interface BinFileReader {
    fileName: BinFileType;
    // requrires: BinFileType[];
    priority: number;

    read(bits: BitReader)
}


