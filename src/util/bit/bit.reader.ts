import { toHexString } from "../to.hex";

export class BitReader {
    buffer: number[] | Buffer;
    /** Offset in bits */
    offset: number;
    constructor(bytes: number[] | Buffer, offset: number = 0) {
        this.offset = offset;
        this.buffer = bytes;
    }

    getBitValue(byte: number, offset: number, length: number): number {
        return ((byte & (((1 << (offset + length)) - 1) & ~((1 << offset) - 1))) >> offset);
    }

    readBit() {
        return this.readBits(1);
    }

    readBits(length: number) {
        let bytePos = Math.floor(this.offset / 8);
        let bitPos = this.offset % 8;
        this.offset = this.offset + length;

        let b = this.buffer[bytePos];
        let result = 0;
        let byteBits;
        let totBits = 0;

        while (length > 0) {
            if (bitPos === 8) {
                b = this.buffer[++bytePos];
                bitPos = 0;
            }
            byteBits = Math.min(length, 8 - bitPos);
            result |= this.getBitValue(b, bitPos, byteBits) << totBits;
            bitPos += byteBits;
            totBits += byteBits;
            length -= byteBits;
        }
        return result;
    }

    readBitsLittleEndian(length: number) {
        const initialLen = length;
        let bits = 0;
        while (length > 0) {
            const bit = this.readBit();
            bits |= ((bit ? 1 : 0) << initialLen - length);

            length -= 1;
        }
        return bits;
    }

    byte(): number { return this.readBits(8) }
    int16le(): number { return this.readBitsLittleEndian(16) }
    int32le(): number { return this.readBitsLittleEndian(32) }

    bytes(count: number): number[] {
        const bytes: number[] = [];
        for (let i = 0; i < count; i++) {
            const byte = this.readBits(8);
            if (byte === 0x00) {
                continue;
            }
            bytes.push(byte);
        }
        return bytes;
    }

    string(count: number): string {
        let buf = '';
        for (let i = 0; i < count; i++) {
            const byte = this.readBits(8);
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
        while ((byte = this.readBits(8)) != 0x00) {
            buf += String.fromCharCode(byte);
        }
        return buf;
    }

    offsetHex(size = 5) {
        return toHexString(this.offset / 8, size);
    }

}
