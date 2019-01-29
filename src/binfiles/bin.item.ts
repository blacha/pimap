import { Log } from "bblog";
import { BitReader } from "../util/bit/bit.reader";
import { Logger } from "../util/log";
import { BinFileReader, BinFileType } from "./bin.reader";

export interface ItemRecord {
    name: string;
    invFile: { normal: string, unique: string, set: string };
    code: string;
    codes: { normal: string, nightmare: string, hell: string };
    unk1: string;
    alternateGfx: string;

    unk2: string;


    betterGem: string;
    upgrade: {
        nightmare: string;
        hell: string;
    };
}

const ItemBinFiles: BinItem[] = [];

export class BinItem implements BinFileReader {
    fileName = BinFileType.Misc;
    priority = 0;
    parent: BinItem;

    constructor(fileName: BinFileType, priority: number) {
        this.fileName = fileName;
        this.priority = priority;
        ItemBinFiles.push(this);
    }

    static findItem(itemCode: number) {
        for (const bf of ItemBinFiles) {
            const res = bf.findItem(itemCode);
            if (res) {
                return res;
            }
        }
        return null;
    }


    setParent(binItem: BinItem) {
        this.parent = binItem;
    }

    private log: Log;

    records: ItemRecord[] = [];
    /** Item offset as D2 seems to merge all these ids together */
    get offset() {
        if (this.parent == null) {
            return 0;
        }
        return this.parent.offsetMax;
    };

    get offsetMax() {
        return this.offset + this.records.length;
    }


    findItem(itemIndex: number) {
        if (this.offset === -1) {
            return null;
        }
        if (this.offset > itemIndex) {
            return null;
        }
        if (this.offsetMax < itemIndex) {
            return null;
        }

        return this.records[itemIndex - this.offset];
    }

    read(bits: BitReader) {

        const RECORD_SIZE = 424;
        this.log = Logger.child({ fileName: this.fileName });

        const length = bits.buffer.length;
        const recordCount = bits.uint32();
        const perRecord = (length - 4) / recordCount;

        this.log.info({ recordCount, bin: this.fileName, perRecord }, 'Reading')

        for (let i = 0; i < recordCount; i++) {
            const item = this.readItem(bits);
            this.records.push(item);
            // this.log.info({ index: i, offset: toHexString(bits.offset / 8 - RECORD_SIZE, 5), code: item.code, }, Lang.t(item.code));
        }

    }

    // TODO this is well explained
    // https://github.com/eezstreet/OpenD2/blob/master/Shared/D2Common_DataTables.hpp
    readItem(bits: BitReader): ItemRecord {
        const item: Partial<ItemRecord> = {}
        item.name = bits.string(32)
        item.invFile = {
            normal: bits.string(32),
            unique: bits.string(32),
            set: bits.string(32)
        }

        item.code = bits.string(4).trim();
        item.codes = {
            normal: bits.string(4).trim(),
            nightmare: bits.string(4).trim(),
            hell: bits.string(4).trim(),
        }
        // console.log(bits.offsetHex())

        item.alternateGfx = bits.string(4).trim()
        bits.bytes(40) // unknown #2
        item.betterGem = bits.string(4).trim();

        bits.bytes(220) // Unknown #3

        const nightmare = bits.string(4).trim();
        const hell = bits.string(4).trim();
        item.upgrade = { hell, nightmare };
        bits.bytes(4);
        // console.log(item, toHexString(bits.offset / 8, 2));

        return item as ItemRecord;
    }
}
