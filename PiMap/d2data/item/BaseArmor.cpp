#include "BaseArmor.h"
#include <iostream>
#include <fstream>
#include <sstream>

int toInt(std::string string);
bool toBool(std::string string);
std::string toString(std::string string);

BaseArmor::BaseArmor(std::string line)
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

	int Index = BaseItem::ItemCount++;

	this->type = (ItemType::ItemType) Index;
	this->index = Index;
	this->tableIndex = Index - BaseItem::BASE_ARMOR_START;

	this->baseType = toString(tokens[48]) == "" ? NULL : BaseItemType::GetByCode(toString(tokens[48]));
	this->baseType2 = toString(tokens[49]) == "" ? NULL : BaseItemType::GetByCode(toString(tokens[49]));

    this->code = toString(tokens[17]);
    this->id = GetIdFromCode(toString(tokens[17]));

    this->nightmareUpgrade = toString(tokens[159]) == "xxx" ? 0 : GetIdFromCode(toString(tokens[159]));
    this->hellUpgrade = toString(tokens[160]) == "xxx" ? 0 : GetIdFromCode(toString(tokens[160]));

	this->NormalID = GetIdFromCode(toString(tokens[23]));
	this->ExceptionalID = GetIdFromCode(toString(tokens[24]));
	this->EliteID = GetIdFromCode(toString(tokens[25]));

	this->name = toString(tokens[0]);
	this->version = toInt(tokens[1]);
	this->compactSave = toInt(tokens[2]);
	this->rarity = toInt(tokens[3]);
    this->spawnable = toBool(tokens[4]);
	this->MinAc = toInt(tokens[5]);
	this->MaxAc = toInt(tokens[6]);
	this->Absorbs = toInt(tokens[7]);
	this->speed = toInt(tokens[8]);
	this->ReqStr = toInt(tokens[9]);
	this->Block = toInt(tokens[10]);
	this->Durability = toInt(tokens[11]);
    this->noDurability = toBool(tokens[12]);
	this->level = toInt(tokens[13]);
	this->levelReq = toInt(tokens[14]);
	this->cost = toInt(tokens[15]);
	this->gambleCost = toInt(tokens[16]);

	this->nameString = toString(tokens[18]);
	this->MagicLevel = toInt(tokens[19]);
	this->autoPrefix = toInt(tokens[20]);
    this->alternateGfx = toString(tokens[21]);
    this->OpenBetaGfx = toString(tokens[22]);

	this->SpellOffset = toInt(tokens[26]);
	this->component = toInt(tokens[27]);
	this->invWidth = toInt(tokens[28]);
	this->invHeight = toInt(tokens[29]);
    this->hasInv = toBool(tokens[30]);
	this->gemSockets = toInt(tokens[31]);
	this->gemApplyType = toInt(tokens[32]);
	this->flippyFile = toString(tokens[33]);
	this->invFile = toString(tokens[34]);
	this->uniqueInvFile = toString(tokens[35]);
	this->SetInvFile = toString(tokens[36]);
	this->lArm = toInt(tokens[37]);
	this->rArm = toInt(tokens[38]);
	this->Torso = toInt(tokens[39]);
	this->Legs = toInt(tokens[40]);
	this->rSPad = toInt(tokens[41]);
	this->lSPad = toInt(tokens[42]);
    this->useable = toBool(tokens[43]);
	this->Throwable = toBool(tokens[44]);
    this->stackable = toBool(tokens[45]);
	this->minStack = toInt(tokens[46]);
	this->maxStack = toInt(tokens[47]);

	this->dropSound = toString(tokens[50]);
	this->dropSfxFrame = toInt(tokens[51]);
	this->useSound = toString(tokens[52]);
    this->unique = toBool(tokens[53]);
    this->transparent = toBool(tokens[54]);
	this->transTbl = toInt(tokens[55]);
	this->Quivered = toBool(tokens[56]);
	this->lightRadius = toInt(tokens[57]);
    this->belt = toBool(tokens[58]);
	this->quest = toInt(tokens[59]);
	this->missileType = toInt(tokens[60]);
	this->durabilityWarning = toInt(tokens[61]);
	this->quantityWarning = toInt(tokens[62]);
	this->minDamage = toInt(tokens[63]);
	this->maxDamage = toInt(tokens[64]);
	this->StrBonus = toInt(tokens[65]);
	this->DexBonus = toInt(tokens[66]);
	this->gemOffset = toInt(tokens[67]);
	this->bitField1 = toInt(tokens[68]);
	this->charsiMin = toInt(tokens[69]);
	this->charsiMax = toInt(tokens[70]);
	this->charsiMagicMin = toInt(tokens[71]);
	this->charsiMagicMax = toInt(tokens[72]);
	this->charsiMagicLvl = toInt(tokens[73]);
	this->gheedMin = toInt(tokens[74]);
	this->gheedMax = toInt(tokens[75]);
	this->gheedMagicMin = toInt(tokens[76]);
	this->gheedMagicMax = toInt(tokens[77]);
	this->gheedMagicLvl = toInt(tokens[78]);
	this->akaraMin = toInt(tokens[79]);
	this->akaraMax = toInt(tokens[80]);
	this->akaraMagicMin = toInt(tokens[81]);
	this->akaraMagicMax = toInt(tokens[82]);
	this->akaraMagicLvl = toInt(tokens[83]);
	this->faraMin = toInt(tokens[84]);
	this->faraMax = toInt(tokens[85]);
	this->faraMagicMin = toInt(tokens[86]);
	this->faraMagicMax = toInt(tokens[87]);
	this->faraMagicLvl = toInt(tokens[88]);
	this->lysanderMin = toInt(tokens[89]);
	this->lysanderMax = toInt(tokens[90]);
	this->lysanderMagicMin = toInt(tokens[91]);
	this->lysanderMagicMax = toInt(tokens[92]);
	this->lysanderMagicLvl = toInt(tokens[93]);
	this->drognanMin = toInt(tokens[94]);
	this->drognanMax = toInt(tokens[95]);
	this->drognanMagicMin = toInt(tokens[96]);
	this->drognanMagicMax = toInt(tokens[97]);
	this->drognanMagicLvl = toInt(tokens[98]);
	this->hraltiMin = toInt(tokens[99]);
	this->hraltiMax = toInt(tokens[100]);
	this->hraltiMagicMin = toInt(tokens[101]);
	this->hraltiMagicMax = toInt(tokens[102]);
	this->hraltiMagicLvl = toInt(tokens[103]);
	this->alkorMin = toInt(tokens[104]);
	this->alkorMax = toInt(tokens[105]);
	this->alkorMagicMin = toInt(tokens[106]);
	this->alkorMagicMax = toInt(tokens[107]);
	this->alkorMagicLvl = toInt(tokens[108]);
	this->ormusMin = toInt(tokens[109]);
	this->ormusMax = toInt(tokens[110]);
	this->ormusMagicMin = toInt(tokens[111]);
	this->ormusMagicMax = toInt(tokens[112]);
	this->ormusMagicLvl = toInt(tokens[113]);
	this->elzixMin = toInt(tokens[114]);
	this->elzixMax = toInt(tokens[115]);
	this->elzixMagicMin = toInt(tokens[116]);
	this->elzixMagicMax = toInt(tokens[117]);
	this->elzixMagicLvl = toInt(tokens[118]);
	this->ashearaMin = toInt(tokens[119]);
	this->ashearaMax = toInt(tokens[120]);
	this->ashearaMagicMin = toInt(tokens[121]);
	this->ashearaMagicMax = toInt(tokens[122]);
	this->ashearaMagicLvl = toInt(tokens[123]);
	this->cainMin = toInt(tokens[124]);
	this->cainMax = toInt(tokens[125]);
	this->cainMagicMin = toInt(tokens[126]);
	this->cainMagicMax = toInt(tokens[127]);
	this->cainMagicLvl = toInt(tokens[128]);
	this->halbuMin = toInt(tokens[129]);
	this->halbuMax = toInt(tokens[130]);
	this->halbuMagicMin = toInt(tokens[131]);
	this->halbuMagicMax = toInt(tokens[132]);
	this->halbuMagicLvl = toInt(tokens[133]);
	this->jamellaMin = toInt(tokens[134]);
	this->jamellaMax = toInt(tokens[135]);
	this->jamellaMagicMin = toInt(tokens[136]);
	this->jamellaMagicMax = toInt(tokens[137]);
	this->jamellaMagicLvl = toInt(tokens[138]);
	this->larzukMin = toInt(tokens[139]);
	this->larzukMax = toInt(tokens[140]);
	this->larzukMagicMin = toInt(tokens[141]);
	this->larzukMagicMax = toInt(tokens[142]);
	this->larzukMagicLvl = toInt(tokens[143]);
	this->malahMin = toInt(tokens[144]);
	this->malahMax = toInt(tokens[145]);
	this->malahMagicMin = toInt(tokens[146]);
	this->malahMagicMax = toInt(tokens[147]);
	this->malahMagicLvl = toInt(tokens[148]);
	this->drehyaMin = toInt(tokens[149]);
	this->drehyaMax = toInt(tokens[150]);
	this->drehyaMagicMin = toInt(tokens[151]);
	this->drehyaMagicMax = toInt(tokens[152]);
	this->drehyaMagicLvl = toInt(tokens[153]);
	this->sourceArt = toInt(tokens[154]);
	this->gameArt = toInt(tokens[155]);
	this->transform = toInt(tokens[156]);
	this->invTrans = toInt(tokens[157]);
	this->skipName = toInt(tokens[158]);

	this->minDamage = toInt(tokens[161]);
	this->maxDamage = toInt(tokens[162]);
    this->nameable = toBool(tokens[163]);

	//std::cout << line << std::endl;
}
