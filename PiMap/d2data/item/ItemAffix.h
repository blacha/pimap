#pragma once

#include <string>
#include "MagicPrefixType.h"
#include "MagicSuffixType.h"

//tolua_begin
namespace ItemAffixType
{
	enum ItemAffixType
	{
		NotApplicable		= 0,
		Prefix				= 1,
		Suffix				= 2,

		Inferior			= 4,
		InferiorPrefix		= 5,

		Superior			= 8,
		SuperiorPrefix		= 9,

		Magic				= 0x10,
		MagicPrefix			= 0x11,
		MagicSuffix			= 0x12,

		Rare				= 0x20,
		RarePrefix			= 0x21,
		RareSuffix			= 0x22,
	};
};
// tolua_end

class ItemNames { // tolua_export

public:
	//tolua_begin
	static const std::string SuperiorPrefix;
	static const std::string InferiorPrefix[];
	static const int RarePrefixOffset;
	static const int RareSuffixOffset;
	static const std::string RareAffix[];
};
// tolua_end

class ItemAffix { // tolua_export

public:
	//tolua_begin
	ItemAffixType::ItemAffixType Type;
	int Index;
	std::string Name;

	ItemAffix()
	{
	}

	ItemAffix(ItemAffixType::ItemAffixType type, int index)
	{
		this->Index = index;
		this->Type = type;
		if ((int)this->Type < 3)
			throw "ItemAffix(ItemAffixType::ItemAffixType type, int index)";
		if (((int)this->Type & 3) == 0)
		{
			switch (this->Type)
			{
				case ItemAffixType::Superior:
					this->Type = (ItemAffixType::ItemAffixType) (this->Type | ItemAffixType::Prefix);
					break;
				case ItemAffixType::Inferior:
					this->Type = (ItemAffixType::ItemAffixType) (this->Type | ItemAffixType::Prefix);
					break;
				case ItemAffixType::Magic:
					throw "ItemAffix(ItemAffixType::ItemAffixType type, int index)";
				case ItemAffixType::Rare:
					if (index < ItemNames::RarePrefixOffset)
						this->Type = (ItemAffixType::ItemAffixType) (this->Type | ItemAffixType::Suffix);
					else
						this->Type = (ItemAffixType::ItemAffixType) (this->Type | ItemAffixType::Prefix);
					break;
				default:
					throw "ItemAffix(ItemAffixType::ItemAffixType type, int index)";
			}
		}

		if ((this->Type & ItemAffixType::Superior) == ItemAffixType::Superior)
			this->Name = ItemNames::SuperiorPrefix;
		else if ((this->Type & ItemAffixType::Inferior) == ItemAffixType::Inferior)
			this->Name = ItemNames::InferiorPrefix[this->Index];
        else if ((this->Type & ItemAffixType::Magic) == ItemAffixType::Magic)
        {
            if (this->Index == 0)
				this->Name = "";
			if ((this->Type & ItemAffixType::Prefix) == ItemAffixType::Prefix)
				this->Name = MagicPrefixType::toString((MagicPrefixType::MagicPrefixType)this->Index);
            else
				this->Name = MagicSuffixType::toString((MagicSuffixType::MagicSuffixType)this->Index);
        }
		else if ((this->Type & ItemAffixType::Rare) == ItemAffixType::Rare)
            this->Name = ItemNames::RareAffix[this->Index];
	}

	std::string ToString()
	{
		if ((this->Type & ItemAffixType::Superior) == ItemAffixType::Superior)
			return ItemNames::SuperiorPrefix;
		else if ((this->Type & ItemAffixType::Inferior) == ItemAffixType::Inferior)
			return ItemNames::InferiorPrefix[this->Index];
		else if ((this->Type & ItemAffixType::Magic) == ItemAffixType::Magic)
		{
			if (this->Index == 0)
				return "";
			if ((this->Type & ItemAffixType::Prefix) == ItemAffixType::Prefix)
				return MagicPrefixType::toString((MagicPrefixType::MagicPrefixType)this->Index);
			else
				return MagicSuffixType::toString((MagicSuffixType::MagicSuffixType)this->Index);
		}
		else if ((this->Type & ItemAffixType::Rare) == ItemAffixType::Rare)
			return ItemNames::RareAffix[this->Index];

		return "";
	}
};
// tolua_end
