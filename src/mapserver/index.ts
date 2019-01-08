import * as fs from 'fs';
const PiMapCommand = './bin/pimap.exe';


if (!fs.existsSync(PiMapCommand)) {
    console.error(`Missing ${PiMapCommand}`);
    process.exit(1);
}
export const MapServer = {};
