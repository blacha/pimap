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

        const recordCount = bits.int32le();
        Logger.info({ recordCount, bin: this.fileName }, 'Reading')
        for (let i = 0; i < recordCount; i++) {
            const record = this.readRecord(bits);
            this.records.push(record);
        }

    }

    readRecord(bits: BitReader): CubeMainRecord {
        return {
            enabled: bits.byte() as any,
            ladder: bits.byte() as any,
            minDiff: bits.byte(),
            classId: bits.byte(),
            op: bits.int32le(),
            param: bits.int32le(),
            valueId: bits.int32le(),
            inputCount: bits.int16le(),
            version: bits.int16le(),

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
                item: bits.int16le(),
                itemId: bits.int16le(),
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
                item: bits.int16le(),
                itemId: bits.int16le(),
                param: bits.int16le(),
                type: bits.byte(),
                lvl: bits.byte(),
                pLvl: bits.byte(),
                iLvl: bits.byte(),
                prefixId: [bits.int16le(), bits.int16le(), bits.int16le()],
                suffixId: [bits.int16le(), bits.int16le(), bits.int16le()],
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
                mod: bits.int32le(),
                param: bits.int16le(),
                min: bits.int16le(),
                max: bits.int16le(),
                chance: bits.int16le(),
            }
            if (intputItem.mod === 0) {
                continue;
            }
            outputs.push(intputItem);
        }
        return outputs;
    }

}
