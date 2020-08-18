import { BitConverter } from '../util/bit/bit.converter';

export class GSPacketSize {
  static PacketSizes = [
    /*	0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F	*/
    /* 0 */ 1,
    9,
    1,
    12,
    1,
    1,
    1,
    6,
    6,
    11,
    6,
    6,
    9,
    13,
    12,
    16,
    /* 1 */ 16,
    8,
    26,
    14,
    18,
    11,
    -1,
    -1,
    15,
    2,
    2,
    3,
    5,
    3,
    4,
    6,
    /* 2 */ 10,
    12,
    12,
    13,
    90,
    90,
    -1,
    40,
    103,
    97,
    15,
    0,
    8,
    0,
    0,
    0,
    /* 3 */ 0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    34,
    8,
    /* 4 */ 13,
    0,
    6,
    0,
    0,
    13,
    0,
    11,
    11,
    0,
    0,
    0,
    16,
    17,
    7,
    1,
    /* 5 */ 15,
    14,
    42,
    10,
    3,
    0,
    0,
    14,
    7,
    26,
    40,
    -1,
    5,
    6,
    38,
    5,
    /* 6 */ 7,
    2,
    7,
    21,
    0,
    7,
    7,
    16,
    21,
    12,
    12,
    16,
    16,
    10,
    1,
    1,
    /* 7 */ 1,
    1,
    1,
    32,
    10,
    13,
    6,
    2,
    21,
    6,
    13,
    8,
    6,
    18,
    5,
    10,
    /* 8 */ 4,
    20,
    29,
    0,
    0,
    0,
    0,
    0,
    0,
    2,
    6,
    6,
    11,
    7,
    10,
    33,
    /* 9 */ 13,
    26,
    6,
    8,
    -1,
    13,
    9,
    1,
    7,
    16,
    17,
    7,
    -1,
    -1,
    7,
    8,
    /* A */ 10,
    7,
    8,
    24,
    3,
    8,
    -1,
    7,
    -1,
    7,
    -1,
    7,
    -1,
    0,
    -1,
    0,
    /* B */ 1,

    // 1, 9/*8*/, 1, 12, 1, 1, 1, 6, 6, 11, 6, 6, 9, 13, 12, 16,
    // 16, 8, 26, 14, 18, 11, 0, 0, 15, 2, 2, 3, 5, 3, 4, 6,
    // 10, 12, 12, 13, 90, 90, 0, 40, 103, 97, 15, 0, 8, 0, 0, 0,
    // 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 8,
    // 13, 0, 6, 0, 0, 13, 0, 11, 11, 0, 0, 0, 16, 17, 7, 1,
    // 15, 14, 42, 10, 3, 0, 0, 14, 7, 26, 40, 0, 5, 6, 38, 5,
    // 7, 2, 7, 21, 0, 7, 7, 16, 21, 12, 12, 16, 16, 10, 1, 1,
    // 1, 1, 1, 32, 10, 13, 6, 2, 21, 6, 13, 8, 6, 18, 5, 10,
    // 4, 20, 29, 0, 0, 0, 0, 0, 0, 2, 6, 6, 11, 7, 10, 33,
    // 13, 26, 6, 8, 0, 13, 9, 1, 7, 16, 17, 7, 0, 0, 7, 8,
    // 10, 7, 8, 24, 3, 8, 0, 7, 0, 7, 0, 7, 0, 0, 0, 0,
    // 1
  ];

  static getChatPacketSize(packet: number[]): number {
    if (packet.length < 12) {
      return null;
    }

    const initial_offset = 10;

    let name_offset = packet.indexOf(0, initial_offset);

    if (name_offset === -1) {
      return null;
    }

    name_offset -= initial_offset;

    let message_offset = packet.indexOf(0, initial_offset + name_offset + 1);

    if (message_offset === -1) {
      return null;
    }

    message_offset = message_offset - initial_offset - name_offset - 1;

    return initial_offset + name_offset + 1 + message_offset + 1;
  }

  static getPacketSize(data: number[]): number | null {
    const length = data.length;
    const packetId = data[0];

    let pLen = GSPacketSize.PacketSizes[packetId];
    if (pLen !== -1) return pLen;

    switch (packetId) {
      case 0x26:
        return GSPacketSize.getChatPacketSize(data);
      case 0x5b:
        if (length < 3) break;
        return BitConverter.ToUInt16(data, 1);
      case 0x94:
        if (length < 2) break;
        return 6 + data[1] * 3;
      case 0x9c:
      case 0x9d:
        if (length < 3) break;
        return data[2];
      case 0xa8:
      case 0xaa:
        if (length < 7) break;
        return data[6];
      case 0xac:
        if (length < 13) break;
        return data[12];
      case 0xae:
        if (length < 4) break;
        return 3 + BitConverter.ToUInt16(data, 1);
      default:
        pLen = 0;
        break;
    }

    return pLen;
  }
}
