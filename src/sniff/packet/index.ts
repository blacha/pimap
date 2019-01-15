import { IGNORE } from '../packet.ignore';
import { GSPacketAddUnit } from './add.unit';
import { GSPacketAssignWarp } from './add.warp';
import { GSPacketByteToExperience, GSPacketDWordToExperience, GSPacketMercByteToExperience, GSPacketMercWordToExperience, GSPacketWordToExperience } from './gain.exp';
import { GSPacketGameLogonReceipt } from './game.login';
import { GSPacketGameOver } from './game.over';
import { GSPacketItemWorldAction } from './item.world';
import { GSPacketLoadAct } from './load.act';
// import { GSPacketMapAdd } from './map.add';
import { GSPacketMercAssignment } from './merc.assign';
import { GSPacketNPCAction } from './npc.action';
import { GSPacketNPCAssign } from './npc.assign';
import { GSPacketNPCMove, GSPacketNPCMoveToTarget } from './npc.move';
import { GSPacketRemoveGroundUnit } from './npc.remove';
import { GSPacketNPCStop } from './npc.stop';
import { GSPacketNPCUpdate } from './npc.update';
import { GSPacketAssignGameObject, GSPacketGameObjectModeChange, GSPacketSetGameObjectMode } from './object.add';
import { GSPacketAboutPlayer } from './player.about';
import { GSPacketPlayerAssign } from './player.assign';
import { GSPacketPlayerInGame } from './player.in.game';
import { GSPacketPlayerKillCount } from './player.kill.count';
import { GSPacketPlayerLifeManaChange } from './player.life.mana';
import { GSPacketPlayerMove } from './player.move';
import { GSPacketPlayerReassign } from './player.reassign';
import { GSPacketPlayerStop } from './player.stop';
import { GSPacketWalkVerify } from './player.walk';
import { GSPacketReportKill } from './report.kill';
import { Logger } from '../../util/log';

export const PACKETS = [
    GSPacketAddUnit,
    GSPacketAssignGameObject,
    GSPacketAssignWarp,
    GSPacketByteToExperience,
    GSPacketDWordToExperience,
    GSPacketGameLogonReceipt,
    GSPacketGameObjectModeChange,
    GSPacketGameOver,
    GSPacketItemWorldAction,
    GSPacketLoadAct,
    GSPacketMercByteToExperience,
    GSPacketMercWordToExperience,
    GSPacketNPCAction,
    GSPacketNPCAssign,
    GSPacketNPCMove,
    GSPacketNPCMoveToTarget,
    GSPacketNPCStop,
    GSPacketNPCUpdate,
    GSPacketPlayerAssign,
    GSPacketPlayerInGame,
    GSPacketPlayerKillCount,
    GSPacketPlayerLifeManaChange,
    GSPacketPlayerMove,
    GSPacketPlayerReassign,
    GSPacketPlayerStop,
    GSPacketRemoveGroundUnit,
    GSPacketReportKill,
    GSPacketSetGameObjectMode,
    GSPacketWalkVerify,
    GSPacketWordToExperience,
    GSPacketMercAssignment,
    GSPacketAboutPlayer,
    // GSPacketMapAdd
];


PACKETS.forEach(p => {
    if (IGNORE[p.id]) {
        Logger.fatal({ packetId: '0x' + p.id.toString(16) }, 'PacketIdIgnored');
        process.exit();
    }
});


