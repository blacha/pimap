#pragma once

#include <string>
#include "BaseItem.h"

/// <summary>
/// Data classs holding a single base item's information (as in Misc.txt)
/// </summary>
class BaseMiscItem : public BaseItem { // tolua_export

public:
	//tolua_begin
	int SpawnStack;
	bool AutoBelt;
	ItemType::ItemType BetterGem;
	int Calc1;
	int Calc2;
	int Calc3;
	StateType::StateType CState1;
	StateType::StateType CState2;
	int Len;
	bool MultiBuy;
	std::string Name2;
	bool PermStoreItem;
	int pSpell;
	bool QuestDiffCheck;
	std::string Special;
	int SpellDesc;
	int SpellDescCalc;
	std::string SpellDescStr;
	int SpellIcon;
	StatType::StatType Stat1;
	StatType::StatType Stat2;
	StatType::StatType Stat3;
	StateType::StateType State;
	int SzFlavorText;
	bool Throwable;
	int TMogMax;
	int TMogMin;
	std::string TMogType;
	bool Transmogrify;

	BaseMiscItem(std::string line);

	bool isMiscItem() { return true; }
	BaseMiscItem * getBaseMiscItem() { return this; };
};
// tolua_end
