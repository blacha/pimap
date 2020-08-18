import { SniffingWebServer } from './sniff/server';
import { SessionState } from './sniff/state/session';
import { D2PacketSniffer } from './sniff/sniffer';
import * as dotenv from 'dotenv';
import { Logger } from './util/log';

dotenv.config();

const snifferNetworkAdapter = process.env['SNIFF_NETWORK_ADAPTER'];

if (snifferNetworkAdapter == null) {
  Logger.fatal('Invalid SNIFF_NETWORK_ADAPTER');
  process.exit(1);
}

const server = new SniffingWebServer();
server.start();

SessionState.onDirty(() => server.updateState());

const sniff = new D2PacketSniffer(snifferNetworkAdapter);
sniff.listen();
