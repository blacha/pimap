#pragma once

#include <string>
#include "../Stat.h"
#include "../DamageType.h"
#include "../SkillType.h"
#include "../SkillTab.h"
#include "../NPCCode.h"

class SkillStat : public SignedStat { // tolua_export

public:
	//tolua_begin
	//SkillType::SkillType Skill;

    SkillStat(BaseStat *stat, int skill, int val) : SignedStat(stat, val)
    {
		this->Skill = (SkillType::SkillType)skill;
    }
};
// tolua_end

class ReanimateStat : public UnsignedStat { // tolua_export

public:
	//tolua_begin
	//NPCCode::NPCCode Monster;

    ReanimateStat(BaseStat *stat, unsigned int monster, unsigned int val) : UnsignedStat(stat, val)
    {
		this->Monster = (NPCCode::NPCCode)monster;
    }

    std::string ToString()
    {
        return "ReanimateStat";//String.Format("{0}% Reanimate As: {1}", this->Value, this->Monster);
    }
};
// tolua_end

class AuraStat : public SkillStat { // tolua_export

public:
	//tolua_begin
    AuraStat(BaseStat *stat, int skill, int val) : SkillStat(stat, skill, val)
    {
    }

    std::string ToString()
    {
        return "AuraStat";//String.Format("Level {0} {1} Aura", this->Value, this->Skill);
    }
};
// tolua_end

class SkillBonusStat : public SkillStat { // tolua_export

public:
	//tolua_begin
    //TODO: 
	//public readonly CharacterClass Class;
    //if (stat.Id == StatType.NonClassSkill) this->Class = CharacterClass.Any;
	//else this->Class = BaseSkill.Get(Skill).Class

	SkillBonusStat(BaseStat *stat, int skill, int val) : SkillStat(stat, skill, val)
	{
	}

	std::string ToString()
	{
		return "SkillBonusStat";//String.Format("+{0} To {1}", this->Value, this->Skill);
	}
};
// tolua_end

class ChargedSkillStat : public SkillStat { // tolua_export

public:
	//tolua_begin
	//int Charges;
	//int MaxCharges;

    //public int Level { get { return this->Value; } }

	ChargedSkillStat(BaseStat *stat, int level, int skill, int charges, int maxCharges) : SkillStat(stat, skill, level)
	{
		this->Charges = charges;
		this->MaxCharges = maxCharges;
	}

	std::string ToString()
	{
		return "ChargedSkillStat";//String.Format("Level {0} {1} ({2}/{3} Charges)", this->Value, this->Skill, this->Charges, this->MaxCharges);
	}
};
// tolua_end

class SkillOnEventStat : public SkillStat { // tolua_export

public:
	//tolua_begin
    //int Chance;
	//ItemEventType::ItemEventType Event;

    //public int Level { get { return this->Value; } }

	SkillOnEventStat(BaseStat *stat, int level, int skill, int chance) : SkillStat(stat, skill, level)
	{
		this->Chance = chance;
        this->Event = (ItemEventType::ItemEventType)(stat->ItemEvent1 | stat->ItemEvent2);
	}

	std::string ToString()
	{
		return "SkillOnEventStat";//String.Format("{0}% Chance To Cast Level {1} {2} {3}", this->Chance, this->Value, this->Skill, this->BaseStat.ToString().Substring(6));
	}
};
// tolua_end

class ElementalSkillsBonusStat : public SignedStat { // tolua_export

public:
	//tolua_begin
	//DamageType::DamageType Element;

	ElementalSkillsBonusStat(BaseStat *stat, int element, int val) : SignedStat(stat, val)
	{
		this->Element = (DamageType::DamageType)element;
	}

	std::string ToString()
	{
        return "ElementalSkillsBonusStat";//String.Format("+{0} To {1} Skills", this->Value, this->Element);
	}
};
// tolua_end

class ClassSkillsBonusStat : public SignedStat { // tolua_export

public:
	//tolua_begin
	//CharacterClass::CharacterClass Class;

	ClassSkillsBonusStat(BaseStat *stat, int charClass, int val) : SignedStat(stat, val)
	{
		this->Class = (CharacterClass::CharacterClass)charClass;
	}

	std::string ToString()
	{
		return "ClassSkillsBonusStat";//String.Format("+{0} To {1} Skills", this->Value, this->Class);
	}
};
// tolua_end

class SkillTabBonusStat : public SignedStat { // tolua_export

public:
	//tolua_begin
	//CharacterClass::CharacterClass Class;
	//SkillTab::SkillTab Tab;
	//int TabNumber;
	//int Unknown;

	SkillTabBonusStat(BaseStat *stat, int tab, int charClass, int val) : SignedStat(stat, val)
    {
		this->Class = (CharacterClass::CharacterClass)charClass;
		this->Tab = (SkillTab::SkillTab)((charClass << 3) | tab);
		this->TabNumber = tab;
		this->Unknown = -1;
	}

	SkillTabBonusStat(BaseStat *stat, int tab, int charClass, int unknown, int val) : SignedStat(stat, val)
    {
		this->Class = (CharacterClass::CharacterClass)charClass;
		this->Tab = (SkillTab::SkillTab)((charClass << 3) | tab);
		this->TabNumber = tab;
		this->Unknown = unknown;
	}

