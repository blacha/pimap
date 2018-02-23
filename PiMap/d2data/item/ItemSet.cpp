#include "ItemSet.h"
#include "../../Log.h"
#include <iostream>
#include <fstream>
#include <sstream>

int ItemSet::ItemCount = 0;
std::vector<ItemSet *> ItemSet::items;

int toInt(std::string string);
bool toBool(std::string string);
std::string toString(std::string string);

ItemSet::ItemSet()
{
}
/*
ItemSet::ItemSet(int index, std::string name, std::string name2, int version, int level, std::string PCode2a, std::string PParam2a,
	int PMin2a, int PMax2a, std::string PCode2b, std::string PParam2b, int PMin2b, int PMax2b, std::string PCode3a, std::string PParam3a,
	int PMin3a, int PMax3a, std::string PCode3b, std::string PParam3b, int PMin3b, int PMax3b, std::string PCode4a, std::string PParam4a,
	int PMin4a, int PMax4a, std::string PCode4b, std::string PParam4b, int PMin4b, int PMax4b, std::string PCode5a, std::string PParam5a,
	int PMin5a, int PMax5a, std::string PCode5b, std::string PParam5b, int PMin5b, int PMax5b, std::string FCode1, std::string FParam1,
	int FMin1, int FMax1, std::string FCode2, std::string FParam2, int FMin2, int FMax2, std::string FCode3, std::string FParam3, int FMin3, int FMax3,
	std::string FCode4, std::string FParam4, int FMin4, int FMax4, std::string FCode5, std::string FParam5, int FMin5, int FMax5,
	std::string FCode6, std::string FParam6, int FMin6, int FMax6, std::string FCode7, std::string FParam7, int FMin7, int FMax7,
	std::string FCode8, std::string FParam8, int FMin8, int FMax8)
{
}
*/

ItemSet::ItemSet(std::string line)
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

	int Index = ItemSet::ItemCount++;

	this->Index = Index;
	this->Id = (ItemSetType::ItemSetType) Index;
	this->Name = toString(tokens[0]);
	this->Name2 = toString(tokens[1]);
	this->Version = toInt(tokens[2]);
	this->Level = toInt(tokens[3]);

	this->PCode2a = toString(tokens[4]);
	this->PParam2a = toString(tokens[5]);
	this->PMin2a = toInt(tokens[6]);
	this->PMax2a = toInt(tokens[7]);
	this->PCode2b = toString(tokens[8]);
	this->PParam2b = toString(tokens[9]);
	this->PMin2b = toInt(tokens[10]);
	this->PMax2b = toInt(tokens[11]);
	this->PCode3a = toString(tokens[12]);
	this->PParam3a = toString(tokens[13]);
	this->PMin3a = toInt(tokens[14]);
	this->PMax3a = toInt(tokens[15]);
	this->PCode3b = toString(tokens[16]);
	this->PParam3b = toString(tokens[17]);
	this->PMin3b = toInt(tokens[18]);
	this->PMax3b = toInt(tokens[19]);
	this->PCode4a = toString(tokens[20]);
	this->PParam4a = toString(tokens[21]);
	this->PMin4a = toInt(tokens[22]);
	this->PMax4a = toInt(tokens[23]);
	this->PCode4b = toString(tokens[24]);
	this->PParam4b = toString(tokens[25]);
	this->PMin4b = toInt(tokens[26]);
	this->PMax4b = toInt(tokens[27]);
	this->PCode5a = toString(tokens[28]);
	this->PParam5a = toString(tokens[29]);
	this->PMin5a = toInt(tokens[30]);
	this->PMax5a = toInt(tokens[31]);
	this->PCode5b = toString(tokens[32]);
	this->PParam5b = toString(tokens[33]);
	this->PMin5b = toInt(tokens[34]);
	this->PMax5b = toInt(tokens[35]);
	this->FCode1 = toString(tokens[36]);
	this->FParam1 = toString(tokens[37]);
	this->FMin1 = toInt(tokens[38]);
	this->FMax1 = toInt(tokens[39]);
	this->FCode2 = toString(tokens[40]);
	this->FParam2 = toString(tokens[41]);
	this->FMin2 = toInt(tokens[42]);
	this->FMax2 = toInt(tokens[43]);
	this->FCode3 = toString(tokens[44]);
	this->FParam3 = toString(tokens[45]);
	this->FMin3 = toInt(tokens[46]);
	this->FMax3 = toInt(tokens[47]);
	this->FCode4 = toString(tokens[48]);
	this->FParam4 = toString(tokens[49]);
	this->FMin4 = toInt(tokens[50]);
	this->FMax4 = toInt(tokens[51]);
	this->FCode5 = toString(tokens[52]);
	this->FParam5 = toString(tokens[53]);
	this->FMin5 = toInt(tokens[54]);
	this->FMax5 = toInt(tokens[55]);
	this->FCode6 = toString(tokens[56]);
	this->FParam6 = toString(tokens[57]);
	this->FMin6 = toInt(tokens[58]);
	this->FMax6 = toInt(tokens[59]);
	this->FCode7 = toString(tokens[60]);
	this->FParam7 = toString(tokens[61]);
	this->FMin7 = toInt(tokens[62]);
	this->FMax7 = toInt(tokens[63]);
	this->FCode8 = toString(tokens[64]);
	this->FParam8 = toString(tokens[65]);
	this->FMin8 = toInt(tokens[66]);
	this->FMax8 = toInt(tokens[67]);

	//std::cout << line << std::endl;
}

std::string ItemSet::ToString()
{
	return this->Name;
}

ItemSet * ItemSet::Get(int index)
{
	if (index < 0 || index >= ItemCount)
		throw "ItemSet Get(int index)";

	return items[index];
}

ItemSet * ItemSet::Get(ItemSetType::ItemSetType type)
{
	int index = (int) type;
	if (index < 0 || index >= ItemCount)
		throw "ItemSet Get(ItemSetType::ItemSetType type)";

	return items[index];
}

ItemSet * ItemSet::GetByName(std::string name)
{
	for (int i = 0; i < ItemCount; i++)
		if (_stricmp(items[i]->Name.c_str(), name.c_str()) == 0)
			return items[i];

	throw "ItemSet GetByName(std::string name)";
}

void ItemSet::init()
{
	std::ifstream ifs("data\\ItemSet.csv", std::ifstream::in);

	if (!ifs)
	{
		LOG(logERROR) << "can not find data\\ItemSet.csv";
		exit(1);
	}

	std::string line;

	while (std::getline(ifs, line, '\n'))
	{
		items.push_back(new ItemSet(line));
	}

	ifs.close();
	return;
}
