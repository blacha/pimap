import { Log } from 'bblog';
import { GameServerPacket } from '../gs.packet';
import { GamePacket } from './game.server';
import { UnitType } from '../../core/unit';
import { BitReader } from '../../util/bit/bit.reader';
import { NpcSuperUnique } from '../../core/super.unique';
import { SessionState } from '../state/session';
import { NpcName } from '../../core/npc.name';
import { NPC_FIELDS } from '../npc.fields';

function BitScanReverse(mask) {
    let index = 0;
    while (mask > 1) {
        mask >>= 1;
        index++;
    }
    return { index, mask };
}

export class GSPacketNPCAssign extends GamePacket {
    superUniqueName: string;
    flags: {
        champion: boolean,
        minion: boolean,
        unique: boolean;
        superUnique: boolean;
        ghostly: boolean;
    };

    life: number;
    y: number;
    x: number;
    type: UnitType;
    code: number;
    uid: number;

    valid: boolean;

    static id = GameServerPacket.NPCAssign;


    constructor(br: BitReader) {
        super(br);

        this.uid = br.uint32();
        this.code = br.uint16();
        this.x = br.uint16();
        this.y = br.uint16();
        this.life = br.byte();

        br.byte(); // size

        if (br.buffer.length < 0x10) {
            this.valid = false;
            return;
        }
        br.bits(4); // Animation

        const entries = NPC_FIELDS[this.code];
        if (entries == null) {
            this.valid = false;
            return;
        }
        if (br.bit()) {
            const informationLength = 16;
            if (entries.length !== 16) {
                this.valid = false;
                return;
            }
            for (const entry of entries) {
                let temp = BitScanReverse(entry - 1);
                if (temp.mask !== 1) {
                    temp.index = 0;
                }
                if (temp.index === 31) {
                    temp.index = 0;
                }
                br.bits(temp.index + 1);
            }
        }


        const flags = br.bit();
        if (flags) {
            this.flags = {
                champion: br.bit() === 1,
                unique: br.bit() === 1,
                superUnique: br.bit() === 1,
                minion: br.bit() === 1,
                ghostly: br.bit() === 1
            };

            for (const [key, value] of Object.entries(this.flags)) {
                if (value === false) {
                    delete this.flags[key];
                }
            }
        }

        if (this.flags && this.flags.superUnique) {
            const superUniqueId = br.uint16();
            this.superUniqueName = NpcSuperUnique[superUniqueId];
            // console.warn('SUPERUNIQUE', this, NPCCode[this.code], superUniqueId, this.superUniqueName);
        }



    }

    track() {
        // FIXME
        // this.bits.skip(this.bits.remainingBits);
        // if (this.valid === false) {
        //     Logger.error({ uid: this.uid, ...this.toJSON() }, 'Invalid');
        //     return 0;
        // }

        const npcObj = {
            _t: Date.now(),
            code: this.code,
            uid: this.uid,
            x: this.x,
            y: this.y,
            life: this.life,
            name: NpcName[this.code],
            uniqueName: this.superUniqueName,
            flags: this.flags
        };

        // console.log('NPCAssign', this.uid, this.code, npcObj.name, '@', `${npcObj.x},${npcObj.y}`, npcObj.flags);
        SessionState.current.npc.add(this.uid, npcObj);
        return Log.TRACE;
    }

    toJSON() {
        return {
            ...super.toJSON(),
            uid: this.uid,
            // type: this.type,
            x: this.x,
            y: this.y,
            life: this.life,
            code: this.code,
            monster: NpcName[this.code]
        };
    }
}


