#include "BaseRuneword.h"
#include "SetItem.h"
#include "../../Log.h"
#include <iostream>
#include <fstream>
#include <sstream>

int BaseRuneword::ItemCount = 0;
std::vector<BaseRuneword *> BaseRuneword::items;

int toInt(std::string string);
bool toBool(std::string string);
std::string toString(std::string string);

BaseRuneword::BaseRuneword()
{
}

BaseRuneword::BaseRuneword(std::string line)
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

	int Index = ++BaseRuneword::ItemCount;

	this->Index = Index;
	this->Id = (RunewordType::RunewordType) Index;

	if (line.empty())
	{
		return;
	}

	this->Name = toString(tokens[0]);
	this->Complete = toBool(tokens[1]);
	this->Server = toBool(tokens[2]);
	if (toString(tokens[3]).length() == 0) this->IType1 = NULL;
	else this->IType1 = BaseItemType::GetByCode(toString(tokens[3]));
	if (toString(tokens[4]).length() == 0) this->IType2 = NULL;
	else this->IType2 = BaseItemType::GetByCode(toString(tokens[4]));
	if (toString(tokens[5]).length() == 0) this->IType3 = NULL;
	else this->IType3 = BaseItemType::GetByCode(toString(tokens[5]));
	if (toString(tokens[6]).length() == 0) this->IType4 = NULL;
	else this->IType4 = BaseItemType::GetByCode(toString(tokens[6]));
	if (toString(tokens[7]).length() == 0) this->IType5 = NULL;
	else this->IType5 = BaseItemType::GetByCode(toString(tokens[7]));
	if (toString(tokens[8]).length() == 0) this->IType6 = NULL;
	else this->IType6 = BaseItemType::GetByCode(toString(tokens[8]));
	if (toString(tokens[9]).length() == 0) this->EType1 = NULL;
	else this->EType1 = BaseItemType::GetByCode(toString(tokens[9]));
	if (toString(tokens[10]).length() == 0) this->EType2 = NULL;
	else this->EType2 = BaseItemType::GetByCode(toString(tokens[10]));
	if (toString(tokens[11]).length() == 0) this->EType3 = NULL;
	else this->EType3 = BaseItemType::GetByCode(toString(tokens[11]));
	this->Runes = toString(tokens[12]);
	this->Rune1 = toString(tokens[13]);
	this->Rune2 = toString(tokens[14]);
	this->Rune3 = toString(tokens[15]);
	this->Rune4 = toString(tokens[16]);
	this->Rune5 = toString(tokens[17]);
	this->Rune6 = toString(tokens[18]);
	if (toString(tokens[19]).length() == 0) this->Property1 = NULL;
	else this->Property1 = BaseProperty::GetByCode(toString(tokens[19]));
	this->Param1 = toInt(tokens[20]);
	this->Min1 = toInt(tokens[21]);
	this->Max1 = toInt(tokens[22]);
	if (toString(tokens[23]).length() == 0) this->Property2 = NULL;
	else this->Property2 = BaseProperty::GetByCode(toString(tokens[23]));
	this->Param2 = toInt(tokens[24]);
	this->Min2 = toInt(tokens[25]);
	this->Max2 = toInt(tokens[26]);
	if (toString(tokens[27]).length() == 0) this->Property3 = NULL;
	else this->Property3 = BaseProperty::GetByCode(toString(tokens[27]));
	this->Param3 = toInt(tokens[28]);
	this->Min3 = toInt(tokens[29]);
	this->Max3 = toInt(tokens[30]);
	if (toString(tokens[31]).length() == 0) this->Property4 = NULL;
	else this->Property4 = BaseProperty::GetByCode(toString(tokens[31]));
	this->Param4 = toInt(tokens[32]);
	this->Min4 = toInt(tokens[33]);
	this->Max4 = toInt(tokens[34]);
	if (toString(tokens[35]).length() == 0) this->Property5 = NULL;
	else this->Property5 = BaseProperty::GetByCode(toString(tokens[35]));
	this->Param5 = toInt(tokens[36]);
	this->Min5 = toInt(tokens[37]);
	this->Max5 = toInt(tokens[38]);
	if (toString(tokens[39]).length() == 0) this->Property6 = NULL;
	else this->Property6 = BaseProperty::GetByCode(toString(tokens[39]));
	this->Param6 = toInt(tokens[40]);
	this->Min6 = toInt(tokens[41]);
	this->Max6 = toInt(tokens[42]);
	if (toString(tokens[43]).length() == 0) this->Property7 = NULL;
	else this->Property7 = BaseProperty::GetByCode(toString(tokens[43]));
	this->Param7 = toInt(tokens[44]);
	this->Min7 = toInt(tokens[45]);
	this->Max7 = toInt(tokens[46]);

	//std::cout << line << std::endl;
}

std::string BaseRuneword::ToString()
{
	return this->Name;
}

BaseRuneword * BaseRuneword::Get(RunewordType::RunewordType type)
{
    int index = (int)type;
	if (index < 1 || index > ItemCount)
		throw "BaseRuneword Get(RunewordType type)";

	return items[index-1];
}

BaseRuneword * BaseRuneword::Get(int index)
{
	if (index < 1 || index > ItemCount)
		throw "BaseRuneword Get(int index)";

	return items[index-1];
}

BaseRuneword * BaseRuneword::Get(std::string name)
{
    return GetByName(name);
}

BaseRuneword * BaseRuneword::GetByName(std::string name)
{
    for (int i = 0; i <= ItemCount; i++)
    {
        if (items[i] == NULL)
            continue;
        if (items[i]->Name == name)
            return items[i];
    }
	throw "BaseRuneword GetByName(std::string name)";
}

void BaseRuneword::init()
{
	std::ifstream ifs("data\\BaseRuneword.csv", std::ifstream::in);

	if (!ifs)
	{
		LOG(logERROR) << "can not find data\\BaseRuneword.csv";
		exit(1);
	}

	std::string line;

	while (std::getline(ifs, line, '\n'))
	{
		items.push_back(new BaseRuneword(line));
	}

	ifs.close();
	return;
}
