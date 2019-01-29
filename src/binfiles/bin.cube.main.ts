import { BinFileReader, BinFileType } from "./bin.reader";
import { BitReader } from "../util/bit/bit.reader";
import { Logger } from "../util/log";
import { BinFiles } from "./bin.files";
import { BinItem } from "./bin.item";
import { Lang } from "./lang";


export interface CubeMainRecordInput {
    inputFlags: number;
    itemType: number;
    item: number;
    quality: number;
    quantity: number;
}

export interface CubeMainRecordOutput {
    itemFlags: number;
    itemType: number;
    item: number;
    itemId: number;
    param: number;
    type: number;
    lvl: number;
    pLvl: number;
    iLvl: number;
    prefixId: [number, number, number];
    suffixId: [number, number, number];
    mods: CubeMainRecordOutputMod[]
}

export interface CubeMainRecordOutputMod {
    mod: number;
    param: number;
    min: number;
    max: number;
    chance: number;
}

interface CubeMainRecord {
    enabled: boolean;
    ladder: boolean;
    minDiff: number;
    classId: number;
    op: number;
    param: number;
    valueId: number;
    inputCount: number;
    version: number;
    inputs: CubeMainRecordInput[];
    outputs: CubeMainRecordOutput[];
}

const INPUT_COUNT = 7;
const OUTPUT_COUNT = 3;
const MOD_COUNT = 5;

export class BinCubeMain implements BinFileReader {
    // requrires: BinFileType[] = [];
    fileName = BinFileType.CubeMain;
    priority = 10;

    records: CubeMainRecord[] = [];
    read(bits: BitReader) {

        const recordCount = bits.uint32();
        Logger.info({ recordCount, bin: this.fileName }, 'Reading')
        for (let i = 0; i < recordCount; i++) {
            const record = this.readRecord(bits);
            this.records.push(record);
            // if (this.records.length > 400) {
            //     console.log(record.inputs.map(c => Lang.t(BinItem.findItem(c.item)))))
            // }
        }

    }

    readRecord(bits: BitReader): CubeMainRecord {
        return {
            enabled: bits.byte() as any,
            ladder: bits.byte() as any,
            minDiff: bits.byte(),
            classId: bits.byte(),
            op: bits.uint32(),
            param: bits.uint32(),
            valueId: bits.uint32(),
            inputCount: bits.uint16(),
            version: bits.uint16(),

            inputs: this.readInputs(bits),
            outputs: this.readOutputs(bits) //this.readOutputs(bits)

        }
    }
    readInputs(bits: BitReader) {
        const inputs: CubeMainRecordInput[] = [];
        for (let i = 0; i < INPUT_COUNT; i++) {
            const intputItem = {
                inputFlags: bits.byte(),
                itemType: bits.byte(),
                item: bits.uint16(),
                itemId: bits.uint16(),
                quality: bits.byte(),
                quantity: bits.byte()
            }
            if (intputItem.item === 0) {
                continue;
            }
            inputs.push(intputItem);
        }
        return inputs;
    }

    readOutputs(bits: BitReader) {
        const outputs = [];
        for (let i = 0; i < OUTPUT_COUNT; i++) {
            const intputItem = {
                itemFlags: bits.byte(),
                itemType: bits.byte(),
                item: bits.uint16(),
                itemId: bits.uint16(),
                param: bits.uint16(),
                type: bits.byte(),
                lvl: bits.byte(),
                pLvl: bits.byte(),
                iLvl: bits.byte(),
                prefixId: [bits.uint16(), bits.uint16(), bits.uint16()],
                suffixId: [bits.uint16(), bits.uint16(), bits.uint16()],
                mods: this.readOutputMods(bits)
            }
            if (intputItem.item === 65535 || intputItem.item === 0) {
                continue;
            }
            outputs.push(intputItem);
        }
        return outputs;
    }

    readOutputMods(bits: BitReader) {
        const outputs = [];
        for (let i = 0; i < MOD_COUNT; i++) {
            const intputItem = {
                mod: bits.uint32(),
                param: bits.uint16(),
                min: bits.uint16(),
                max: bits.uint16(),
                chance: bits.uint16(),
            }
            if (intputItem.mod === 0) {
                continue;
            }
            outputs.push(intputItem);
        }
        return outputs;
    }

}
