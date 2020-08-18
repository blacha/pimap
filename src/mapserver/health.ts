import { PiMapRoute, PiMapRequest } from './route';

export class HealthRoute implements PiMapRoute {
  url = '/healthz';
  async process(req: PiMapRequest) {
    return { message: 'ok' };
  }
}
