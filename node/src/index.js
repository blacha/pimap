const cp = require('child_process');
const express = require('express');
const fs = require('fs');
const log = require('pino')();
const path = require('path');
const cors = require('cors')

const D2MapGen = '../pimap.exe';
const D2Path = '../../game/Path of Diablo';
const MapPath = 'maps'

function toHex(num, padding = 0) {
    let hex = num.toString(16)
    while (hex.length < padding) {
        hex = '0' + hex;
    }
    return '0x' + hex;
}

const getFolderName = (diff, seed) => `${MapPath}/${toHex(seed, 8)}_${diff}`
const getMapName = (diff, seed, mapId) => `${getFolderName(diff, seed)}/${toHex(mapId, 2)}.json`

const server = express()

server.use(cors())

const MAP_GENERATED = {};

function rimraf(dir_path) {
    if (fs.existsSync(dir_path)) {
        fs.readdirSync(dir_path).forEach(function (entry) {
            var entry_path = path.join(dir_path, entry);
            if (fs.lstatSync(entry_path).isDirectory()) {
                rimraf(entry_path);
            } else {
                fs.unlinkSync(entry_path);
            }
        });
        fs.rmdirSync(dir_path);
    }
}

function generateMaps(diff, seed) {

    const mapLogs = getFolderName(diff, seed) + '/log.json';
    const cwd = process.cwd();
    const command = 'wine ' + ['../pimap.exe', D2Path, seed, diff].map(c => `"${c}"`).join(' ');
    console.log(command, 'in', cwd);
    const child = cp.spawn('wine', [D2MapGen, D2Path, seed, diff], {
        cwd
    })
    console.log('Spawned');

    function killChild() {
        child.stdin.pause();
        child.stderr.pause();
        child.kill();
    }

    const logs = [];
    return new Promise((resolve, reject) => {
        child.stdout.on('data', (data) => {
            logs.push(data)

            // console.log('stdout:' + data);
            if (data.indexOf('$$DONE') > -1) {
                console.log('DONE');
                killChild();
                resolve();
            }

        });
        child.stderr.on('data', data => {
            if (data.indexOf('RtlpWaitForCriticalSection')) {
                killChild();
                resolve();
                return;
            }
            log.error({
                cmd: command
            }, data);
            killChild();
            reject('Error running command "' + data + '"')
        });
    }).then(_ => {
        fs.writeFileSync(mapLogs, logs.join(''));
    })
}

const ACT_LEVELS = [1, 40, 75, 103, 109, 137];

server.get('/act/:arg', async function (req, res, next) {
    const [diff, seed, act] = req.params.arg.split('_').map(c => parseInt(c));

    if (diff < 0 || diff > 3) {
        res.status(500);
        res.send({
            "error": "Invalid difficuilty"
        });
        return next();
    }


    const actMin = ACT_LEVELS[act];
    const actMax = ACT_LEVELS[act + 1];
    const output = {
        maps: {},
        act,
        seed,
        diff
    };

    const folderName = getFolderName(diff, seed)
    log.info({
        folderName,
        exists: fs.existsSync(folderName)
    }, 'Check Folder');
    if (!fs.existsSync(folderName)) {
        log.info({
            diff,
            seed,
            act
        }, 'Generating data maps');

        try {
            await generateMaps(diff, seed, act);
        } catch (e) {
            res.status(500);
            res.send({
                "error": "Error making maps",
                e
            });
            return next();
        }
    }
    for (let i = actMin; i < actMax; i++) {
        const mapName = getMapName(diff, seed, i);
        if (!fs.existsSync(mapName)) {
            log.error({
                mapName
            }, 'Missing Map')
            continue;
        }

        output.maps[i] = JSON.parse(fs.readFileSync(mapName).toString());
    }
    log.info({
        diff,
        seed,
        act,
        maps: output.maps.length
    }, 'Sending maps');

    res.header('Content-Type', 'application/json');
    res.send(output);
    next();

})


console.log(getMapName(0, 1689628444, 3))
server.listen(5000, () => log.info('Starting'));
