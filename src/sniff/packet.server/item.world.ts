import { Log } from 'bblog';
import { ItemActionType, ItemCategory, ItemDestination, ItemFlag, ItemQuality } from '../../core/item';
import { BASE_ITEMS } from '../../generated/item.name';
import { BitReader } from '../../util/bit/bit.reader';
import { GameServerPacket } from '../gs.packet';
import { SessionState } from '../state/session';
import { GamePacket } from './game.server';

import 'source-map-support/register';

export interface ItemFlags {
    isNone: boolean;
    isEquipped: boolean;
    isInSocket: boolean;
    isIdentified: boolean;
    isx20: boolean;
    isSwitchedIn: boolean;
    isSwitchedOut: boolean;
    isBroken: boolean;
    isSocketed: boolean;
    isNotInSocket: boolean;
    isEar: boolean;
    isStartItem: boolean;
    isEthereal: boolean;
    // isAny: boolean;
    isPersonalized: boolean;
    isGamble: boolean;
    isRuneword: boolean;
    isx8000000: boolean;
}

export function makeItemFlags(flags: number): ItemFlags {
    const flagObj: ItemFlags = {
        isNone: (flags & ItemFlag.None) == ItemFlag.None,
        isEquipped: (flags & ItemFlag.Equipped) == ItemFlag.Equipped,
        isInSocket: (flags & ItemFlag.InSocket) == ItemFlag.InSocket,
        isIdentified: (flags & ItemFlag.Identified) == ItemFlag.Identified,
        isx20: (flags & ItemFlag.x20) == ItemFlag.x20,
        isSwitchedIn: (flags & ItemFlag.SwitchedIn) == ItemFlag.SwitchedIn,
        isSwitchedOut: (flags & ItemFlag.SwitchedOut) == ItemFlag.SwitchedOut,
        isBroken: (flags & ItemFlag.Broken) == ItemFlag.Broken,
        // isDuplicate: (flags & ItemFlag.Duplicate) == ItemFlag.Duplicate,
        isSocketed: (flags & ItemFlag.Socketed) == ItemFlag.Socketed,
        // isOnPet: (flags & ItemFlag.OnPet) == ItemFlag.OnPet,
        // isx2000: (flags & ItemFlag.x2000) == ItemFlag.x2000,
        isNotInSocket: (flags & ItemFlag.NotInSocket) == ItemFlag.NotInSocket,
        isEar: (flags & ItemFlag.Ear) == ItemFlag.Ear,
        isStartItem: (flags & ItemFlag.StartItem) == ItemFlag.StartItem,
        // isCompact: (flags & ItemFlag.Compact) == ItemFlag.Compact,
        isEthereal: (flags & ItemFlag.Ethereal) == ItemFlag.Ethereal,
        // isAny: (flags & ItemFlag.Any) == ItemFlag.Any,
        isPersonalized: (flags & ItemFlag.Personalized) == ItemFlag.Personalized,
        isGamble: (flags & ItemFlag.Gamble) == ItemFlag.Gamble,
        isRuneword: (flags & ItemFlag.Runeword) == ItemFlag.Runeword,
        isx8000000: (flags & ItemFlag.x8000000) == ItemFlag.x8000000
    }

    const output = {};
    for (const [key, value] of Object.entries(flagObj)) {
        if (value) {
            output[key] = value;
        }
    }
    return output as ItemFlags;
}

export class GSPacketItemWorldAction extends GamePacket {
    quality: ItemQuality;
    sockets: number;
    level: number;
    flags: ItemFlags;
    uid: number;
    category: ItemCategory;
    action: ItemActionType;
    x: number;
    y: number;
    version: number;
    code: string;
    destination: ItemDestination;
    isSkipped: boolean;
    usedSockets: number;

    static id = GameServerPacket.ItemWorldAction;


    constructor(bits: BitReader) {
        super(bits);

        this.action = <ItemActionType>bits.byte();
        bits.skip(8); // Packet size
        this.category = <ItemCategory>bits.byte();
        this.uid = bits.uint32();

        if (this.id === GameServerPacket.ItemOwnedAction) {
            bits.skip(40);
        }

        this.flags = makeItemFlags(<ItemFlag>bits.uint32())
        this.version = bits.byte();

        bits.skip(2); // Unknown?

        this.destination = <ItemDestination>bits.bits(3);

        if (this.destination === ItemDestination.Ground) {
            this.x = bits.uint16();
            this.y = bits.uint16();
            // this.isSkipped = true;
            // return;
        } else {
            bits.bits(4);
            this.x = bits.bits(4);
            this.y = bits.bits(3);
            bits.bits(4);
        }


        if (this.flags.isEar) {
            this.isSkipped = true;
            return;
        }

        const itemCode = this.code = bits.string(4).trim();
        const itemName = BASE_ITEMS[itemCode];

        if (itemName == null) {
            this.isSkipped = true;
            return;
        }

        if (itemCode === 'gld') {
            this.isSkipped = true;
            return;
        }

        if (this.category === ItemCategory.Misc || this.destination !== ItemDestination.Ground) {
            return;
        }


        this.usedSockets = bits.bits(3);
        this.level = bits.bits(7);
        this.quality = <ItemQuality>bits.bits(4);
    }


    static isOnGround(action: ItemActionType) {
        return action === ItemActionType.AddToGround
            || action === ItemActionType.DropToGround
            || action === ItemActionType.OnGround;
    }


    trackCode(): number {

        if (this.code == null) {
            return 0;
        }

        if (this.code === 'cx5' || this.code === 'cx8') {
            return Log.WARN;
        }

        if (this.code.match(/(r[0-9][0-9])/)) {
            return Log.WARN;
        }

        if (this.quality === ItemQuality.Set) {
            return Log.WARN;
        }

        if (this.quality === ItemQuality.Unique) {
            return Log.WARN;
        }

        if (this.code === 'gld') {
            return 0;
        }

        if (this.quality === ItemQuality.NotApplicable) {
            return 0;
        }

        if (this.sockets === 1) {
            return 0;
        }

        if (this.quality === ItemQuality.Normal) {
            return 0;
        }

        return Log.DEBUG;
    }

    track() {
        this.bits.skip(this.bits.remainingBits);

        if (this.destination !== ItemDestination.Ground) {
            return 0;
        }
        const code = this.trackCode();
        if (code > 20) {
            SessionState.current.item.stat({
                _t: null,
                uid: this.uid,
                x: this.x,
                y: this.y,
                category: this.category,
                quality: this.quality,
                name: BASE_ITEMS[this.code],
                code: this.code,
                level: this.level
            });
        }
        return 0;

    }

    toJSON() {

        return {
            ...super.toJSON(),
            // flags: this.flags,
            uid: this.uid,
            category: ItemCategory[this.category],
            // action: ItemActionType[this.action],
            // destination: ItemDestination[this.destination],
            flags: this.flags,
            code: this.code,
            itemName: BASE_ITEMS[this.code],
            // sockets: this.sockets,
            itemLevel: this.level,
            // x: this.x,
            // y: this.y,
            quality: ItemQuality[this.quality]

        };
    }
}
