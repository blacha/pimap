#pragma once

//tolua_begin
namespace SkillTab
{
	enum SkillTab
	{
		// Amazon
		BowAndCrossBow		= 0,
		PassiveAndMagic		= 1,
		JavelinAndSpear		= 2,

		// Sorc (0-2 | 8 (or 1 << 3))
		Fire				= 8,
		Lightning			= 9,
		Cold				= 10,

		// Necro (0-2 | 16 (or 2 << 3))
		Curses				= 16,
		PoisonAndBone		= 17,
		NecroSummoning		= 18,

		// Paladin (0-2 | 24 (or 3 << 3))
		PaladinCombat		= 24,
		OffensiveAuras		= 25,
		DefensiveAuras		= 26,

		// Barbarian (0-2 | 32 (or 4 << 3))
		BarbarianCombat		= 32,
		Masteries			= 33,
		Warcries			= 34,

		// Druid (0-2 | 40 (or 5 << 3))
		DruidSummoning		= 40,
		ShapeShifting		= 41,
		Elemental			= 42,

		// Assassin (0-2 | 48 (or 6 << 3))
		Traps				= 48,
		ShadowDisciplines	= 49,
		MartialArts			= 50,

		Invalid				= 0xFFFF,
	};
};
// tolua_end
