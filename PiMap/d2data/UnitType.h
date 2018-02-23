#pragma once

//tolua_begin
namespace UnitType
{
	enum UnitType
	{
        /// <summary>
        /// Any player character, including yours.
        /// </summary>
		Player = 0,
        /// <summary>
        /// Any non player character, including town folks and monsters.
        /// </summary>
		NPC = 1,
        /// <summary>
        /// Most generic game objects, such as chests, dummy objects, etc.
        /// </summary>
		GameObject = 2,
        /// <summary>
        /// Any kind of missiles, even those fired by the French.
        /// </summary>
		Missile = 3,
        /// <summary>
        /// Item units.
        /// </summary>
		Item = 4,
        /// <summary>
        /// Doorways, stairs, etc used to change area.
        /// </summary>
		Warp = 5,		// Room tile ?

		Invalid = 6,
		NotApplicable = 0xFF
	};
};

namespace UnitVisibility
{
	enum UnitVisibility
	{
        /// <summary>
        /// No longer valid (not in proximity, the area for which the client receives extended information.)
        /// </summary>
		Invalid = 0,
        /// <summary>
        /// Displayed on screen.
        /// </summary>
		OnScreen = 1,
        /// <summary>
        /// Visible to the character.
        /// </summary>
		InSight = 2,
        /// <summary>
        /// Within the 2-4 screen range for which the client receives extended information.
        /// </summary>
		InProximity = 4,
	};
};
// tolua_end
