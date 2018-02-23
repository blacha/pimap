#pragma once

/*
class CharactersInfo
{
	/// <summary>
	/// Character Genders array. true = Female; false = Male
	/// </summary>
	public static readonly bool[] Genders = new bool[] {
		true, true, false, false, false, false, true
	};
};
*/
//tolua_begin
namespace CharacterClass
{
	enum CharacterClass
    {
        Any = -1,
		Amazon = 0,
		Sorceress = 1,
		Necromancer = 2,
		Paladin = 3,
		Barbarian = 4,
		Druid = 5,
		Assassin = 6,

		Invalid = 7,
		NotApplicable = 8
	};
};

namespace CharacterFlags
{
	enum CharacterFlags
	{
		/// <summary>
		/// None would normally mean a male softcore character on open non-ladder classic who never died...
		/// </summary>
		None			= 0,
		/// <summary>
		/// Character has never joined a game
		/// </summary>
		Noob			= 1,
		UNKNOWNx2		= 2,
		Hardcore		= 4,
		Died			= 8,
		UNKNOWNx10		= 0x10,	// Ghost ? (Died + Hardcore + Chicken...)
		Expansion		= 0x20,
		Ladder			= 0x40,
		Realm			= 0x80,
		Female			= 0x100,
	};
};

namespace CharacterTitle
{
	/// <summary>
	/// All Bnet titles are 0x01 - 0x03. To match this list, add 4 if hardcore, 0x20 if expansion and 0x100 if female...
	/// Some expansion title are gender neutral; if title ends with "F", remove it to get proper title...
	/// </summary>
	enum CharacterTitle
	{
		// Classic, male, softcore
		Nooblar = 0,
		Sir = 1,
		Lord = 2,
		Baron = 3,

		// Classic, female, softcore
		Nooblette = 0x100,
		Dame = 0x101,
		Lady = 0x102,
		Baroness = 0x103,

		// Classic, male, hardcore
		CourageousNooblar = 4,
		Count = 5,
		Duke = 6,
		King = 7,

		// Classic, female, hardcore
		CourageousNooblette = 0x104,
		Countess = 0x105,
		Duchess = 0x106,
		Queen = 0x107,

		// Expansion, male, softcore
		DoublePlusNooblar = 0x20,
		Slayer = 0x21,
		Champion = 0x22,
		Patriarch = 0x23,

		// Expansion, female, softcore
		DoublePlusNooblette = 0x120,
		SlayerF = 0x121,		// Slayer
		ChampionF = 0x122,		// Champion
		Matriarch = 0x123,

		// Expansion, male, hardcore
		NooblarWhoLikesChicken = 0x24,
		Destroyer = 0x25,
		Conquerer = 0x26,
		Guardian = 0x27,

		// Expansion, female, hardcore
		NoobletteWhoLikesChicken = 0x124,
		DestroyerF = 0x125,	// Destroyer
		ConquererF = 0x125,	// Conquerer
		GuardianF = 0x125,	// Guardian

		None = 0xFFFF
	};
};
// tolua_end