	std::string ToString()
	{
		if (this->Unknown > 0)
			return "SkillTabBonusStat";//String.Format("+{0} to {1} {2} Skills ({3})", this->Value, this->Class, this->Tab, this->Unknown);
		else
			return "SkillTabBonusStat";//String.Format("+{0} to {1} {2} Skills", this->Value, this->Class, this->Tab);
	}
};
// tolua_end

class ReplenishStat : public SignedStat { // tolua_export

public:
	//tolua_begin
    //int Seconds;

    ReplenishStat(BaseStat *stat, int val) : SignedStat(stat, val)
    {
        this->Seconds = 100 / val;
    }

    std::string ToString()
    {
		if (this->Stat->Type == StatType::ReplenishQuantity)
            return "SignedStat";//String.Format("Replenishes Quantity (1 in {0} seconds)", this->Seconds);
        else
            return "SignedStat";//String.Format("Repairs 1 Durability in {0} seconds", this->Seconds);
    }
};
// tolua_end

class PerLevelStat : public SignedStat { // tolua_export

public:
	//tolua_begin
    //double PerLevel;

    PerLevelStat(BaseStat *stat, int val) : SignedStat(stat, val)
    {
        this->PerLevel = (double)val / (1 << stat->OpParam);
    }

    std::string ToString()
    {
        return "PerLevelStat";//String.Format("+{0} To {1} Per Level", this->PerLevel, this->BaseStat.OpStat1);
    }
};
// tolua_end

class DamageRangeStat : public SignedStatParam { // tolua_export

public:
	//tolua_begin
	//DamageType::DamageType Type;
	//bool IsPercent;

    //public int Min { get { return this->Value; } }
    //public int Max { get { return this->Param; } }
	
	//ERROR
	//int Min;
	//int Max;

	DamageRangeStat(BaseStat *stat, int min, int max) : SignedStatParam(stat, min, max)
	{
		IsPercent = false;

		switch (stat->Type)
		{
			case StatType::MinDamagePercent:
			case StatType::MaxDamagePercent:
                this->Type = DamageType::Physical;
				this->IsPercent = true;
				break;
			case StatType::FireMinDamage:
                this->Type = DamageType::Fire;
				break;
			case StatType::LightMinDamage:
                this->Type = DamageType::Lightning;
				break;
			case StatType::MagicMinDamage:
                this->Type = DamageType::Magic;
				break;
            case StatType::ColdMinDamage:
                this->Type = DamageType::Cold;
                break;
            case StatType::PoisonMinDamage:
                this->Type = DamageType::Poison;
                break;
		}
	}

	std::string ToString()
	{
		if (this->Min == this->Max)
			return "DamageRangeStat";//String.Format("+{0}{1} {2} Damage", this->Min, this->IsPercent ? "%" : "", this->Type);
		else
			return "DamageRangeStat";//String.Format("+{0}-{1}{2} {3} Damage", this->Min, this->Max, this->IsPercent ? "%" : "", this->Type);
	}
};
// tolua_end

class ColdDamageStat : public DamageRangeStat { // tolua_export

public:
	//tolua_begin
	//int Frames;
	//double Seconds;

	ColdDamageStat(BaseStat *stat, int min, int max, int frames) : DamageRangeStat(stat, min, max)
	{
		this->Frames = frames;
		this->Seconds = (double)frames / 25;
	}

	std::string ToString()
	{
		if (this->Min == this->Max)
			return "ColdDamageStat";//String.Format("+{0} Cold Damage (Chills {1} seconds)", this->Min, Math.Round(this->Seconds, 2));
		else
			return "ColdDamageStat";//String.Format("+{0}-{1} Cold Damage (Chills {2} seconds)", this->Min, this->Max, Math.Round(this->Seconds, 2));
	}
};
// tolua_end

class PoisonDamageStat : public DamageRangeStat { // tolua_export

public:
	//tolua_begin
	//int Frames;
	//double Seconds;
	//public double MinPerSecond { get { return (double) this->Min / 10.25; } }
	//public double MaxPerSecond { get { return (double) this->Max / 10.25; } }

	PoisonDamageStat(BaseStat *stat, int min, int max, int frames) : DamageRangeStat(stat, min, max)
	{
        this->Frames = frames;
        this->Seconds = (double)frames / 25;
		this->Min = (int)((min / 10.25) * this->Seconds);
		this->Max = (int)((max / 10.25) * this->Seconds);
	}

	std::string ToString()
	{
		if (this->Min == this->Max)
			return "PoisonDamageStat";//String.Format("+{1} Poison Damage over {0} seconds", this->Seconds, Math.Floor(this->MinPerSecond * this->Seconds));
		else
			return "PoisonDamageStat";//String.Format("+{1}-{2} Poison Damage over {0} seconds", this->Seconds, Math.Floor(this->MinPerSecond * this->Seconds) + 1, Math.Floor(this->MaxPerSecond * this->Seconds));
	}
};
// tolua_end
