#include "../Log.h"
#include "BaseStat.h"
#include <iostream>
#include <fstream>
#include <sstream>

int BaseStat::ItemCount = 359;
std::vector<BaseStat *> BaseStat::items;

int toInt(std::string string)
{
	if (string.find("\"") != std::string::npos)
	{
		LOG(logINFO, NULL) << "WARNING";
	}

	int result;
	std::istringstream(string) >> result;
	return result;
}

bool toBool(std::string string)
{
	return toInt(string) == 1 ? true : false;
}

std::string toString(std::string string)
{
//	LOG(logINFO) << string.find("\"");
//	LOG(logINFO) << string.rfind("\"");

	int start = string.find("\"");
	int end = string.rfind("\"");


	return string.substr(start + 1, end  - start - 1);
}

BaseStat::BaseStat()
{
}

BaseStat::BaseStat(std::string line)
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

	this->Name = toString(tokens[0]);
	this->Stat = toString(tokens[1]);
	this->Index = toInt(tokens[2]);
	this->TableIndex = toInt(tokens[2]);
	this->Type = (StatType::StatType) toInt(tokens[2]);

	this->SendOther = toBool(tokens[3]);
	this->Signed = toBool(tokens[4]);
	this->SendBits = toInt(tokens[5]);
	this->SendParamBits = toInt(tokens[6]);
	this->UpdateAnimRate = toInt(tokens[7]);
	this->Saved = toInt(tokens[8]);
	this->CSvSigned = toInt(tokens[9]);
	this->CSvBits = toInt(tokens[10]);
	this->CSvParam = toInt(tokens[11]);
	this->fCallback = toInt(tokens[12]);
	this->fMin = toInt(tokens[13]);
	this->MinAccr = toInt(tokens[14]);
	this->Encode = toInt(tokens[15]);
	this->Add = toInt(tokens[16]);
	this->Multiply = toInt(tokens[17]);
	this->Divide = toInt(tokens[18]);
	this->ValShift = toInt(tokens[19]);
	this->SaveBits_1_09 = toInt(tokens[20]);
	this->SaveAdd_1_09 = toInt(tokens[21]);
	this->SaveBits = toInt(tokens[22]);
	this->SaveAdd = toInt(tokens[23]);
	this->SaveParamBits = toInt(tokens[24]);
	this->KeepZero = toBool(tokens[25]);
	this->Op = toInt(tokens[26]);
	this->OpParam = toInt(tokens[27]);
	this->OpBase = (StatType::StatType) toInt(tokens[28]);
	this->OpStat1 = (StatType::StatType) toInt(tokens[29]);
    this->OpStat2 = (StatType::StatType) toInt(tokens[30]);
    this->OpStat3 = (StatType::StatType) toInt(tokens[31]);
	this->Direct = toBool(tokens[32]);
    this->MaxStat = (StatType::StatType) toInt(tokens[33]);
	this->ItemSpecific = toBool(tokens[34]);
	this->DamageRelated = toBool(tokens[35]);
	this->ItemEvent1 = (ItemEventType::ItemEventType) toInt(tokens[36]);
	this->ItemEventFunc1 = toInt(tokens[37]);
	this->ItemEvent2 = (ItemEventType::ItemEventType) toInt(tokens[38]);
	this->ItemEventFunc2 = toInt(tokens[39]);
	this->DescPriority = toInt(tokens[40]);
	this->DescFunc = toInt(tokens[41]);
	this->DescVal = toInt(tokens[42]);
	this->DescStrPos = toString(tokens[43]);
	this->DescStrNeg = toString(tokens[44]);
	this->DescStr2 = toString(tokens[45]);
	this->DGrp = toInt(tokens[46]);
	this->DGrpFunc = toInt(tokens[47]);
	this->DGrpval = toInt(tokens[48]);
	this->DGrpStrPos = toString(tokens[49]);
	this->DGrpStrNeg = toString(tokens[50]);
	this->DGrpStr2 = toInt(tokens[51]);
	this->Stuff = toInt(tokens[52]);
}

std::string BaseStat::ToString()
{
	return this->Name;
}

BaseStat * BaseStat::Get(int index)
{
	if (index < 0 || ItemCount < index)
		throw "BaseStat::Get(int index)";

	return items[index];
}

BaseStat * BaseStat::Get(StatType::StatType type)
{
	int index = (int) type;
	if (index < 0 || ItemCount < index)
		throw "BaseStat::Get(StatType::StatType type)";

	return items[index];
}

BaseStat * BaseStat::GetByStat(std::string stat)
{
    for (int i = 0; i < ItemCount; i++)
		if (_stricmp(items[i]->Stat.c_str(), stat.c_str()) == 0)
            return items[i];

	throw "BaseStat::GetByStat(std::string stat)";
}

BaseStat * BaseStat::GetByName(std::string name)
{
    for (int i = 0; i < ItemCount; i++)
		if (_stricmp(items[i]->Name.c_str(), name.c_str()) == 0)
            return items[i];

    throw "BaseStat::GetByName(std::string name)";
}

void BaseStat::init()
{
	std::ifstream ifs("data\\BaseStat.csv", std::ifstream::in);

	if (!ifs)
	{
		LOG(logERROR) << "can not find data\\BaseStat.csv";
		exit(1);
	}

	std::string line;

	while (std::getline(ifs, line, '\n'))
	{
		items.push_back(new BaseStat(line));
	}

	ifs.close();
	return;
}
