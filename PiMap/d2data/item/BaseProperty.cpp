#include "BaseProperty.h"
#include "../../Log.h"
#include <iostream>
#include <fstream>
#include <sstream>

int BaseProperty::ItemCount = 0;
std::vector<BaseProperty *> BaseProperty::items;

int toInt(std::string string);
bool toBool(std::string string);
std::string toString(std::string string);

BaseProperty::BaseProperty()
{
}

BaseProperty::BaseProperty(std::string line)
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

	this->Code = toString(tokens[0]);
	this->Done = toBool(tokens[1]);
	this->Set1 = toInt(tokens[2]);
	this->Val1 = toInt(tokens[3]);
	this->Func1 = toInt(tokens[4]);
	this->Stat1 = (StatType::StatType) toInt(tokens[5]);
	this->Set2 = toInt(tokens[6]);
	this->Val2 = toInt(tokens[7]);
	this->Func2 = toInt(tokens[8]);
    this->Stat2 = (StatType::StatType) toInt(tokens[9]);
	this->Set3 = toInt(tokens[10]);
	this->Val3 = toInt(tokens[11]);
	this->Func3 = toInt(tokens[12]);
    this->Stat3 = (StatType::StatType) toInt(tokens[13]);
	this->Set4 = toInt(tokens[14]);
	this->Val4 = toInt(tokens[15]);
	this->Func4 = toInt(tokens[16]);
    this->Stat4 = (StatType::StatType) toInt(tokens[17]);
	this->Set5 = toInt(tokens[18]);
	this->Val5 = toInt(tokens[19]);
	this->Func5 = toInt(tokens[20]);
    this->Stat5 = (StatType::StatType) toInt(tokens[21]);
	this->Set6 = toInt(tokens[22]);
	this->Val6 = toInt(tokens[23]);
	this->Func6 = toInt(tokens[24]);
    this->Stat6 = (StatType::StatType) toInt(tokens[25]);
	this->Set7 = toInt(tokens[26]);
	this->Val7 = toInt(tokens[27]);
	this->Func7 = toInt(tokens[28]);
    this->Stat7 = (StatType::StatType) toInt(tokens[29]);
	this->Desc = toString(tokens[30]);
	this->Param = toString(tokens[31]);
	this->Min = toString(tokens[32]);
	this->Max = toString(tokens[33]);
}

std::string BaseProperty::ToString()
{
	return this->Code;
}

BaseProperty * BaseProperty::Get(int index)
{
	if (index < 0 || index >= ItemCount)
		throw "BaseProperty Get(int index)";

	return items[index];
}

BaseProperty * BaseProperty::Get(SetItemType::SetItemType type)
{
	int index = (int) type;
	if (index < 0 || index >= ItemCount)
		throw "BaseProperty Get(SetItemType type)";

	return items[index];
}

BaseProperty * BaseProperty::GetByCode(std::string code)
{
	for (int i = 0; i < ItemCount; i++)
		if (items[i]->Code == code)
			return items[i];

	throw "BaseProperty GetByCode(std::string code)";
}

void BaseProperty::init()
{
	std::ifstream ifs("data\\BaseProperty.csv", std::ifstream::in);

	if (!ifs)
	{
		LOG(logERROR) << "can not find data\\BaseProperty.csv";
		exit(1);
	}

	std::string line;

	while (std::getline(ifs, line, '\n'))
	{
		items.push_back(new BaseProperty(line));
	}

	ifs.close();
	return;
}
