
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
        return (byteD << 32) + (byteC << 16) + (byteB << 8) + byteA;
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
