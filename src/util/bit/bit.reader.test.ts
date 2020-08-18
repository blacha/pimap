import { BitReader } from './bit.reader';

function checkRead(ary: number[], bitCount: number) {
  let expected = 0;
  ary.forEach((c, i) => (expected += c * Math.pow(256, i)));
  const br2 = new BitReader(ary);
  const res2 = br2.bits(bitCount);
  console.log(res2, expected);
}
checkRead([255], 8);
checkRead([255, 255], 16);
checkRead([255, 255, 255], 24);
checkRead([255, 255, 255, 255], 32);
checkRead([255, 255, 255, 255, 255], 40);

checkRead([1, 1, 1, 1], 32);
checkRead([1, 1, 1, 255], 32);
checkRead([1, 1, 1, 255], 32);
