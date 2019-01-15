import { Log } from 'bblog';
import { GameServerPacket } from '../gs.packet';
import { GSPacket } from './game.server';
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

export class GSPacketNPCAssign extends GSPacket {
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


    constructor(data: number[]) {
        super(GSPacketNPCAssign.id);

        const br = new BitReader(data, 8);
        this.uid = br.int32();
        this.code = br.int16();
        this.x = br.int16();
        this.y = br.int16();
        this.life = br.byte();

        br.byte(); // size

        if (data.length < 0x10) {
            this.valid = false;
            return;
        }
        br.bits(4); // ?

        const entries = NPC_FIELDS[this.code];
        if (entries == null) {
            this.valid = false;
            return;
        }
        if (br.bits(1)) {
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


        const flags = br.bits(1);
        if (flags) {
            this.flags = {
                champion: br.bits(1) === 1,
                unique: br.bits(1) === 1,
                superUnique: br.bits(1) === 1,
                minion: br.bits(1) === 1,
                ghostly: br.bits(1) === 1
            };

            for (const [key, value] of Object.entries(this.flags)) {
                if (value === false) {
                    delete this.flags[key];
                }
            }
        }

        if (this.flags && this.flags.superUnique) {
            const superUniqueId = br.int16le();
            this.superUniqueName = NpcSuperUnique[superUniqueId];
            // console.warn('SUPERUNIQUE', this, NPCCode[this.code], superUniqueId, this.superUniqueName);
        }



    }

    track() {
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


