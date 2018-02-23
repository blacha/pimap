#pragma once

#include <string>
#include "BaseItemType.h"
#include "ItemType.h"
#include "../StateType.h"

class BaseArmor;
class BaseMiscItem;
class BaseWeapon;

/// <summary>
/// Abstract base class and static container class for BaseArmor, BaseWeapon and BaseMiscItem
/// </summary>
class BaseItem { // tolua_export

protected:
	static const int BASE_ARMOR_START = 150;
	static const int BASE_WEAPON_START = 351;

public:
	static void init();

protected:
	static int ItemCount;

private:
	static std::vector<BaseItem *> items;

public:
	//tolua_begin
	ItemType::ItemType type;
	int index;
    int tableIndex;
	BaseItemType *baseType;
    BaseItemType *baseType2;
	std::string code;
    unsigned int id;
    unsigned int nightmareUpgrade;
    unsigned int hellUpgrade;

	int akaraMagicLvl;
	int akaraMagicMax;
	int akaraMagicMin;
	int akaraMax;
	int akaraMin;
	int alkorMagicLvl;
	int alkorMagicMax;
	int alkorMagicMin;
	int alkorMax;
	int alkorMin;
	std::string alternateGfx;
	int ashearaMagicLvl;
	int ashearaMagicMax;
	int ashearaMagicMin;
	int ashearaMax;
	int ashearaMin;
	int autoPrefix;
	bool belt;
	int bitField1;
	int cainMagicLvl;
	int cainMagicMax;
	int cainMagicMin;
	int cainMax;
	int cainMin;
	int charsiMagicLvl;
	int charsiMagicMax;
	int charsiMagicMin;
	int charsiMax;
	int charsiMin;
	int compactSave;
	int component;
	int cost;
	int drehyaMagicLvl;
	int drehyaMagicMax;
	int drehyaMagicMin;
	int drehyaMax;
	int drehyaMin;
	int drognanMagicLvl;
	int drognanMagicMax;
	int drognanMagicMin;
	int drognanMax;
	int drognanMin;
	int dropSfxFrame;
	std::string dropSound;
	int durabilityWarning;
	int elzixMagicLvl;
	int elzixMagicMax;
	int elzixMagicMin;
	int elzixMax;
	int elzixMin;
	int faraMagicLvl;
	int faraMagicMax;
	int faraMagicMin;
	int faraMax;
	int faraMin;
	std::string flippyFile;
	int gambleCost;
	int gameArt;
	int gemApplyType;
	int gemOffset;
	int gemSockets;
	int gheedMagicLvl;
	int gheedMagicMax;
	int gheedMagicMin;
	int gheedMax;
	int gheedMin;
	int halbuMagicLvl;
	int halbuMagicMax;
	int halbuMagicMin;
	int halbuMax;
	int halbuMin;
    bool hasInv;
	int hraltiMagicLvl;
	int hraltiMagicMax;
	int hraltiMagicMin;
	int hraltiMax;
	int hraltiMin;
	std::string invFile;
	int invHeight;
	int invTrans;
	int invWidth;
	int jamellaMagicLvl;
	int jamellaMagicMax;
	int jamellaMagicMin;
	int jamellaMax;
	int jamellaMin;
	int larzukMagicLvl;
	int larzukMagicMax;
	int larzukMagicMin;
	int larzukMax;
	int larzukMin;
	int level;
	int levelReq;
	int lightRadius;
	int lysanderMagicLvl;
	int lysanderMagicMax;
	int lysanderMagicMin;
	int lysanderMax;
	int lysanderMin;
	int malahMagicLvl;
	int malahMagicMax;
	int malahMagicMin;
	int malahMax;
	int malahMin;
	int maxDamage;
	int maxStack;
	int minDamage;
	int minStack;
	int missileType;
	std::string name;
    bool nameable;
	std::string nameString;
    bool noDurability;
	int ormusMagicLvl;
	int ormusMagicMax;
	int ormusMagicMin;
	int ormusMax;
	int ormusMin;
	int quantityWarning;
	int quest;
	int rarity;
	int skipName;
	int sourceArt;
    bool spawnable;
	int speed;
    bool stackable;
	int transform;
	bool transparent;
	int transTbl;
	bool unique;
	std::string uniqueInvFile;
    bool useable;
	std::string useSound;
	int version;

public:

