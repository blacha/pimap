#pragma once

#include <string>
#include "BaseItem.h"

/// <summary>
/// Data classs holding a single base item's information (as in Armors.txt)
/// </summary>
class BaseArmor : public BaseItem { // tolua_export

public:
	//tolua_begin
    unsigned int NormalID;
    unsigned int ExceptionalID;
    unsigned int EliteID;

	int Absorbs;
	int Block;
	int DexBonus;
	int Durability;
	int lArm;
	int Legs;
	int lSPad;
	int MagicLevel;
	int MaxAc;
	int MaxDamage2;
	int MinAc;
    int MinDamage2;
	std::string OpenBetaGfx;
	bool Quivered;
	int rArm;
	int ReqStr;
	int rSPad;
	std::string SetInvFile;
	int SpellOffset;
	int StrBonus;
	bool Throwable;
    int Torso;

	BaseArmor(std::string line);

	bool isArmor() { return true; }
	BaseArmor * getBaseArmor() { return this; }
};
// tolua_end
