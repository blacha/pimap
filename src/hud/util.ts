import * as ta from 'time-ago';


export const capFirstLetter = str => str.charAt(0).toUpperCase() + str.substr(1);
export function nFormatter(num: number, digits: number) {
    var si = [
        { value: 1, symbol: '' },
        { value: 1E3, symbol: 'k' },
        { value: 1E6, symbol: 'M' },
        { value: 1E9, symbol: 'G' },
        { value: 1E12, symbol: 'T' },
        { value: 1E15, symbol: 'P' },
        { value: 1E18, symbol: 'E' }
    ];
    var rx = /\.0+$|(\.[0-9]*[1-9])0+$/;
    var i;
    for (i = si.length - 1; i > 0; i--) {
        if (num >= si[i].value) {
            break;
        }
    }
    return (num / si[i].value).toFixed(digits).replace(rx, '$1') + si[i].symbol;
}

export function timeAgo(d: number) {
    const diff = Math.abs(Date.now() - d);
    if (diff < 61 * 1000) {
        return '< 1 minute';
    }
    return ta.ago(new Date(d));

}
