import { readFileSync } from 'fs';
import { BitReader } from '../util/bit/bit.reader';
import { Logger } from '../util/log';

const fileName = process.argv[2];
if (fileName == null) {
  Logger.fatal('Invalid filename');
  process.exit(1);
}
Logger.info({ fileName }, 'Reading..');
const data = readFileSync(fileName);

const bitReader = new BitReader(data);
const recordCount = bitReader.bits(32);

console.log(recordCount);

const RUNE_WORD_SIZE = 288;
const RUNE_WORD_OFFSET = 4;
let offset = 4;
function readRuneWord() {
  const rw = {
    id: bitReader.string(64),
    name: bitReader.string(64),
  };

  offset = offset + 288;
  const toRead = offset * 8 - bitReader.offset;

  bitReader.bits(toRead);
  return rw;
}

for (let i = 0; i < recordCount; i++) {
  console.log(readRuneWord());
}
