import { BinCubeMain } from "./bin.cube.main";
import { BinItem } from "./bin.item";
import { BinFileType } from "./bin.reader";
import { BinMonster } from "./bin.monster";
import { BinExp } from "./bin.exp";

export const BinFiles = {
    CubeMain: new BinCubeMain(),
    Misc: new BinItem(BinFileType.Misc, 2),
    Armor: new BinItem(BinFileType.Armor, 1),
    Weapon: new BinItem(BinFileType.Weapon, 0),
    MonStats: new BinMonster(),
    Exp: new BinExp()
}

BinFiles.Armor.setParent(BinFiles.Weapon);
BinFiles.Misc.setParent(BinFiles.Armor);

