#pragma once

#include <string>
#include "ItemSet.h"
#include "SetItemType.h"
#include "BaseProperty.h"
#include "BaseItem.h"

/// <summary>
/// Base info class for Set Items
/// </summary>
class BaseSetItem { // tolua_export

public:
	static void init();

private:
	static int ItemCount;
	static std::vector<BaseSetItem *> items;

public:
	//tolua_begin
	int Index;
	SetItemType::SetItemType Id;
	std::string Name;
	ItemSet *Set;
	BaseItem *Item;

	int Rarity;
	int DropLevel;
	int RequiredLevel;
	std::string CharTransform;
	std::string InvTransform;
	std::string InvFile;
	std::string FlippyFile;
	std::string DropSound;
	int DropSfxFrame;
	std::string UseSound;
	int CostMultiply;
	int CostAdd;
	int AddFunc;
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
	BaseProperty *AProperty1a;
	int AParam1a;
	int AMin1a;
	int AMax1a;
	BaseProperty *AProperty1b;
	int AParam1b;
	int AMin1b;
	int AMax1b;
	BaseProperty *AProperty2a;
	int AParam2a;
	int AMin2a;
	int AMax2a;
	BaseProperty *AProperty2b;
	int AParam2b;
	int AMin2b;
	int AMax2b;
	BaseProperty *AProperty3a;
	int AParam3a;
	int AMin3a;
	int AMax3a;
	BaseProperty *AProperty3b;
	int AParam3b;
	int AMin3b;
	int AMax3b;
	BaseProperty *AProperty4a;
	int AParam4a;
	int AMin4a;
	int AMax4a;
	BaseProperty *AProperty4b;
	int AParam4b;
	int AMin4b;
	int AMax4b;
	BaseProperty *AProperty5a;
	int AParam5a;
	int AMin5a;
	int AMax5a;
	BaseProperty *AProperty5b;
	int AParam5b;
	int AMin5b;
	int AMax5b;

	BaseSetItem();
	BaseSetItem(std::string line);

	//TODO: GetBySet and return a BaseSetItem[]

	std::string ToString();

	static BaseSetItem * Get(int index);
	static BaseSetItem * Get(SetItemType::SetItemType type);
	static BaseSetItem * GetByName(std::string name);
};
// tolua_end
