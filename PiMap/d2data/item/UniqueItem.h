#pragma once

#include <string>
#include "UniqueItemType.h"
#include "BaseProperty.h"
#include "BaseItem.h"

/// <summary>
/// Base information class for Unique Items
/// </summary>
class BaseUniqueItem { // tolua_export

public:
	static void init();

private:
	static int ItemCount;
	static std::vector<BaseUniqueItem *> items;

public:
	//tolua_begin
	int Index;
	UniqueItemType::UniqueItemType Id;
	std::string Name;
	BaseItem *Item;

	int Version;
	int Enabled;
	int Ladder;
	int Rarity;
	int NoLimit;
	int DropLevel;
	int RequiredLevel;
	std::string BaseItemName;
	int Uber;
	int Carry1;
	int CostMultiply;
	int CostAdd;
	std::string CharTransform;
	std::string InvTransform;
	std::string FlippyFile;
	std::string InvFile;
	std::string DropSound;
	int DropSfxFrame;
	std::string UseSound;
	BaseProperty *Property1;
	int Param1;
	int Min1;
	int Max1;
	BaseProperty *Property2;
	int Param2;
	int Min2;
	int Max2;
	BaseProperty *Property3;
	int Param3;
	int Min3;
	int Max3;
	BaseProperty *Property4;
	int Param4;
	int Min4;
	int Max4;
	BaseProperty *Property5;
	int Param5;
	int Min5;
	int Max5;
	BaseProperty *Property6;
	int Param6;
	int Min6;
	int Max6;
	BaseProperty *Property7;
	int Param7;
	int Min7;
	int Max7;
	BaseProperty *Property8;
	int Param8;
	int Min8;
	int Max8;
	BaseProperty *Property9;
	int Param9;
	int Min9;
	int Max9;
	BaseProperty *Property10;
	int Param10;
	int Min10;
	int Max10;
	BaseProperty *Property11;
	int Param11;
	int Min11;
	int Max11;
	BaseProperty *Property12;
	int Param12;
	int Min12;
	int Max12;

	BaseUniqueItem();
	BaseUniqueItem(std::string line);

	std::string ToString();

	static BaseUniqueItem * Get(int index);
	static BaseUniqueItem * Get(UniqueItemType::UniqueItemType type);
	static BaseUniqueItem * GetByName(std::string name);
	static BaseProperty * GetProperty(std::string code);
};
// tolua_end
