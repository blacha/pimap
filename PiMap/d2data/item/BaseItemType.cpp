#include "BaseItemType.h"
#include "../../Log.h"
#include <iostream>
#include <fstream>
#include <sstream>

int BaseItemType::ItemCount = 0;
std::vector<BaseItemType *> BaseItemType::items;

int toInt(std::string string);
bool toBool(std::string string);
std::string toString(std::string string);

BaseItemType::BaseItemType()
{
}
/*
BaseItemType::BaseItemType(int Index, std::string Name, std::string Code, std::string Equiv1, std::string Equiv2, int Repair, int Body, std::string BodyLoc1,
	std::string BodyLoc2, std::string Shoots, std::string Quiver, int Throwable, int Reload, int ReEquip, int AutoStack, int Magic,
	int Rare, int Normal, int Charm, int Gem, int Beltable, int MaxSock1, int MaxSock25, int MaxSock40,
    int TreasureClass, int Rarity, int StaffMods, int CostFormula, int Class, int VarInvGfx, std::string InvGfx1,
	std::string InvGfx2, std::string InvGfx3, std::string InvGfx4, std::string InvGfx5, std::string InvGfx6, int Page)
{
	this->Index = Index;
	this->Type = (ItemKind::ItemKind)Index;

	this->Name = Name;
	this->Code = Code;
	this->Equiv1 = Equiv1;
	this->Equiv2 = Equiv2;
	this->Repair = Repair == 1;
	this->Body = Body == 1;
	this->BodyLoc1 = BodyLoc1;
	this->BodyLoc2 = BodyLoc2;
	this->Shoots = Shoots;
	this->Quiver = Quiver;
    this->Throwable = Throwable == 1;
    this->Reload = Reload == 1;
    this->ReEquip = ReEquip == 1;
    this->AutoStack = AutoStack == 1;
    this->Magic = Magic == 1;
    this->Rare = Rare == 1;
    this->Normal = Normal == 1;
    this->Charm = Charm == 1;
    this->Gem = Gem == 1;
    this->Beltable = Beltable == 1;
	this->MaxSock1 = MaxSock1;
	this->MaxSock25 = MaxSock25;
	this->MaxSock40 = MaxSock40;
	this->TreasureClass = TreasureClass;
	this->Rarity = Rarity;
	this->StaffMods = (CharacterClass::CharacterClass)StaffMods;
	this->CostFormula = CostFormula;
	this->Class = (CharacterClass::CharacterClass)Class;
	this->VarInvGfx = VarInvGfx;
	this->InvGfx1 = InvGfx1;
	this->InvGfx2 = InvGfx2;
	this->InvGfx3 = InvGfx3;
	this->InvGfx4 = InvGfx4;
	this->InvGfx5 = InvGfx5;
	this->InvGfx6 = InvGfx6;
	this->Page = (StorePage::StorePage)Page;
}
*/

BaseItemType::BaseItemType(std::string line)
{
    // Skip delimiters at beginning.
	std::string::size_type lastPos = line.find_first_not_of(",", 0);

	// Find first "non-delimiter".
	std::string::size_type pos = line.find_first_of(",", lastPos);

	// vector of tokens
	std::vector<std::string> tokens;

	while (std::string::npos != pos || std::string::npos != lastPos)
	{
		tokens.push_back(line.substr(lastPos, pos - lastPos));

		// Skip delimiters.  Note the "not_of"
		lastPos = line.find_first_not_of(",", pos);

		// Find next "non-delimiter"
		pos = line.find_first_of(",", lastPos);
	}


	this->Index = ItemCount++;
	this->Type = (ItemKind::ItemKind) Index;

	this->Name = toString(tokens[0]);
	this->Code = toString(tokens[1]);
	this->Equiv1 = toString(tokens[2]);
	this->Equiv2 = toString(tokens[3]);
	this->Repair = toBool(tokens[4]);
	this->Body = toBool(tokens[5]);
	this->BodyLoc1 = toString(tokens[6]);
	this->BodyLoc2 = toString(tokens[7]);
	this->Shoots = toString(tokens[8]);
	this->Quiver = toString(tokens[9]);
    this->Throwable = toBool(tokens[10]);
    this->Reload = toBool(tokens[11]);
    this->ReEquip = toBool(tokens[12]);
    this->AutoStack = toBool(tokens[13]);
    this->Magic = toBool(tokens[14]);
    this->Rare = toBool(tokens[15]);
    this->Normal = toBool(tokens[16]);
    this->Charm = toBool(tokens[17]);
    this->Gem = toBool(tokens[18]);
    this->Beltable = toBool(tokens[19]);
	this->MaxSock1 = toInt(tokens[20]);
	this->MaxSock25 = toInt(tokens[21]);
	this->MaxSock40 = toInt(tokens[22]);
	this->TreasureClass = toInt(tokens[23]);
	this->Rarity = toInt(tokens[24]);
	this->StaffMods = (CharacterClass::CharacterClass) toInt(tokens[25]);
	this->CostFormula = toInt(tokens[26]);
	this->Class = (CharacterClass::CharacterClass) toInt(tokens[27]);
	this->VarInvGfx = toInt(tokens[28]);
	this->InvGfx1 = toString(tokens[29]);
	this->InvGfx2 = toString(tokens[30]);
	this->InvGfx3 = toString(tokens[31]);
	this->InvGfx4 = toString(tokens[32]);
	this->InvGfx5 = toString(tokens[33]);
	this->InvGfx6 = toString(tokens[34]);
	this->Page = (StorePage::StorePage) toInt(tokens[35]);
}

BaseItemType *BaseItemType::Get(int index)
{
	if (index < 0 || index >= ItemCount)
		throw "BaseItemType::Get(int index)";

	return items[index];
}

BaseItemType *BaseItemType::Get(ItemKind::ItemKind type)
{
	int index = (int) type;
	if (index < 0 || index >= ItemCount)
		throw "BaseItemType::Get(ItemKind::ItemKind type)";

	return items[index];
}

BaseItemType *BaseItemType::GetByCode(std::string code)
{
	for (int i = 0; i < ItemCount; i++)
		if (_stricmp(items[i]->Code.c_str(), code.c_str()) == 0)
			return items[i];

	throw "BaseItemType::GetByCode(std::string code)";
}

void BaseItemType::init()
{
	std::ifstream ifs("data\\BaseItemType.csv", std::ifstream::in);

	if (!ifs)
	{
		LOG(logERROR) << "can not find data\\BaseItemType.csv";
		exit(1);
	}

	std::string line;

	while (std::getline(ifs, line, '\n'))
	{
		items.push_back(new BaseItemType(line));
	}

	ifs.close();
	return;
}
