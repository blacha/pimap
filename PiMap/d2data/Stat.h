#pragma once

#include <string>
#include "BaseStat.h"
#include "SkillType.h"
#include "CharacterClass.h"
#include "NPCCode.h"
#include "Stat.h"
#include "DamageType.h"
#include "SkillTab.h"

class StatBase { // tolua_export

public:
	//tolua_begin
    BaseStat *Stat;
	// added
	unsigned int Value;
	unsigned int Param;
	SkillType::SkillType Skill;
	NPCCode::NPCCode Monster;
	int Charges;
	int MaxCharges;
    int Chance;
	ItemEventType::ItemEventType Event;
	DamageType::DamageType Element;
	CharacterClass::CharacterClass Class;
	SkillTab::SkillTab Tab;
	int TabNumber;
	int Unknown;
	double PerLevel;
	DamageType::DamageType Type;
	bool IsPercent;
	int Frames;
	double Seconds;
	int Min;
	int Max;

	StatBase()
	{
		Stat = NULL;
		Value = -1;
		Param = -1;
		Skill = SkillType::Invalid;
		Monster = NPCCode::Invalid;
		Charges = -1;
		MaxCharges = -1;
		Chance = -1;
		Event = ItemEventType::None;
		Element = DamageType::None;
		Class = CharacterClass::Invalid;
		Tab = SkillTab::Invalid;
		TabNumber = -1;
		Unknown = -1;
		PerLevel = -1;
		Type = DamageType::None;
		IsPercent = false;
		Frames = -1;
		Seconds = -1;
		Min = -1;
		Max = -1;
	}

	StatBase(BaseStat *stat)
    {
        this->Stat = stat;
		Value = -1;
		Param = -1;
		Skill = SkillType::Invalid;
		Monster = NPCCode::Invalid;
		Charges = -1;
		MaxCharges = -1;
		Chance = -1;
		Event = ItemEventType::None;
		Element = DamageType::None;
		Class = CharacterClass::Invalid;
		Tab = SkillTab::Invalid;
		TabNumber = -1;
		Unknown = -1;
		PerLevel = -1;
		Type = DamageType::None;
		IsPercent = false;
		Frames = -1;
		Seconds = -1;
		Min = -1;
		Max = -1;
    }

	std::string ToString()
    {
        return this->Stat->ToString();
    }
};
// tolua_end

class SignedStat : public StatBase { // tolua_export
public:
	//tolua_begin
    //int Value;

    SignedStat(BaseStat *stat, int val) : StatBase(stat)
    {
        this->Value = val;
    }

    std::string ToString()
    {
		return "SignedStat";
        //return String.Format("{0}: {1}", this->Stat, this->Value);
    }
};
// tolua_end

class SignedStatParam : public SignedStat { // tolua_export
public:
	//tolua_begin
    //int Param;

    SignedStatParam(BaseStat *stat, int val, int param) : SignedStat(stat, val)
    {
        this->Param = param;
    }

    std::string ToString()
    {
		return "SignedStatParam";
        //return String.Format("{0}: {1}, {2}", this->Stat, this->Value, this->Param);
    }
};
// tolua_end

class UnsignedStat : public StatBase { // tolua_export
public:
	//tolua_begin
    //unsigned int Value;

    UnsignedStat(BaseStat *stat, unsigned int val) : StatBase(stat)
    {
        this->Value = val;
    }

    std::string ToString()
    {
		return "UnsignedStat";
        //return String.Format("{0}: {1}", this->Stat, this->Value);
    }
};
// tolua_end

class UnsignedStatParam : public UnsignedStat { // tolua_export
public:
	//tolua_begin
    //unsigned int Param;

    UnsignedStatParam(BaseStat *stat, unsigned int val, unsigned int param) : UnsignedStat(stat, val)
    {
        this->Param = param;
    }

    std::string ToString()
    {
		return "UnsignedStatParam";
        //return String.Format("{0}: {1}, {2}", this->Stat, this->Value, this->Param);
    }
};
// tolua_end
