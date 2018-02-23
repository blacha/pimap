#pragma once

//tolua_begin
namespace BattleNetPlatform
{
    enum BattleNetPlatform
    {
        Ix86 = 0x49583836,
        PowerMac = 0x504d4143,
        XMac = 0x584d4143,
    };
};

namespace BattleNetClient
{
    enum BattleNetClient
    {
        Unknown = 0,
        DiabloShareware = 0x44534852,
        Diablo = 0x4452544c,
        Diablo2 = 0x44324456,
        Diablo2LoD = 0x44325850,
        Warcraft2 = 0x5732424e,
        Warcraft3 = 0x57415233,
        Warcraft3FrozenThrone = 0x57335850,
        StarcraftShareware = 0x53534852,
        StarcraftJapanese = 0x4a535452,
        Starcraft = 0x53544152,
        StarcraftBroodWar = 0x53455850,
        ChatBot = 0x43484154,
    };
};

namespace BattleNetCharacter
{
    enum BattleNetCharacter
    {
        // Diablo 2
        Amazon,
        Sorceress,
        Necromancer,
        Paladin,
        Barbarian,
        // Diablo 2 LoD
        Druid,
        Assassin,

        OpenCharacter,

        // Diablo 1
        Warrior,
        Rogue,
        Sorcerer,

        Unknown1,
        Unknown2Grey,
        Unknown3Grey,

        StarcraftMarine,
        BroodWarMedic,
        WarcraftIIGrunt,
        BlizzardRep,
        Moderator,
        Sysop,
        Referee,
        Chat,
        Speaker,
        Unknown,
    };
};

namespace BattleNetCharacterFlags
{
    enum BattleNetCharacterFlags
    {
        BlizzardRepresentative = 0x01,
        ChannelOperator = 0x02,
        Speaker = 0x04,
        BattleNetAdministrator = 0x08,
        NoUDPSupport = 0x10,
        Squelched = 0x20,
        SpecialGuest = 0x40,
        PGLOfficial = 0x400,			// (Defunct) - probably wrong... 0x4000000 ?
        WCGOfficial = 0x1000,
        KBKSingles = 0x2000,
        KBKPlayer = 0x8000,
        KBKBeginner = 0x10000,
        WhiteKBK = 0x20000,				// 1 orange bar icon
        GameRoom = 0x40000,
        GFOfficial = 0x100000,
        GFPlayer = 0x200000,
        PGLPlayer = 0x2000000,
    };
};

namespace ChannelFlags
{
    enum ChannelFlags
    {
        PublicChannel = 0x01,
        Moderated = 0x02,
        Restricted = 0x04,
        Silent = 0x08,
        System = 0x10,
        ProductSpecific = 0x20,
        GloballyAccessible = 0x1000,
    };
};
// tolua_end
