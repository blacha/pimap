import { CubeMain } from "./bin.cube.main";
import { BinItem } from "./bin.item";
import { BinFileType } from "./bin.reader";

export const BinFiles = {
    CubeMain: new CubeMain(),
    Misc: new BinItem(BinFileType.Misc, 2),
    Armor: new BinItem(BinFileType.Armor, 1),
    Weapon: new BinItem(BinFileType.Weapon, 0)
}

BinFiles.Armor.setParent(BinFiles.Weapon);
BinFiles.Misc.setParent(BinFiles.Armor);

