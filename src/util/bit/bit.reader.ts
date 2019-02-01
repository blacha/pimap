import { toHexString } from "../to.hex";

const p2: number[] = []
for (let i: number = 0; i < 64; i++) { p2[i] = Math.pow(2, i) }

export class BitReader {
    buffer: number[] | Buffer;
    /** Offset in bits */
    offset: number;
    constructor(bytes: number[] | Buffer, offset: number = 0) {
        this.offset = offset;
        this.buffer = bytes;
    }
    /** Convert the buffer into a hex string */
    toHexString(): string {
        const output: string[] = [];
        for (const byte of this.buffer) {
            output.push(toHexString(byte, 2));
        }
        return output.join(', ');
    }
    /** Convert the buffer into a hex string */
    toCharString(): string {
        const output: string[] = [];
        for (const byte of this.buffer) {
            output.push(String.fromCharCode(byte));
        }
        return output.join(', ');
    }


    get remainingBits() {
        return this.buffer.length * 8 - this.offset;
    }

    getBitValue(byte: number, offset: number, length: number): number {
        return ((byte & (((1 << (offset + length)) - 1) & ~((1 << offset) - 1))) >> offset);
    }

    bool(): boolean {
        return this.bit() === 1;
    }

    bit() {
        const bytePos = Math.floor(this.offset / 8);
        const bitPos = this.offset % 8;
        const byte = this.buffer[bytePos];
        if (this.remainingBits < 0) {
            console.trace('Overflow: ' + this.remainingBits);
            // throw new Error('Overflow ' + this.remainingBits);
        }

        this.offset++;
        return this.getBitValue(byte, bitPos, 1);
    }

    byte() {
        const bytePos = Math.floor(this.offset / 8);
        const bitPos = this.offset % 8;
        if (bitPos === 0) {
            this.offset += 8;
            return this.buffer[bytePos];
        }
        return this.bits(8)
    }

    /** Read bits little endian */
    bits(length: number) {
        const initialLen = length;
        let bits = 0;
        while (length > 0) {
            bits += ((this.bit() ? 1 : 0) * p2[initialLen - length]);
            length -= 1;
        }
        return bits;
    }

    skip(count: number = 1) {
        this.offset += count;
    }
    skipByte(count: number = 1) {
        this.skip(8 * count);
    }

    // byte(): number { return this.readBits(8) }
    // int16le(): number { return this.bits(16) }
    // int32le(): number { return this.bits(32) }
    uint32(): number { return this.bits(32); }
    uint16(): number { return this.bits(16); }
    // int32(): number { return this.readBits(32) }
    // int16(): number { return this.readBits(16) }

    bytes(count: number): number[] {
        const bytes: number[] = [];
        for (let i = 0; i < count; i++) {
            const byte = this.byte();
            bytes.push(byte);
        }
        return bytes;
    }

    string(count: number): string {
        let buf = '';
        for (let i = 0; i < count; i++) {
            const byte = this.byte();
            if (byte === 0x00) {
                continue;
            }
            buf += String.fromCharCode(byte);
        }
        return buf;
    }

    /** Read a null terminated string */
    stringNull(): string {
        let buf = '';
        let byte: number;
        while ((byte = this.byte()) != 0x00) {
            buf += String.fromCharCode(byte);
        }
        return buf;
    }

    offsetHex(size = 5) {
        return toHexString(this.offset / 8, size);
    }

}


