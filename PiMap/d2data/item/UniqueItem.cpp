#include "UniqueItem.h"
#include "../../Log.h"
#include <iostream>
#include <fstream>
#include <sstream>

int BaseUniqueItem::ItemCount = 0;
std::vector<BaseUniqueItem *> BaseUniqueItem::items;

int toInt(std::string string);
bool toBool(std::string string);
std::string toString(std::string string);

BaseUniqueItem::BaseUniqueItem()
{
}

BaseUniqueItem::BaseUniqueItem(std::string line)
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

	int Index = BaseUniqueItem::ItemCount++;

	this->Index = Index;
	this->Id = (UniqueItemType::UniqueItemType) Index;

	if (line.empty())
	{
		return;
	}

	this->Item = BaseItem::GetByCode(toString(tokens[8]));

	this->Name = toString(tokens[0]);
	this->Version = toInt(tokens[1]);
	this->Enabled = toInt(tokens[2]);
	this->Ladder = toInt(tokens[3]);
	this->Rarity = toInt(tokens[4]);
	this->NoLimit = toInt(tokens[5]);
	this->DropLevel = toInt(tokens[6]);
	this->RequiredLevel = toInt(tokens[7]);

	this->BaseItemName = toString(tokens[9]);
	this->Uber = toInt(tokens[10]);
	this->Carry1 = toInt(tokens[11]);
	this->CostMultiply = toInt(tokens[12]);
	this->CostAdd = toInt(tokens[13]);
	this->CharTransform = toString(tokens[14]);
	this->InvTransform = toString(tokens[15]);
	this->FlippyFile = toString(tokens[16]);
	this->InvFile = toString(tokens[17]);
	this->DropSound = toString(tokens[18]);
	this->DropSfxFrame = toInt(tokens[19]);
	this->UseSound = toString(tokens[20]);

	if (toString(tokens[21]).length() == 0) this->Property1 = NULL;
	else this->Property1 = GetProperty(toString(tokens[21]));
	this->Param1 = toInt(tokens[22]);
	this->Min1 = toInt(tokens[23]);
	this->Max1 = toInt(tokens[24]);
	if (toString(tokens[25]).length() == 0) this->Property2 = NULL;
	else this->Property2 = GetProperty(toString(tokens[25]));
	this->Param2 = toInt(tokens[26]);
	this->Min2 = toInt(tokens[27]);
	this->Max2 = toInt(tokens[28]);
	if (toString(tokens[29]).length() == 0) this->Property3 = NULL;
	else this->Property3 = GetProperty(toString(tokens[29]));
	this->Param3 = toInt(tokens[30]);
	this->Min3 = toInt(tokens[31]);
	this->Max3 = toInt(tokens[32]);
	if (toString(tokens[33]).length() == 0) this->Property4 = NULL;
	else this->Property4 = GetProperty(toString(tokens[33]));
	this->Param4 = toInt(tokens[34]);
	this->Min4 = toInt(tokens[35]);
	this->Max4 = toInt(tokens[36]);
	if (toString(tokens[37]).length() == 0) this->Property5 = NULL;
	else this->Property5 = GetProperty(toString(tokens[37]));
	this->Param5 = toInt(tokens[38]);
	this->Min5 = toInt(tokens[39]);
	this->Max5 = toInt(tokens[40]);
	if (toString(tokens[41]).length() == 0) this->Property6 = NULL;
	else this->Property6 = GetProperty(toString(tokens[41]));
	this->Param6 = toInt(tokens[42]);
	this->Min6 = toInt(tokens[43]);
	this->Max6 = toInt(tokens[44]);
	if (toString(tokens[45]).length() == 0) this->Property7 = NULL;
	else this->Property7 = GetProperty(toString(tokens[45]));
	this->Param7 = toInt(tokens[46]);
	this->Min7 = toInt(tokens[47]);
	this->Max7 = toInt(tokens[48]);
	if (toString(tokens[49]).length() == 0) this->Property8 = NULL;
	else this->Property8 = GetProperty(toString(tokens[49]));
	this->Param8 = toInt(tokens[50]);
	this->Min8 = toInt(tokens[51]);
	this->Max8 = toInt(tokens[52]);
	if (toString(tokens[53]).length() == 0) this->Property9 = NULL;
	else this->Property9 = GetProperty(toString(tokens[53]));
	this->Param9 = toInt(tokens[54]);
	this->Min9 = toInt(tokens[55]);
	this->Max9 = toInt(tokens[56]);
	if (toString(tokens[57]).length() == 0) this->Property10 = NULL;
	else this->Property10 = GetProperty(toString(tokens[57]));
	this->Param10 = toInt(tokens[58]);
	this->Min10 = toInt(tokens[59]);
	this->Max10 = toInt(tokens[60]);
	if (toString(tokens[61]).length() == 0) this->Property11 = NULL;
	else this->Property11 = GetProperty(toString(tokens[61]));
	this->Param11 = toInt(tokens[62]);
	this->Min11 = toInt(tokens[63]);
	this->Max11 = toInt(tokens[64]);
	if (toString(tokens[65]).length() == 0) this->Property12 = NULL;
	else this->Property12 = GetProperty(toString(tokens[65]));
	this->Param12 = toInt(tokens[66]);
	this->Min12 = toInt(tokens[67]);
	this->Max12 = toInt(tokens[68]);

	//std::cout << line << std::endl;
}

std::string BaseUniqueItem::ToString()
{
	return this->Name;
}

BaseUniqueItem * BaseUniqueItem::Get(int index)
{
	return items[index];
}

BaseUniqueItem * BaseUniqueItem::Get(UniqueItemType::UniqueItemType type)
{
	return items[(int) type];
}

BaseUniqueItem * BaseUniqueItem::GetByName(std::string name)
{
	for (int i = 0; i < ItemCount; i++)
		if (items[i] != NULL && items[i]->Name == name)
			return items[i];

	throw "BaseUniqueItem GetByName(std::string name)";
}

BaseProperty * BaseUniqueItem::GetProperty(std::string code)
{
	//if (code.Length < 1)
	//	return null;
	if (code.find("*") == 0)//.StartsWith("*"))
		return BaseProperty::GetByCode(code.substr(1));//.Substring(1));

	return BaseProperty::GetByCode(code);
}

void BaseUniqueItem::init()
{
	std::ifstream ifs("data\\BaseUniqueItem.csv", std::ifstream::in);

	if (!ifs)
	{
		LOG(logERROR) << "can not find data\\BaseUniqueItem.csv";
		exit(1);
	}

	std::string line;

	while (std::getline(ifs, line, '\n'))
	{
		items.push_back(new BaseUniqueItem(line));
	}

	ifs.close();
	return;
}
