export function toHexString(num: number, padding = 2, raw = false): string {
  const hex = num.toString(16);
  if (raw) return hex.padStart(padding, '0');
  return '0x' + hex.padStart(padding, '0');
}
