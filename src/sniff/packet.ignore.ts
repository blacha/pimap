import { GameServerPacket } from './gs.packet';
export const IGNORE = {};
const PACKETS = [
    GameServerPacket.AssignPlayerToParty,
    GameServerPacket.AssignSkillHotkey,
    GameServerPacket.AttributeByte,
    GameServerPacket.AttributeDWord, ,
    GameServerPacket.AttributeWord,
    GameServerPacket.DelayedState,
    GameServerPacket.EndState,
    GameServerPacket.GameHandshake,
    GameServerPacket.GameLoading,
    GameServerPacket.GameLogonSuccess,
    GameServerPacket.GameLogoutSuccess,
    GameServerPacket.GameMessage,
    GameServerPacket.IdentifyItem,
    GameServerPacket.InformationMessage,
    GameServerPacket.ItemTriggerSkill,
    GameServerPacket.MapAdd,
    GameServerPacket.MapRemove,
    GameServerPacket.MercAttributeByte,
    GameServerPacket.MercAttributeDWord,
    GameServerPacket.MercAttributeNotification,
    GameServerPacket.MercAttributeWord,
    GameServerPacket.MercForHire,
    GameServerPacket.MercForHireListStart,
    GameServerPacket.NpcAttack,
    GameServerPacket.NPCGetHit,
    GameServerPacket.NPCHeal,
    GameServerPacket.NPCInteraction,
    GameServerPacket.NpcWantsInteract,
    GameServerPacket.OverHeadClear,
    GameServerPacket.PartyMemberPulse,
    GameServerPacket.PartyMemberUpdate,
    GameServerPacket.PartyRefresh,
    GameServerPacket.PlayerAssignSkill,
    GameServerPacket.PlaySound,
    GameServerPacket.Pong,
    GameServerPacket.PortalOwnership,
    GameServerPacket.QuestItemState,
    GameServerPacket.Relator1,
    GameServerPacket.Relator2,
    GameServerPacket.SetState,
    GameServerPacket.SkillsLog,
    GameServerPacket.SmallGoldAdd,
    GameServerPacket.SummonAction,
    GameServerPacket.SwitchWeaponSet,
    GameServerPacket.TransactionComplete,
    GameServerPacket.UnitUseSkill,
    GameServerPacket.UnitUseSkillOnTarget,
    GameServerPacket.UnloadDone,
    GameServerPacket.UpdateGameQuestLog,
    GameServerPacket.UpdateItemUI,
    GameServerPacket.UpdatePlayerItemSkill,
    GameServerPacket.UpdateQuestInfo,
    GameServerPacket.UseSpecialItem,
    GameServerPacket.UseStackableItem,
    GameServerPacket.UpdateContainerItem,

    // Unkown
    0x91, 0x5e, 0x5f, 0x7e, 0x13, 0x18,// unkowns

    0x60, //Portal Info
    0x63, // OpenWaypoint

    // TODO ?
    GameServerPacket.ItemOwnedAction
];
PACKETS.forEach(p => IGNORE[p] = true);
