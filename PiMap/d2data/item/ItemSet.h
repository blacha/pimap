#pragma once

#include <string>
#include <vector>
#include "ItemSetType.h"

/// <summary>
/// Item Sets Base Info
/// </summary>
class ItemSet { // tolua_export

public:
	static void init();

private:
	static int ItemCount;
	static std::vector<ItemSet *> items;

public:
	//tolua_begin
	int Index;
	ItemSetType::ItemSetType Id;
	std::string Name;
	std::string Name2;

	int Version;
	int Level;
	std::string PCode2a;
	std::string PParam2a;
	int PMin2a;
	int PMax2a;
	std::string PCode2b;
	std::string PParam2b;
	int PMin2b;
	int PMax2b;
	std::string PCode3a;
	std::string PParam3a;
	int PMin3a;
	int PMax3a;
	std::string PCode3b;
	std::string PParam3b;
	int PMin3b;
	int PMax3b;
	std::string PCode4a;
	std::string PParam4a;
	int PMin4a;
	int PMax4a;
	std::string PCode4b;
	std::string PParam4b;
	int PMin4b;
	int PMax4b;
	std::string PCode5a;
	std::string PParam5a;
	int PMin5a;
	int PMax5a;
	std::string PCode5b;
	std::string PParam5b;
	int PMin5b;
	int PMax5b;
	std::string FCode1;
	std::string FParam1;
	int FMin1;
	int FMax1;
	std::string FCode2;
	std::string FParam2;
	int FMin2;
	int FMax2;
	std::string FCode3;
	std::string FParam3;
	int FMin3;
	int FMax3;
	std::string FCode4;
	std::string FParam4;
	int FMin4;
	int FMax4;
	std::string FCode5;
	std::string FParam5;
	int FMin5;
	int FMax5;
	std::string FCode6;
	std::string FParam6;
	int FMin6;
	int FMax6;
	std::string FCode7;
	std::string FParam7;
	int FMin7;
	int FMax7;
	std::string FCode8;
	std::string FParam8;
	int FMin8;
	int FMax8;

	ItemSet();
	ItemSet(std::string line);

	std::string ToString();

	static ItemSet * Get(int index);
	static ItemSet * Get(ItemSetType::ItemSetType type);
	static ItemSet * GetByName(std::string name);
};
// tolua_end
