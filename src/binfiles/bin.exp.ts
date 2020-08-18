// import { BitReader } from "../util/bit/bit.reader";
// import { Logger } from "../util/log";
// import { BinFileReader, BinFileType } from "./bin.reader";
// import { BitConverter } from "../util/bit/bit.converter";
// import { EXP_REQ } from "../core/xp";

// const INPUT_COUNT = 7;
// const OUTPUT_COUNT = 3;
// const MOD_COUNT = 5;

// export class BinExp implements BinFileReader {
//     // requrires: BinFileType[] = [];
//     fileName = BinFileType.Experience;
//     priority = 10;

//     records: number[] = [];
//     read(bits: BitReader) {

//         const recordCount = bits.int32le();
//         Logger.info({ recordCount, bin: this.fileName }, 'Reading')
//         for (let i = 0; i < recordCount; i++) {

//             const expObj = {
//                 level: i - 1,
//                 Amazon: bits.bytes(4),
//                 Sorceress: bits.int32le(),
//                 Necromancer: bits.int32le(),
//                 Paladin: bits.int32le(),
//                 Barbarian: bits.int32le(),
//                 Druid: bits.int32le(),
//                 Assassin: bits.int32le(),
//                 ratio: bits.int32le()
//             }
//             if (expObj.level < 0) {
//                 continue;
//             }

//             const xp = BitConverter.ToUInt32(expObj.Amazon, 0);

//             const xpLe = BitConverter.toUInt32le(expObj.Amazon, 0);

//             const expected = EXP_REQ[expObj.level];

//             console.log(expObj.level, xp, expected, expObj.Amazon);
//         }

//     }

// }
