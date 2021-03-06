import express from 'express';
import * as jsondiffpatch from 'jsondiffpatch';
import serveStatic = require('serve-static');
import { Server } from 'ws';
import { SessionState } from '../state/session';
import { Logger } from '../../util/log';
import { ulid } from 'ulid';
import { MessageType } from '../../core/game.json';
import { PiMapRequest } from '../../mapserver/route';
import { Diablo2PacketSniffer } from '@diablo2/sniffer';
import { Diablo2GameSession } from '@diablo2/core';

/** Sniffing server that just dumps current state to any websocket that connects */
export class SniffingWebServer {
  app = express();
  wss;
  lastSend = Date.now();
  sendTrigger = null;
  sniffer: Diablo2PacketSniffer;
  currentGame?: Diablo2GameSession;

  constructor(sniffer: Diablo2PacketSniffer) {
    this.sniffer = sniffer;

    this.sniffer.onNewGame((game) => {
      console.log('NewGame---');
      this.currentGame = game;
      this.currentGame.state.onChange = () => this.updateState();
    });
  }

  start(): void {
    Logger.info('Starting server');

    this.wss = new Server({ port: 40510 });
    this.app.use((req: PiMapRequest, res, next) => {
      const id = (req.id = ulid());
      req.log = Logger.child({ id });
      next();
    });

    this.app.use('/', serveStatic('dist/'));
    this.app.use('/assets', serveStatic('dist/assets/'));
    this.app.use('/js', serveStatic('dist/js/'));

    // this.app.get('/assets/', serveStatic('assets/'));

    this.app.use((req: PiMapRequest, res, next) => {
      if (res.headersSent) {
        req.log.info({ url: req.url, status: res.statusCode }, 'Request');
        return;
      }
      res.status(404);
      res.end();
    });
    this.app.listen(1337, () => Logger.info({ url: 'http://localhost:1337/' }, 'Server started'));

    this.wss.on('connection', (client) => {
      client.id = ulid();
      Logger.info({ client: client.id }, 'Client Connected');
      client.lastState = JSON.parse(JSON.stringify(this.currentGame?.state ?? {}));
      client.lastSend = new Date();
      client.on('close', () => Logger.info({ client: client.id }, 'Client Close'));
      client.on('error', (error) => Logger.info({ error, client: client.id }, 'Client Error'));
      client.send(JSON.stringify({ type: MessageType.STATE, data: client.lastState }));
    });
  }

  stop(): void {
    this.wss.close();
  }

  updateState(): void {
    const currentState = JSON.parse(JSON.stringify(this.currentGame?.state ?? {}));
    if (Date.now() - this.lastSend < 5) {
      if (this.sendTrigger == null) {
        this.sendTrigger = setTimeout(() => this.updateState(), 5);
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
        client.send(JSON.stringify({ type: MessageType.STATE, data: client.lastState }));
      }
    }
  }
}
