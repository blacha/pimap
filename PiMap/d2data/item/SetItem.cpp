#include "ItemSet.h"
#include "SetItem.h"
#include "../../Log.h"
#include <iostream>
#include <fstream>
#include <sstream>

int BaseSetItem::ItemCount = 0;
std::vector<BaseSetItem *> BaseSetItem::items;

int toInt(std::string string);
bool toBool(std::string string);
std::string toString(std::string string);

BaseSetItem::BaseSetItem()
{
}

BaseSetItem::BaseSetItem(std::string line)
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

	int Index = BaseSetItem::ItemCount++;

	this->Index = Index;
	this->Id = (SetItemType::SetItemType) Index;
	this->Name = toString(tokens[0]);
	this->Set = ItemSet::GetByName(toString(tokens[1]));
	this->Item = BaseItem::GetByCode(toString(tokens[2]));

	this->Rarity = toInt(tokens[3]);
	this->DropLevel = toInt(tokens[4]);
	this->RequiredLevel = toInt(tokens[5]);
	this->CharTransform = toString(tokens[6]);
	this->InvTransform = toString(tokens[7]);
	this->InvFile = toString(tokens[8]);
	this->FlippyFile = toString(tokens[9]);
	this->DropSound = toString(tokens[10]);
	this->DropSfxFrame = toInt(tokens[11]);
	this->UseSound = toString(tokens[12]);
	this->CostMultiply = toInt(tokens[13]);
	this->CostAdd = toInt(tokens[14]);
	this->AddFunc = toInt(tokens[15]);
	if (toString(tokens[16]).length() == 0) this->Property1 = NULL;
	else this->Property1 = BaseProperty::GetByCode(toString(tokens[16]));
	this->Param1 = toInt(tokens[17]);
	this->Min1 = toInt(tokens[18]);
	this->Max1 = toInt(tokens[19]);
	if (toString(tokens[20]).length() == 0) this->Property2 = NULL;
	else this->Property2 = BaseProperty::GetByCode(toString(tokens[20]));
	this->Param2 = toInt(tokens[21]);
	this->Min2 = toInt(tokens[22]);
	this->Max2 = toInt(tokens[23]);
	if (toString(tokens[24]).length() == 0) this->Property3 = NULL;
	else this->Property3 = BaseProperty::GetByCode(toString(tokens[24]));
	this->Param3 = toInt(tokens[25]);
	this->Min3 = toInt(tokens[26]);
	this->Max3 = toInt(tokens[27]);
	if (toString(tokens[28]).length() == 0) this->Property4 = NULL;
	else this->Property4 = BaseProperty::GetByCode(toString(tokens[28]));
	this->Param4 = toInt(tokens[29]);
	this->Min4 = toInt(tokens[30]);
	this->Max4 = toInt(tokens[31]);
	if (toString(tokens[32]).length() == 0) this->Property5 = NULL;
	else this->Property5 = BaseProperty::GetByCode(toString(tokens[32]));
	this->Param5 = toInt(tokens[33]);
	this->Min5 = toInt(tokens[34]);
	this->Max5 = toInt(tokens[35]);
	if (toString(tokens[36]).length() == 0) this->Property6 = NULL;
	else this->Property6 = BaseProperty::GetByCode(toString(tokens[36]));
	this->Param6 = toInt(tokens[37]);
	this->Min6 = toInt(tokens[38]);
	this->Max6 = toInt(tokens[39]);
	if (toString(tokens[40]).length() == 0) this->Property7 = NULL;
	else this->Property7 = BaseProperty::GetByCode(toString(tokens[40]));
	this->Param7 = toInt(tokens[41]);
	this->Min7 = toInt(tokens[42]);
	this->Max7 = toInt(tokens[43]);
	if (toString(tokens[44]).length() == 0) this->Property8 = NULL;
	else this->Property8 = BaseProperty::GetByCode(toString(tokens[44]));
	this->Param8 = toInt(tokens[45]);
	this->Min8 = toInt(tokens[46]);
	this->Max8 = toInt(tokens[47]);
	if (toString(tokens[48]).length() == 0) this->Property9 = NULL;
	else this->Property9 = BaseProperty::GetByCode(toString(tokens[48]));
	this->Param9 = toInt(tokens[49]);
	this->Min9 = toInt(tokens[50]);
	this->Max9 = toInt(tokens[51]);
	if (toString(tokens[52]).length() == 0) this->AProperty1a = NULL;
	else this->AProperty1a = BaseProperty::GetByCode(toString(tokens[52]));
	this->AParam1a = toInt(tokens[53]);
	this->AMin1a = toInt(tokens[54]);
	this->AMax1a = toInt(tokens[55]);
	if (toString(tokens[56]).length() == 0) this->AProperty1b = NULL;
	else this->AProperty1b = BaseProperty::GetByCode(toString(tokens[56]));
	this->AParam1b = toInt(tokens[57]);
	this->AMin1b = toInt(tokens[58]);
	this->AMax1b = toInt(tokens[59]);
	if (toString(tokens[60]).length() == 0) this->AProperty2a = NULL;
	else this->AProperty2a = BaseProperty::GetByCode(toString(tokens[60]));
	this->AParam2a = toInt(tokens[61]);
	this->AMin2a = toInt(tokens[62]);
	this->AMax2a = toInt(tokens[63]);
	if (toString(tokens[64]).length() == 0) this->AProperty2b = NULL;
	else this->AProperty2b = BaseProperty::GetByCode(toString(tokens[64]));
	this->AParam2b = toInt(tokens[65]);
	this->AMin2b = toInt(tokens[66]);
	this->AMax2b = toInt(tokens[67]);
	if (toString(tokens[68]).length() == 0) this->AProperty3a = NULL;
	else this->AProperty3a = BaseProperty::GetByCode(toString(tokens[68]));
	this->AParam3a = toInt(tokens[69]);
	this->AMin3a = toInt(tokens[70]);
	this->AMax3a = toInt(tokens[71]);
	if (toString(tokens[72]).length() == 0) this->AProperty3b = NULL;
	else this->AProperty3b = BaseProperty::GetByCode(toString(tokens[72]));
	this->AParam3b = toInt(tokens[73]);
	this->AMin3b = toInt(tokens[74]);
	this->AMax3b = toInt(tokens[75]);
	if (toString(tokens[76]).length() == 0) this->AProperty4a = NULL;
	else this->AProperty4a = BaseProperty::GetByCode(toString(tokens[76]));
	this->AParam4a = toInt(tokens[77]);
	this->AMin4a = toInt(tokens[78]);
	this->AMax4a = toInt(tokens[79]);
	if (toString(tokens[80]).length() == 0) this->AProperty4b = NULL;
	else this->AProperty4b = BaseProperty::GetByCode(toString(tokens[80]));
	this->AParam4b = toInt(tokens[81]);
	this->AMin4b = toInt(tokens[82]);
	this->AMax4b = toInt(tokens[83]);
	if (toString(tokens[84]).length() == 0) this->AProperty5a = NULL;
	else this->AProperty5a = BaseProperty::GetByCode(toString(tokens[84]));
	this->AParam5a = toInt(tokens[85]);
	this->AMin5a = toInt(tokens[86]);
	this->AMax5a = toInt(tokens[87]);
	if (toString(tokens[88]).length() == 0) this->AProperty5b = NULL;
	else this->AProperty5b = BaseProperty::GetByCode(toString(tokens[88]));
	this->AParam5b = toInt(tokens[89]);
	this->AMin5b = toInt(tokens[90]);
	this->AMax5b = toInt(tokens[91]);

	//std::cout << line << std::endl;
}

std::string BaseSetItem::ToString()
{
	return this->Name;
}

BaseSetItem * BaseSetItem::Get(int index)
{
	if (index < 0 || index >= ItemCount)
		throw "BaseSetItem Get(int index)";

	return items[index];
}

BaseSetItem * BaseSetItem::Get(SetItemType::SetItemType type)
{
	int index = (int) type;
	if (index < 0 || index >= ItemCount)
		throw "BaseSetItem Get(SetItemType::SetItemType type)";

	return items[index];
}

BaseSetItem * BaseSetItem::GetByName(std::string name)
{
	for (int i = 0; i < ItemCount; i++)
		if (items[i]->Name == name)
			return items[i];

	throw "BaseSetItem GetByName(std::string name)";
}

void BaseSetItem::init()
{
	std::ifstream ifs("data\\BaseSetItem.csv", std::ifstream::in);

	if (!ifs)
	{
		 LOG(logERROR) << "can not find data\\BaseSetItem.csv";
		 exit(1);
	}

	std::string line;

	while (std::getline(ifs, line, '\n'))
	{
		items.push_back(new BaseSetItem(line));
	}

	ifs.close();
	return;
}
