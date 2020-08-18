// Shifting << 32 does not work.

// tslint:disable no-bitwise
export class BitConverter {
  static ToUInt16(bytes: number[] | Buffer, offset: number): number {
    const byteA = bytes[offset];
    const byteB = bytes[offset + 1];
    return (byteB << 8) + byteA;
  }
}
