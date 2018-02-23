#pragma once

//tolua_begin
namespace NPCType
{
	enum NPCFlag
	{
		IsSuperUnique = 0x01,
		IsChampion = 0x04,
		IsBoss = 0x08,
		IsMinion = 0x10,
		IsCloaked = 0x40,
	};
};
// tolua_end
