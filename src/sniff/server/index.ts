import * as express from 'express';
import * as jsondiffpatch from 'jsondiffpatch';
import serveStatic = require('serve-static');
import { Server } from 'ws';
import { SessionState } from '../state/session';
import { Logger } from '../../util/log';
import { ulid } from 'ulid';
import { MessageType } from '../../core/game.json';
import { PiMapRequest } from '../../mapserver/route';

export class SniffingWebServer {
    app = express();
    wss;
    lastSend = Date.now();
    sendTrigger = null;

    start() {
        Logger.info('Starting server');

        this.wss = new Server({ port: 40510 });
        this.app.use((req: PiMapRequest, res, next) => {
            const id = req.id = ulid();
            req.log = Logger.child({ id })
            next();
        });

        this.app.get('/', serveStatic('dist/'));
        this.app.get('/assets/', serveStatic('assets/'));

        this.app.use((req: PiMapRequest, res, next) => {
            req.log.info({ url: req.url, status: res.statusCode }, 'Request');
        })
        this.app.listen(1337, () => Logger.info('Server started'));

        this.wss.on('connection', client => {
            client.id = ulid()
            Logger.info({ client: client.id }, 'Client Connected');
            client.lastState = JSON.parse(JSON.stringify(SessionState.currentGame));
            client.lastSend = new Date();
            client.on('close', () => Logger.info({ client: client.id }, 'Client Close'));
            client.on('error', error => Logger.info({ error, client: client.id }, 'Client Error'));
            client.send(JSON.stringify({ type: MessageType.STATE, data: client.lastState }));
        });
    }

    stop() {
        this.wss.close();
    }

    updateState() {
        let currentState = JSON.parse(JSON.stringify(SessionState.currentGame));
        if (Date.now() - this.lastSend < 5) {
            if (this.sendTrigger == null) {
                this.sendTrigger = setTimeout(_ => this.updateState(), 5);
            }

            return;
        }

        if (this.sendTrigger) {
            clearTimeout(this.sendTrigger);
            this.sendTrigger = null;
        }

        this.lastSend = Date.now();
        for (const client of this.wss.clients) {
            const patch = jsondiffpatch.diff(client.lastState, currentState);
            client.lastState = currentState;
            client.lastSend = new Date();
            if (patch != null) {
                client.send(JSON.stringify({ type: MessageType.STATE, data: client.lastState, patch }));
            }
        }
    }
}
