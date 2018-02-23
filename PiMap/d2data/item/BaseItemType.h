#pragma once

#include <string>
#include "ItemKind.h"
#include "../BaseStat.h"
#include "../CharacterClass.h"

/// <summary>
/// ItemTypes.txt
/// </summary>
class BaseItemType { // tolua_export

public:
	static void init();

private:
	static int ItemCount;
	static std::vector<BaseItemType *> items;

public:
	//tolua_begin
	int Index;
	ItemKind::ItemKind Type;

	std::string Name;
	std::string Code;
	std::string Equiv1;
	std::string Equiv2;
	bool Repair;
    bool Body;
	std::string BodyLoc1;
	std::string BodyLoc2;
	std::string Shoots;
	std::string Quiver;
    bool Throwable;
    bool Reload;
    bool ReEquip;
    bool AutoStack;
    bool Magic;
    bool Rare;
    bool Normal;
    bool Charm;
    bool Gem;
    bool Beltable;
	int MaxSock1;
	int MaxSock25;
	int MaxSock40;
	int TreasureClass;
	int Rarity;
	CharacterClass::CharacterClass StaffMods;
	int CostFormula;
	CharacterClass::CharacterClass Class;
	int VarInvGfx;
	std::string InvGfx1;
	std::string InvGfx2;
	std::string InvGfx3;
	std::string InvGfx4;
	std::string InvGfx5;
	std::string InvGfx6;
	StorePage::StorePage Page;

	BaseItemType();
	BaseItemType(std::string line);

	static BaseItemType *Get(int index);
	static BaseItemType *Get(ItemKind::ItemKind type);
	static BaseItemType *GetByCode(std::string code);
};
// tolua_end
