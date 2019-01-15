import { BitReader } from "../util/bit/bit.reader";
import { BinCubeMain } from "./bin.cube.main";
import { BinItem } from "./bin.item";

export enum BinFileType {
    CubeMain = 'CubeMain.bin',
    Misc = 'Misc.bin',
    Armor = 'Armor.bin',
    Weapon = 'Weapons.bin',
    MonStat = 'MonStats.bin'
}

export interface BinFileReader {
    fileName: BinFileType;
    // requrires: BinFileType[];
    priority: number;

    read(bits: BitReader)
}


