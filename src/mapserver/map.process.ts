import { Log } from 'bblog';
import { ChildProcess, spawn } from 'child_process';
import { resolve } from 'path';
import { GameDifficulty } from '../core/difficulty';
import { Logger } from '../util/log';
import { D2_PATH, PI_MAP_COMMAND } from './config';
import { runCommand } from '../util/process';
import { D2Map } from '../core/map';

/** Wait atmost 10 seconds for things to work */
const TIMEOUT = 10000;
const MAX_PROCESS_GENERATE = 1000;

const cwd = process.cwd();
interface D2MapResponse {
  seed: number;
  difficulty: number;
}

function getJson(s: string) {
  try {
    return JSON.parse(s);
  } catch (e) {
    return null;
  }
}

const WINE_COMMAND = 'wine';
export class D2MapProcess {
  COMMANDS = {
    SEED: '$SEED',
    MAP: '$MAP',
    DIFFICULTY: '$DIFF',
    EXIT: '$EXIT',
  };

  generatedCount = 0;
  process: ChildProcess;
  buffer = '';
  difficulty: number;
  seed: number;

  lines: string[] = [];
  onLine: (line: any) => void;

  version: string;
  async init(log: Log) {
    const versionResponse = await runCommand(WINE_COMMAND, ['--version']);
    this.version = versionResponse.trim();
    log.info({ version: this.version, command: WINE_COMMAND }, 'WineVersion');
  }

  async startProcess(log: Log) {
    if (this.process != null) {
      return;
    }

    const args = [PI_MAP_COMMAND, D2_PATH];
    log.info({ wineArgs: args }, 'Starting MapProcess');

    this.process = spawn(WINE_COMMAND, args, { cwd });
    this.process.stdout.on('data', this.onData.bind(this));
    this.process.on('error', (err) => this.onError(err));
    this.process.on('close', (code) => this.onClose(code));

    log.info('Waiting for process to start');
    await this.waitForJson((line) => line.message === 'InitDone', log);
    log.info('Process started');
  }

  /** Wait for the next json line */
  async waitForJson(cb: (line: any) => boolean, log: Log, timeout = TIMEOUT): Promise<void> {
    return new Promise((resolve, reject) => {
      // If it takes too long die!
      const rejectTimer = setTimeout(async () => {
        this.onLine = null;
        log.fatal({ timeout }, 'Failed to get line');
        await this.killProcess(log);
        reject();
      }, timeout);

      this.registerOnLine((line) => {
        const data = getJson(line);
        if (data == null) {
          log.info({ line: line.trim() }, 'Process start');
          return;
        }
        if (cb(data)) {
          clearTimeout(rejectTimer);
          this.onLine = null;
          resolve(data);
        }
      });
    });
  }

  registerOnLine(cb: (line: any) => any): void {
    if (this.onLine != null) {
      console.log('line', this.onLine);
      Logger.error('Overwriting onLine');
    }

    if (this.lines.length > 0) {
      this.lines.forEach((l) => cb(l));
      this.lines = [];
    }
    this.onLine = cb;
  }

  async raw(command: string, log: Log) {
    if (this.process == null) {
      await this.startProcess(log);
    }
    log.info({ command }, 'Command');
    this.process.stdin.write(`${command}\n`);
  }
  async setCommand(command: string, value: any, log: Log): Promise<D2MapResponse> {
    await this.startProcess(log);

    this.raw(`${command} ${value}`, log);

    await this.waitForJson(
      (line) => {
        if (line.seed != null && line.difficulty != null) {
          this.seed = line.seed;
          this.difficulty = line.difficulty;
          return true;
        }
        return false;
      },
      log,
      2500,
    );
    return { seed: this.seed, difficulty: this.difficulty };
  }

  async setDifficulty(difficulty: GameDifficulty, log: Log): Promise<D2MapResponse> {
    const response = await this.setCommand(this.COMMANDS.DIFFICULTY, GameDifficulty[difficulty], log);
    this.difficulty = response.difficulty;
    return response;
  }

  async setSeed(seed: number, log: Log): Promise<D2MapResponse> {
    const response = await this.setCommand(this.COMMANDS.SEED, seed, log);
    this.seed = response.seed;
    return response;
  }

  async getMaps(log: Log): Promise<{ [key: string]: D2Map }> {
    if (this.generatedCount > MAX_PROCESS_GENERATE) {
      this.generatedCount = 0;
      await this.killProcess(log);
      await this.startProcess(log);
    }
    this.generatedCount++;
    log.info({ seed: this.seed, difficulty: this.difficulty, generated: this.generatedCount }, 'Generating maps');
    const maps = {};

    this.raw(this.COMMANDS.MAP, log);
    return new Promise((resolve, reject) => {
      // If it takes too long die!
      const rejectTimer = setTimeout(async () => {
        log.fatal({ timeout: TIMEOUT }, 'Failed to get maps');
        await this.killProcess(log);
        reject();
      }, TIMEOUT);
      this.registerOnLine((line) => {
        if (line == '') {
          return;
        }
        const data = getJson(line);
        if (data == null) {
          log.info({ line: line.trim() }, 'Invalid line...');
          return;
        }

        if (data.message == 'DONE') {
          clearTimeout(rejectTimer);
          this.onLine = null;
          return resolve(maps);
        }

        if (data.id != null) {
          maps[data.id] = data;
        }
      });
    });
  }

  async killProcess(log: Log) {
    if (this.process == null) {
      return;
    }

    return new Promise((resolve, reject) => {
      const timeout = setTimeout(() => {
        log.error('Failed to kill process');
        reject();
      }, 2000);

      this.process.on('close', async () => {
        log.info('Process killed');
        clearTimeout(timeout);
        await new Promise((resolve) => setTimeout(resolve, 1000));
        resolve();
      });

      this.raw(this.COMMANDS.EXIT, log);
    });
  }

  onData(data: string) {
    let dataStr = data.toString();
    let newLine = dataStr.indexOf('\n');
    // console.log('onData', newLine, dataStr.length);

    while (newLine !== -1) {
      this.buffer += dataStr.substr(0, newLine);
      if (this.buffer.trim() !== '') {
        this.newLine();
      }
      this.buffer = '';
      dataStr = dataStr.substr(newLine + 1);
      newLine = dataStr.indexOf('\n');
    }
    if (dataStr.length > 0) {
      this.buffer += dataStr;
      return;
    }
  }

  newLine() {
    // console.log(`Line  "${this.buffer.trim()}"`);
    if (this.onLine) {
      this.onLine(this.buffer);
    } else {
      this.lines.push(this.buffer);
    }

    // If there are 10 unread lines throw them away!
    if (this.lines.length > 10) {
      Logger.warn({ lines: this.lines }, 'Invalid lines');
      this.lines = [];
    }
  }

  onError(error: Error) {
    Logger.fatal({ error }, 'ProcessDied');
    this.process = null;
  }

  onClose(exitCode: number) {
    this.process = null;
    if (exitCode > 0) {
      Logger.fatal({ exitCode }, 'ProcessClosed');
    }
  }
}

export const MapProcess = new D2MapProcess();
