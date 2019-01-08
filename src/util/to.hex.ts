export function toHexString(num: number, padding = 2): string {
    let hex = num.toString(16)
    while (hex.length < padding) {
        hex = '0' + hex;
    }
    return '0x' + hex;
}
