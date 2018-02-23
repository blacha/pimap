#pragma once

#include <string>
#include "RunewordType.h"
#include "BaseItemType.h"
#include "BaseProperty.h"

/// <summary>
/// Base info class for Runewords
/// </summary>
class BaseRuneword { // tolua_export

public:
	static void init();

private:
	static int ItemCount;
	static std::vector<BaseRuneword *> items;

public:
	//tolua_begin
    int Index;
	RunewordType::RunewordType Id;

	std::string Name;
	bool Complete;
	bool Server;
	BaseItemType *IType1;
	BaseItemType *IType2;
	BaseItemType *IType3;
	BaseItemType *IType4;
	BaseItemType *IType5;
	BaseItemType *IType6;
	BaseItemType *EType1;
	BaseItemType *EType2;
	BaseItemType *EType3;
	std::string Runes;
	std::string Rune1;
	std::string Rune2;
	std::string Rune3;
	std::string Rune4;
	std::string Rune5;
	std::string Rune6;
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

	BaseRuneword();
	BaseRuneword(std::string line);

	std::string ToString();

	static BaseRuneword * Get(RunewordType::RunewordType type);
	static BaseRuneword * Get(int index);
    static BaseRuneword * Get(std::string name);
	static BaseRuneword * GetByName(std::string name);
};
// tolua_end
