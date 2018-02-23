#pragma once

#include <string>
#include "BaseItem.h"

/// <summary>
/// Data classs holding a single base item's information (as in Weapons.txt)
/// </summary>
class BaseWeapon : public BaseItem { // tolua_export

public:
	//tolua_begin
    unsigned int NormalID;
    unsigned int ExceptionalID;
    unsigned int EliteID;

	int DexBonus;
	int Durability;
	std::string HitClass;
	int MagicLevel;
	int MaxMisDamage;
	int MinMisDamage;
    bool OneOrTwoHanded;
	std::string OpenBetaGfx;
    bool PermStoreItem;
    bool QuestDiffCheck;
	bool Quivered;
	int RangeAdder;
	int ReqDex;
	int ReqStr;
	int StrBonus;
	bool TwoHanded;
	std::string TwoHandedWeaponClass;
	int TwoHandMaxDamage;
	int TwoHandMinDamage;
	std::string WeaponClass;
	std::string SetInvFile;
	int SpawnStack;
	std::string Special;
	int Unknown;

	BaseWeapon::BaseWeapon(std::string line);

	bool isWeapon() { return true; }
	BaseWeapon * getBaseWeapon() { return this; }
};
// tolua_end
