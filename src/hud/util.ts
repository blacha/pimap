import * as ta from 'time-ago';
import parseMs from 'parse-ms';

export const capFirstLetter = (str) => str.charAt(0).toUpperCase() + str.substr(1);
export function nFormatter(num: number, digits: number) {
  const si = [
    { value: 1, symbol: '' },
    { value: 1e3, symbol: 'k' },
    { value: 1e6, symbol: 'M' },
    { value: 1e9, symbol: 'G' },
    { value: 1e12, symbol: 'T' },
    { value: 1e15, symbol: 'P' },
    { value: 1e18, symbol: 'E' },
  ];
  const rx = /\.0+$|(\.[0-9]*[1-9])0+$/;
  let i;
  for (i = si.length - 1; i > 0; i--) {
    if (num >= si[i].value) {
      break;
    }
  }
  return (num / si[i].value).toFixed(digits).replace(rx, '$1') + si[i].symbol;
}

export function prettyTimeSince(otherDate: Date): string {
  const timeDiff = parseMs(Date.now() - otherDate.getTime());

  const output = [];
  if (timeDiff.days > 0) output.push(`${timeDiff.days}d`);
  if (timeDiff.hours > 0) output.push(`${timeDiff.hours}h`);
  if (timeDiff.minutes > 0) output.push(`${timeDiff.minutes}m`);
  if (timeDiff.seconds > 0) output.push(`${timeDiff.seconds}s`);

  return output.join(' ');
}

export function timeAgo(d: number): string {
  const diff = Math.abs(Date.now() - d);
  if (diff < 61 * 1000) {
    return '< 1 minute';
  }
  return ta.ago(new Date(d));
}
