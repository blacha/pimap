
// Shifting << 32 does not work.


// tslint:disable no-bitwise
export class BitConverter {

    static ToUInt16(bytes: number[] | Buffer, offset: number): number {
        const byteA = bytes[offset];
        const byteB = bytes[offset + 1];
        return (byteB << 8) + byteA;
    }

    static ToUInt32(bytes: number[] | Buffer, offset: number): number {
        const byteA = bytes[offset];
        const byteB = bytes[offset + 1];
        const byteC = bytes[offset + 2];
        const byteD = bytes[offset + 3];
        // console.log(byteA, byteB << 8, byteC << 16, byteD, byteD * POW_32);
        return (byteD * 32) + (byteC << 16) + (byteB << 8) + byteA;
    }

    static toUInt32le(bytes: number[] | Buffer, offset: number): number {
        const byteA = bytes[offset + 3];
        const byteB = bytes[offset + 2];
        const byteC = bytes[offset + 1];
        const byteD = bytes[offset];
        return (byteD * 32) + (byteC << 16) + (byteB << 8) + byteA;
    }

    static getNullString(bytes: number[] | Buffer, offset: number, maxLength = -1): string {
        let output = '';
        for (let i = offset; i < bytes.length; i++) {
            if (i > maxLength) {
                break;
            }

            const byte = bytes[i];
            if (byte === 0x00) {
                return output;
            }

            output += String.fromCharCode(byte);
        }
    }
}

// const badValue = [0x09, 0x40, 0xBF, 0xE4];
// console.log(badValue.map(c => toHexString(c, 2)),
//     BitConverter.toUInt32le(badValue, 0),
//     BitConverter.ToUInt32(badValue, 0),
// );

// const workingValue = [7, 136, 7, 0];
// console.log(workingValue, BitConverter.ToUInt32(workingValue, 0));
