import { loadBinFiles } from "../binfiles";
import { BinFiles } from "../binfiles/bin.files";
import { Lang } from "../binfiles/lang";
import { writeFileSync } from "fs";
import { Logger } from "../util/log";

const BASE_PATH = `/home/blacha/workspace/podrune/mpq/pod`;
const OUTPUT_FILE = './src/generated/item.name.ts';

async function runMe() {
    await loadBinFiles(BASE_PATH);

    const BASE_ITEMS = {};

    BinFiles.Weapon.records.forEach(c => BASE_ITEMS[c.code] = Lang.t(c.code));
    BinFiles.Armor.records.forEach(c => BASE_ITEMS[c.code] = Lang.t(c.code));
    BinFiles.Misc.records.forEach(c => BASE_ITEMS[c.code] = Lang.t(c.code));

    console.log(BASE_ITEMS);

    // writeFileSync('./allItems.dat', JSON.stringify(BASE_ITEMS, null, 2));

    let fileData = `export const BASE_ITEMS: { [key: string]: string } = {};`
    for (const key of Object.keys(BASE_ITEMS)) {
        const value = BASE_ITEMS[key];
        if (value.indexOf('}') > -1) {
            continue;
        }
        fileData += `\nBASE_ITEMS['${key}'] = '${value.replace('\'', '\\\'')}';`
    }

    fileData += '\n';

    writeFileSync(OUTPUT_FILE, fileData);

}



runMe().catch(error => Logger.error({ error }, 'Failed'))
