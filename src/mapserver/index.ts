import 'source-map-support/register';

import * as cors from 'cors';
import * as express from 'express';
import * as fs from 'fs';
import * as ulid from 'ulid';
import { Logger } from '../util/log';
import { MapDifficultyRoute } from './act';
import { D2_PATH, PI_MAP_COMMAND } from './config';
import { HealthRoute } from './health';
import { MapRoute } from './map';
import { MapImageRoute } from './map.image';
import { MapProcess } from './map.process';
import { PiMapRequest, PiMapResponse, PiMapRoute, PiMapRouteError } from './route';

if (!fs.existsSync(PI_MAP_COMMAND)) {
  Logger.fatal(`Cannot find ${PI_MAP_COMMAND}`);
  process.exit(1);
}

if (!fs.existsSync(D2_PATH)) {
  Logger.fatal(`Cannot find ${D2_PATH}`);
  process.exit(1);
}

class D2MapServer {
  server = express();
  port = parseInt(process.env.PORT, 10) || 8899;

  constructor() {
    this.server.use(cors());
  }

  bind(route: PiMapRoute) {
    Logger.info({ url: route.url }, 'Bind');
    this.server.get(route.url, async (req: PiMapRequest, res: PiMapResponse, next: express.NextFunction) => {
      req.id = ulid.ulid();
      req.log = Logger.child({ id: req.id });
      const startTime = Date.now();
      try {
        const output = await route.process(req, res);
        if (output != null) {
          res.status(200);
          res.json(output);
        }
      } catch (e) {
        if (e instanceof PiMapRouteError) {
          req.log.warn(e.message);
          res.status(e.status || 500);
          res.json({ id: req.id, message: e.message });
        } else {
          req.log.error({ error: e }, 'Failed to run');
          res.status(500);
          res.json({ id: req.id, message: `Internal server error` });
        }
      }
      const duration = Date.now() - startTime;
      req.log.info({ duration, status: res.statusCode }, req.url);
      next();
    });
  }

  async init() {
    await MapProcess.init(Logger);
    await new Promise((resolve) => {
      this.server.listen(this.port, () => {
        Logger.info({ port: this.port }, 'Server started...');
        resolve();
      });
    });
  }
}

export const MapServer = new D2MapServer();

MapServer.bind(new HealthRoute());
MapServer.bind(new MapDifficultyRoute());
MapServer.bind(new MapRoute());
MapServer.bind(new MapImageRoute());
MapServer.init().catch((e) => Logger.fatal({ error: e }, 'Uncaucght Exception'));
