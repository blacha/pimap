import { Log } from 'bblog';
import { ConsoleLogStream } from 'bblog-stream-console';
import { hostname } from 'os';

export const Logger = Log.createLogger({
    name: 'PiMap',
    hostname: hostname(),
    stream: new ConsoleLogStream(Log.TRACE),
    keys: {
        // $i: Id.generate()
    }
});

