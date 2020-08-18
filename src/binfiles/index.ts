import { readdirSync, readFileSync, existsSync } from 'fs';
import { BitReader } from '../util/bit/bit.reader';
import { Logger } from '../util/log';
import { BinFiles } from './bin.files';
import { Lang } from './lang';

const LANG_FILES = ['string.txt', 'expansionsring.txt', 'patchstring.txt'];

export async function loadLangFiles(basePath: string) {
  const LANG_PATH = `${basePath}/data/local/LNG/ENG`;
  for (const file of LANG_FILES) {
    Logger.info({ file }, 'Loading lang');
    const filePath = LANG_PATH + '/' + file;
    if (!existsSync(filePath)) {
      continue;
    }
    const data = readFileSync(filePath).toString();
    Lang.loadLangFile(data);
  }
}

export async function loadBinFiles(basePath: string) {
  const BIN_PATH = `${basePath}/data/global/excel`;

  const binfiles = Object.values(BinFiles).sort((a, b) => a.priority - b.priority);
  for (const binF of binfiles) {
    Logger.info({ fileName: binF.fileName }, 'Reading');
    const data = readFileSync(BIN_PATH + '/' + binF.fileName);
    const bitReader = new BitReader(data);
    await binF.read(bitReader);
  }
}

export async function loadMpqData(basePath: string) {
  // return;
  await loadLangFiles(basePath);
  await loadBinFiles(basePath);
}
