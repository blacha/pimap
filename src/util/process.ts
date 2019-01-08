import { spawn } from "child_process";

const cwd = process.cwd();

export function runCommand(command: string, args: any[]): Promise<string> {

    return new Promise((resolve, reject) => {
        const process = spawn(command, args, { cwd });
        let stdout = '';
        let stderr = '';

        process.stdout.on('data', data => stdout += data);
        process.stderr.on('data', data => stderr += data);

        process.on('error', reject);
        process.on('close', exitCode => {
            if (exitCode > 0) {
                return reject(stderr || stdout)
            }
            return resolve(stdout)
        });
    });
};
