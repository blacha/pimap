import * as express from 'express';
import { Log } from 'bblog';

export interface PiMapRequest extends express.Request {
  id: string;
  log: Log;
}

export type PiMapResponse = express.Response;

export class PiMapRouteError {
  status: number;
  message: string;

  constructor(status: number, message: string) {
    this.status = status;
    this.message = message;
  }
}

export interface PiMapRoute {
  url: string;
  process(req: PiMapRequest, res?: PiMapResponse): Promise<unknown>;
}
