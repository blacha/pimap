import { Log } from 'bblog';
import { ItemActionType, ItemCategory, ItemFlag, ItemQuality } from '../../core/item';
import { GameServerPacket } from '../gs.packet';
import { GamePacket } from './game.server';
import { BitConverter } from '../../util/bit/bit.converter';
import { BitReader } from '../../util/bit/bit.reader';
import { SessionState } from '../state/session';
import { BASE_ITEMS } from '../../generated/item.name';
import { toHexString } from '../../util/to.hex';

export class GSPacketItemWorldAction extends GamePacket {
    quality: ItemQuality;
    sockets: number;
    level: number;
    flags: ItemFlag;
    uid: number;
    category: ItemCategory;
    action: ItemActionType;
    x: number;
    y: number;
    version: number;
    code: string;

    static id = GameServerPacket.ItemWorldAction;


    constructor(bits: BitReader) {
        super(bits);

        this.action = <ItemActionType>bits.byte();
        bits.skipByte();
        this.category = <ItemCategory>bits.byte();
        this.uid = bits.uint32();
        this.flags = <ItemFlag>bits.uint32()
        this.version = bits.byte();


        if (!GSPacketItemWorldAction.isOnGround(this.action)) {
            return;
        }

        this.x = Math.floor((bits.uint16() + 131072) / 32);
        this.y = Math.floor((bits.uint16() + 131072) / 32);

        bits.skip();
        bits.bits(4); // container

        const itemCode = this.code = bits.string(3);

        // TODO everything is broken
        const itemName = BASE_ITEMS[itemCode];
        if (itemName == null) {
            return;
        }

        bits.bits(4);

        if (itemCode === 'gld') {
            return;
        }

        bits.bits(4);

        if ((this.flags & ItemFlag.Socketed) === ItemFlag.Socketed) {
            this.sockets = bits.bits(3);
        }
        bits.bits(3);


        this.level = bits.bits(7);
        this.quality = <ItemQuality>bits.bits(4);

        if (bits.bits(1)) {
            bits.bits(3);
        }
        if (bits.bits(1)) {
            bits.bits(11);
        }

    }

    static isOnGround(action: ItemActionType) {
        return action === ItemActionType.AddToGround
            || action === ItemActionType.DropToGround
            || action === ItemActionType.OnGround;
    }


    trackCode(): number {
        // FIXME
        this.bits.skip(this.bits.remainingBits);
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
            action: ItemActionType[this.action],
            code: this.code,
            itemName: BASE_ITEMS[this.code],
            sockets: this.sockets,
            itemLevel: this.level,
            x: this.x,
            y: this.y,
            quality: ItemQuality[this.quality]

        };
    }
}

