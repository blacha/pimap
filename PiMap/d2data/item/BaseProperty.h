#pragma once

#include <string>
#include <vector>
#include "../StatType.h"
#include "SetItemType.h"

/// <summary>
/// Base info class for item properties (as in Properties.txt)
/// Used by Sets, Uniques and Runewords.
/// </summary>
class BaseProperty { // tolua_export

public:
	static void init();

private:
	static int ItemCount;
	static std::vector<BaseProperty *> items;

public:
	//tolua_begin
	int Index;

	std::string Code;
	bool Done;
	int Set1;
	int Val1;
	int Func1;
	StatType::StatType Stat1;
	int Set2;
	int Val2;
	int Func2;
	StatType::StatType Stat2;
	int Set3;
	int Val3;
	int Func3;
    StatType::StatType Stat3;
	int Set4;
	int Val4;
	int Func4;
    StatType::StatType Stat4;
	int Set5;
	int Val5;
	int Func5;
    StatType::StatType Stat5;
	int Set6;
	int Val6;
	int Func6;
    StatType::StatType Stat6;
	int Set7;
	int Val7;
	int Func7;
    StatType::StatType Stat7;
	std::string Desc;
	std::string Param;
	std::string Min;
	std::string Max;

	BaseProperty();
	BaseProperty(std::string line);

	std::string ToString();

	static BaseProperty * Get(int index);
	static BaseProperty * Get(SetItemType::SetItemType type);
	static BaseProperty * GetByCode(std::string code);
};
// tolua_end
