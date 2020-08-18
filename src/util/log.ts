import { Log, LogMessage, LogLevel } from 'bblog';
import { PrettySimple } from 'pretty-json-log/build/pretty/simple';

const ps = new PrettySimple(Log.TRACE);
const PrettyStream = {
  level: Log.TRACE,
  setLevel(level: LogLevel) {
    PrettyStream.level = level;
  },
  write(msg: LogMessage) {
    if (msg.level < PrettyStream.level) return;
    if (process.stdout.isTTY) return process.stdout.write(ps.pretty(msg) + '\n');
    process.stdout.write(JSON.stringify(msg) + '\n');
  },
};

export const Logger = Log.createLogger({
  name: 'PiMap',
  hostname: '',
  streams: [PrettyStream],
  keys: {},
});
