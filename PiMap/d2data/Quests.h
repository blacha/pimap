#pragma once
#include <string>
//tolua_begin
namespace GameQuestState
{
    enum GameQuestState
    {
        /// <summary>
        /// The creator had not completed the quest and it has not been done in this game yet.
        /// </summary>
        Open = 0,
        /// <summary>
        /// The creator has already completed this quest.
        /// </summary>
        Closed = 0x8000,
        /// <summary>
        /// The quest has already been completed in game.
        /// </summary>
        Completed = 0x2000,
    };
};

namespace QuestState
{
    enum QuestState
    {
        Event1 = 1,
        Event2 = 2,
        Event4 = 4,
        Event8 = 8,
        Active = 0x10,
        /// <summary>
        /// Previous quest's main goal is accomplished !?!
        /// </summary>
        Enabled = 0x20,
        Unknown0x40 = 0x40,     //TODO:
        /// <summary>
        /// An NPC wants to give the quest, or quest was given by an NPC.
        /// </summary>
        FromNPC = 0x80,
    };
};

namespace QuestStanding
{
    enum QuestStanding
    {
        Complete = 1,
        RewardPending = 2,
        Started = 4,
        LeftTownWhileStarted = 8,
        EnteredFirstArea = 0x10,
        Event0x20 = 0x20,
        Event0x40 = 0x40,
        Event0x80 = 0x80,
    };
};

namespace QuestType
{
    /// <summary>
    /// Diablo II quest or sub quest type.
    /// </summary>
    enum QuestType
    {
        SpokeToWarriv = 0,
        DenOfEvil = 1,
        SistersBurialGrounds = 2,
        ToolsOfTheTrade = 3,
        TheSearchForCain = 4,
        TheForgottenTower = 5,
        SistersToTheSlaughter = 6,
        CanGoToAct2 = 7,
        SpokeToJerhyn = 8,
        RadamentsLair = 9,
        TheHoradricStaff = 10,
        TaintedSun = 11,
        ArcaneSanctuary = 12,
        TheSummoner = 13,
        TheSevenTombs = 14,
        CanGoToAct3 = 15,
        SpokeToHratli = 16,
        LamEsensTome = 17,
        KhalimsWill = 18,
        BladeOfTheOldReligion = 19,
        TheGoldenBird = 20,
        TheBlackenedTemple = 21,
        TheGuardian = 22,
        CanGoToAct4 = 23,
        SpokeToTyrael = 24,
        TheFallenAngel = 25,
        TerrorsEnd = 26,
        HellsForge = 27,
        /* TODO: extra sub quests here !!!
        1A   a4q3   The Hellforge
        1B          (referred to)
                    (also items "hfh" and "dss" -- "hfh" is Hellforge Hammer,
                     but "dss" not in item tables)
        1C          (referred to in Hellforge code)
        1D          <<not used???>>
        1E   a2q7   vestigial reference???
        1F   a2q8   vestigial reference???
        20   a3q7   vestigial reference???
        21          <<not used???>>
        22          <<not used???>>
        */
        CanGoToAct5 = 28,
        // TODO: extra sub quests here !!!
        TheSecretCowLevel = 32,
        // TODO: extra sub quests here !!!
        SeigeOnHarrogath = 35,
        RescueOnMountArreat = 36,
        PrisonOfIce = 37,
        BetrayalOfHarrogath = 38,
        RiteOfPassage = 39,
        EveOfDestruction = 40,
    };
};
class QuestData
{
public:
	QuestType::QuestType type;
	QuestState::QuestState state;
	QuestStanding::QuestStanding standing;
};
// tolua_end
