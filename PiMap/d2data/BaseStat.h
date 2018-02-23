#pragma once

#include <string>
#include <vector>
#include "StatType.h"
#include "item/ItemEnums.h"

/// <summary>
/// Base information for a single Stat Type (as in ItemStatCost.txt)
/// </summary>
class BaseStat { // tolua_export

public:
	static void init();

private:
	static int ItemCount;
	static std::vector<BaseStat *> items;

public:
	//tolua_begin
	StatType::StatType Type;
	int Index;
	int TableIndex;
	std::string Name;
	std::string Stat;
    bool SendOther;
	bool Signed;
	int SendBits;
	int SendParamBits;
	int UpdateAnimRate;
	int Saved;
	int CSvSigned;
	int CSvBits;
	int CSvParam;
	int fCallback;
	int fMin;
	int MinAccr;
	int Encode;
	int Add;
	int Multiply;
	int Divide;
	int ValShift;
	int SaveBits_1_09;
	int SaveAdd_1_09;
	int SaveBits;
	int SaveAdd;
	int SaveParamBits;
    bool KeepZero;
	int Op;
	int OpParam;
    StatType::StatType OpBase;
    StatType::StatType OpStat1;
    StatType::StatType OpStat2;
    StatType::StatType OpStat3;
    bool Direct;
    StatType::StatType MaxStat;
    bool ItemSpecific;
    /// <summary>
    /// If true and the stat is on a weapon, it will only effect your character when you are using that weapon to attack.
    /// </summary>
    bool DamageRelated;
	ItemEventType::ItemEventType ItemEvent1;
	int ItemEventFunc1;
	ItemEventType::ItemEventType ItemEvent2;
	int ItemEventFunc2;
	int DescPriority;
	int DescFunc;
	int DescVal;
	std::string DescStrPos;
	std::string DescStrNeg;
	std::string DescStr2;
	int DGrp;
	int DGrpFunc;
	int DGrpval;
	std::string DGrpStrPos;
	std::string DGrpStrNeg;
	int DGrpStr2;
	int Stuff;

	BaseStat();
	BaseStat(std::string line);
	
	std::string ToString();

	static BaseStat * Get(int index);
	static BaseStat * Get(StatType::StatType type);
    static BaseStat * GetByStat(std::string stat);
    static BaseStat * GetByName(std::string name);
};
// tolua_end
