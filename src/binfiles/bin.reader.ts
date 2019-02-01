import { BitReader } from "../util/bit/bit.reader";
import { BinCubeMain } from "./bin.cube.main";
import { BinItem } from "./bin.item";

export enum BinFileType {
    CubeMain = 'cubemain.bin',
    Misc = 'misc.bin',
    Armor = 'armor.bin',
    Weapon = 'weapons.bin',
    MonStat = 'monstats.bin',
    SuperUnique = 'superuniques.bin',

    Experience = 'experience.bin'
}

export interface BinFileReader {
    fileName: BinFileType;
    // requrires: BinFileType[];
    priority: number;

    read(bits: BitReader)
}


