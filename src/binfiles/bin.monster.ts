import { Log } from 'bblog';
import { BitReader } from '../util/bit/bit.reader';
import { Logger } from '../util/log';
import { BinFileReader, BinFileType } from './bin.reader';
import { Lang } from './lang';

export interface MonsterRecord {
  id: number;
  res: [number[], number[], number[]];
}

export class BinMonStat implements BinFileReader {
  fileName = BinFileType.MonStat;
  priority = 0;
  recordSize = 424;

  private log: Log;

  records: MonsterRecord[] = [];

  // TODO
  read(bits: BitReader) {
    this.log = Logger.child({ fileName: this.fileName });

    const length = bits.buffer.length;
    const recordCount = bits.uint32();
    const perRecord = (length - 4) / recordCount;

    this.log.info({ recordCount, bin: this.fileName, perRecord }, 'Reading');

    for (let i = 0; i < recordCount; i++) {
      const item = this.readItem(bits);
    }
  }

  readItem(bits: BitReader): MonsterRecord {
    const item: Partial<MonsterRecord> = {};

    item.id = bits.uint16();

    console.log(item);

    const startOffset = bits.offset / 8;

    const offsetMove = bits.offset / 8 - startOffset;
    if (offsetMove != this.recordSize) {
      // this.log.info({ bytes: this.recordSize - offsetMove }, 'Skipping bytes');
      bits.bytes(this.recordSize - offsetMove);
    }

    return item as MonsterRecord;
  }
}