	BaseItem()
	{
	}

	virtual bool isArmor() { return false; }
	virtual bool isMiscItem() { return false; }
	virtual bool isWeapon() { return false; }

	virtual BaseArmor * getBaseArmor() { return NULL; }
	virtual BaseMiscItem * getBaseMiscItem() { return NULL; }
	virtual BaseWeapon * getBaseWeapon() { return NULL; }

	std::string ToString()
	{
		return this->name;
	}

	static BaseItem *Get(int index)
	{
		if (index < 0 || index >= ItemCount)
			throw "BaseItem Get(int index)";

		return items[index];
	}

	static BaseItem *Get(ItemType::ItemType type)
	{
		int index = (int) type;
		if (index < 0 || index >= ItemCount)
			throw "BaseItem Get(ItemType type)";

		return items[index];
	}

    static BaseItem *GetByID(unsigned int id)
    {
        for (int i = 0; i < ItemCount; i++)
            if (items[i]->id == id)
                return items[i];

        throw "BaseItem GetByID(unsigned int id)";
    }

	static BaseItem *GetByID(ItemCategory::ItemCategory cat, unsigned int id)
    {
        switch (cat)
        {
			case ItemCategory::Armor:
			case ItemCategory::Helm:
			case ItemCategory::Shield:
                return GetArmorByID(id);
			case ItemCategory::Weapon:
				return GetWeaponByID(id);
            // case ItemCategory.Weapon2:  // But sometimes shields...
            // case ItemCategory.Misc:     // Can be boots, gloves etc...
            // case ItemCategory.Special:
            default:
                return GetByID(id);
        }
    }

	static BaseItem *GetByCode(std::string code)
	{
		for (int i = 0; i < ItemCount; i++)
			if (_stricmp(items[i]->code.c_str(), code.c_str()) == 0)
				return items[i];

		throw "BaseItem GetByCode(std::string code)";
	}

    static BaseItem *GetArmorByID(unsigned int id)
    {
        for (int i = BASE_ARMOR_START; i < BASE_WEAPON_START; i++)
            if (items[i]->id == id)
                return items[i];// as BaseArmor;

        throw "BaseArmor GetArmorByID(unsigned int id)";
    }

	static BaseItem *GetWeaponByID(unsigned int id)
    {
        for (int i = BASE_WEAPON_START; i < ItemCount; i++)
            if (items[i]->id == id)
                return items[i];// as BaseWeapon;

        throw "BaseWeapon GetWeaponByID(unsigned int id)";
    }

	static unsigned int GetIdFromCode(std::string code)
    {
        unsigned int retVal = 0;
        for (unsigned int i = 0; i < 4; i++)
			retVal |= (unsigned int)((char)(i < code.length() ? code[i] & 0xFF : 0x20) << (i * 8));
        return retVal;
    }

	static std::string GetCodeFromId(unsigned int id)
    {
        char chars[4];
        for (int i = 0; i < 4; i++)
            chars[i] = (char)(char)(id >> (i*8));
		return std::string(chars);
    }

	static unsigned int GetBeltRow(BaseItem *item)
	{
		switch(item->type)
		{
			case ItemType::Sash:
			case ItemType::LightBelt:
				return 2;
			case ItemType::Belt:
			case ItemType::HeavyBelt:
				return 3;
			case ItemType::PlatedBelt:
			case ItemType::DemonhideSash:
			case ItemType::SharkskinBelt:
			case ItemType::MeshBelt:
			case ItemType::BattleBelt:
			case ItemType::WarBelt:
			case ItemType::SpiderwebSash:
			case ItemType::VampirefangBelt:
			case ItemType::MithrilCoil:
			case ItemType::TrollBelt:
			case ItemType::ColossusGirdle:
				return 4;
			default: return 1;
		}
	}
};
// tolua_end
