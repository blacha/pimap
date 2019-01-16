import { Log } from "bblog";
import { BitReader } from "../util/bit/bit.reader";
import { Logger } from "../util/log";
import { BinFileReader, BinFileType } from "./bin.reader";
import { Lang } from "./lang";



export interface MonsterRecord {
    id: number;
}


export class BinMonster implements BinFileReader {
    fileName = BinFileType.MonStat;
    priority = 0;
    recordSize = 424;



    private log: Log;

    records: MonsterRecord[] = [];

    // /** Item offset as D2 seems to merge all these ids together */
    // get offset() {
    //     if (this.parent == null) {
    //         return 0;
    //     }
    //     return this.parent.offsetMax;
    // };

    // get offsetMax() {
    //     return this.offset + this.records.length;
    // }

    // TODO
    read(bits: BitReader) {
        this.log = Logger.child({ fileName: this.fileName });

        const length = bits.buffer.length;
        const recordCount = bits.uint32();
        const perRecord = (length - 4) / recordCount;

        this.log.info({ recordCount, bin: this.fileName, perRecord }, 'Reading')

        for (let i = 0; i < recordCount; i++) {
            const item = this.readItem(bits);
            // this.records.push(item);
            // this.log.info({ index: i, offset: toHexString(bits.offset / 8 - RECORD_SIZE, 5), code: item.code, }, Lang.t(item.code));
        }

    }

    // TODO this is well explained
    // https://github.com/eezstreet/OpenD2/blob/master/Shared/D2Common_DataTables.hpp
    readItem(bits: BitReader): MonsterRecord {
        const item: Partial<MonsterRecord> = {}

        const startOffset = bits.offset / 8;
        // item.id = bits.int16le();
        // item.baseId = bits.int16le();
        // item.nextInClass = bits.int16le();
        // item.wName = bits.int16le();
        // item.wDesc = bits.int16le();
        // bits.bytes(2)
        // item.flags = bits.int32le()
        // item.code = bits.int32le();

        // console.log(item, Lang.t(item.code));
        // item.name = bits.string(32)
        // item.invFile = {
        //     normal: bits.string(32),
        //     unique: bits.string(32),
        //     set: bits.string(32)
        // }

        // item.code = bits.string(4).trim();
        // item.codes = {
        //     normal: bits.string(4).trim(),
        //     nightmare: bits.string(4).trim(),
        //     hell: bits.string(4).trim(),
        // }
        // // console.log(bits.offsetHex())

        // item.alternateGfx = bits.string(4).trim()
        // bits.bytes(40) // unknown #2
        // item.betterGem = bits.string(4).trim();

        // bits.bytes(220) // Unknown #3

        // const nightmare = bits.string(4).trim();
        // const hell = bits.string(4).trim();
        // item.upgrade = { hell, nightmare };
        // bits.bytes(4);
        // // console.log(item, toHexString(bits.offset / 8, 2));

        const offsetMove = bits.offset / 8 - startOffset;
        if (offsetMove != this.recordSize) {
            // this.log.info({ bytes: this.recordSize - offsetMove }, 'Skipping bytes');
            bits.bytes(this.recordSize - offsetMove);
        }

        return item as MonsterRecord;
    }
}
