import { readFileSync } from "fs";
import { BitReader } from "../util/bit/bit.reader";
import { Logger } from "../util/log";

const fileName = process.argv[2];
if (fileName == null) {
    Logger.fatal('Invalid filename');
    process.exit(1);
}
Logger.info({ fileName }, 'Reading..')
const data = readFileSync(fileName);


const bitReader = new BitReader(data);

const INPUT_COUNT = 7;
const OUTPUT_COUNT = 3;

function readInputs(count: number) {
    const inputs = [];
    for (let i = 0; i < count; i++) {
        const intputItem = {
            inputFlags: bitReader.byte(),
            itemType: bitReader.byte(),
            item: bitReader.int16le(),
            itemId: bitReader.int16le(),
            quality: bitReader.byte(),
            quantity: bitReader.byte()
        }
        if (intputItem.item === 0) {
            continue;
        }
        inputs.push(intputItem);
    }
    return inputs;
}
function readOutputs(count: number) {
    const outputs = [];
    for (let i = 0; i < count; i++) {
        const intputItem = {
            itemFlags: bitReader.byte(),
            itemType: bitReader.byte(),
            item: bitReader.int16le(),
            itemId: bitReader.int16le(),
            param: bitReader.int16le(),
            type: bitReader.byte(),
            lvl: bitReader.byte(),
            pLvl: bitReader.byte(),
            iLvl: bitReader.byte(),
            prefixId: [bitReader.int16le(), bitReader.int16le(), bitReader.int16le()],
            suffixId: [bitReader.int16le(), bitReader.int16le(), bitReader.int16le()],
            mods: readOutputMod(5)
        }
        if (intputItem.item === 65535 || intputItem.item === 0) {
            continue;
        }
        outputs.push(intputItem);
    }
    return outputs;
}
function readOutputMod(count: number) {
    const outputs = [];
    for (let i = 0; i < count; i++) {
        const intputItem = {
            mod: bitReader.int32le(),
            param: bitReader.int16le(),
            min: bitReader.int16le(),
            max: bitReader.int16le(),
            chance: bitReader.int16le(),
        }
        if (intputItem.mod === 0) {
            continue;
        }
        outputs.push(intputItem);
    }
    return outputs;
}
function readRecord() {

    return {
        enabled: bitReader.byte(),
        ladder: bitReader.byte(),
        minDiff: bitReader.byte(),
        classId: bitReader.byte(),
        op: bitReader.int32le(),
        param: bitReader.int32le(),
        valueId: bitReader.int32le(),
        inputCount: bitReader.int16le(),
        version: bitReader.int16le(),

        inputs: readInputs(INPUT_COUNT),
        outputs: readOutputs(OUTPUT_COUNT)

    }
}



// const record = readRecord();

// ItemC

// for (let i = 0; i < recordCount; i++) {
//     console.log(readRecord());
// }
// console.log(readRecord());
// console.log(readRecord());
// console.log(readRecord());
