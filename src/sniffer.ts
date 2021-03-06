import { Diablo2PacketSniffer, findLocalIps, PacketLine } from '@diablo2/sniffer';
import * as dotenv from 'dotenv';
import { createReadStream, existsSync, promises as fs } from 'fs';
import * as readline from 'readline';
import { SniffingWebServer } from './sniff/server';
import { Logger } from './util/log';

dotenv.config();

const ReplayPackets = false;
async function replayPackets(sniffer: Diablo2PacketSniffer): Promise<void> {
  // Track items being dropped onto the ground
  const reader = readline.createInterface({
    input: createReadStream(
      '/home/blacha/git/blacha/diablo2/packages/sniffer/replay-01f035vb191hz2ejvp89psm6yk.ndjson',
    ),
    crlfDelay: Infinity,
  });

  const session = sniffer.client.startSession(Logger);
  sniffer.events.emit('session', session);

  let lastTime = null;
  for await (const line of reader) {
    const json = JSON.parse(line) as PacketLine;
    // if (json.direction ===  'out') continue;

    if (lastTime == -1) lastTime = json.time;
    const timeDiff = Math.abs(lastTime - json.time);

    session.onPacket(json.direction, Buffer.from(json.bytes, 'hex'), Logger);

    if (timeDiff > 100) {
      lastTime = json.time;
      // console.log('sleep', timeDiff);
      await new Promise((resolve) => setTimeout(resolve, timeDiff / 20));
    }
  }
}

function usage(err?: string): void {
  if (err) console.log(`Error ${err} \n`);
  console.log('Usage: sniffer :network [--dump]\n');
  console.log('Network adapters:');
  console.log(
    findLocalIps()
      .map((iface) => `\t${iface.interface} (${iface.address})`)
      .join('\n'),
  );
}

async function main(): Promise<void> {
  if (process.argv.length < 3) return usage();

  const args = process.argv.slice(2);
  const isWriteDump = args.indexOf('--dump');
  if (isWriteDump > -1) args.splice(isWriteDump, 1);

  const localNetworks = findLocalIps();
  const networkAdapterIndex = args.findIndex((arg) => localNetworks.find((iface) => iface.interface === arg));

  if (networkAdapterIndex == null) {
    return usage('Cannot find network adapter');
  }
  const [networkAdapter] = args.splice(networkAdapterIndex, 1);
  Logger.debug({ networkAdapter }, 'StartingSniffer');

  const gamePath = process.env['DIABLO2_PATH'];
  if (gamePath == null || !existsSync(gamePath)) {
    Logger.error({ gamePath }, 'Path does not exist');
    return usage('Cannot find game path, set $DIABLO2_PATH');
  }

  const sniffer = new Diablo2PacketSniffer(networkAdapter, gamePath);
  await sniffer.init(Logger);

  sniffer.onNewGame((game) => {
    Logger.info('NewGame:Listener');
    game.state.onClose(async (state) => {
      const duration = state.duration;
      Logger.info({ duration, isLong: duration > 5 * 60_000, isXp: state.player.xp.diff > 10_000 }, 'GameClosed');
      if (duration > 5 * 60_000 || state.player.xp.diff > 10_000) {
        Logger.info({ gameId: state.gameId }, 'WritingGameFile');

        state.units.clear();
        await fs.writeFile(`./games/${state.gameId}.json`, JSON.stringify(state.toJSON()));
      }
    });
  });

  sniffer.isWriteDump = isWriteDump > 0;

  const srv = new SniffingWebServer(sniffer);
  srv.start();

  if (ReplayPackets) await replayPackets(sniffer);
  await sniffer.start(Logger);
}

main().catch((e) => Logger.fatal(e, 'FailedToRun'));
