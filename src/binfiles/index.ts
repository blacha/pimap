import { readdirSync, readFileSync, existsSync } from "fs";
import { BitReader } from "../util/bit/bit.reader";
import { Logger } from "../util/log";
import { BinFiles } from "./bin.files";
import { Lang } from "./lang";

// const BIN_FILES = `/home/blacha/workspace/podrune/mpq/pod/data/global/excel`;
const BASE_PATH = `/home/blacha/workspace/podrune/mpq/pod`;
const BIN_PATH = `${BASE_PATH}/data/global/excel`;
const LANG_PATH = `${BASE_PATH}/data/local/LNG/ENG`

const LANG_FILES = ['string.txt', 'expansionsring.txt', 'patchstring.txt']

async function runMe() {

    // return;
    for (const file of LANG_FILES) {
        Logger.info({ file }, 'Loading lang');
        const filePath = LANG_PATH + '/' + file;
        if (!existsSync(filePath)) {
            continue;
        }
        const data = readFileSync(filePath).toString();
        Lang.loadLangFile(data);
    }


    const binfiles = Object.values(BinFiles).sort((a, b) => a.priority - b.priority)
    for (const binF of binfiles) {
        Logger.info({ fileName: binF.fileName }, 'Reading');
        const data = readFileSync(BIN_PATH + '/' + binF.fileName);
        const bitReader = new BitReader(data);
        await binF.read(bitReader);
    }
}


runMe()
    .catch(error => Logger.error({ error }, 'Failed to run'))