import { readFileSync } from "fs";
import { BitReader } from "../util/bit/bit.reader";
import { Logger } from "../util/log";
import { BinFiles } from "./bin.files";

// const BIN_FILES = `/home/blacha/workspace/podrune/mpq/pod/data/global/excel`;
const BIN_FILES = `/home/blacha/workspace/podrune/mpq/pod_graphite/data/global/excel`;

async function runMe() {
    const binfiles = Object.values(BinFiles).sort((a, b) => a.priority - b.priority)
    for (const binF of binfiles) {
        Logger.info({ fileName: binF.fileName }, 'Reading');
        const data = readFileSync(BIN_FILES + '/' + binF.fileName);
        const bitReader = new BitReader(data);
        await binF.read(bitReader);
    }
}


runMe()
    .catch(error => Logger.error({ error }, 'Failed to run'))
