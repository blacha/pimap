#include "BaseMiscItem.h"
#include <iostream>
#include <fstream>
#include <sstream>

int toInt(std::string string);
bool toBool(std::string string);
std::string toString(std::string string);

BaseMiscItem::BaseMiscItem(std::string line)
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
	this->tableIndex = Index;

	this->baseType = toString(tokens[33]) == "" ? NULL : BaseItemType::GetByCode(toString(tokens[33]));
	this->baseType2 = toString(tokens[34]) == "" ? NULL : BaseItemType::GetByCode(toString(tokens[34]));

    this->code = toString(tokens[14]);
    this->id = GetIdFromCode(toString(tokens[14]));

    this->nightmareUpgrade = toString(tokens[161]) == "xxx" ? 0 : GetIdFromCode(toString(tokens[161]));
    this->hellUpgrade = toString(tokens[162]) == "xxx" ? 0 : GetIdFromCode(toString(tokens[162]));

	this->name = toString(tokens[0]);
	this->Name2 = toString(tokens[1]);
	this->SzFlavorText = toInt(tokens[2]);
	this->compactSave = toInt(tokens[3]);
	this->version = toInt(tokens[4]);
	this->level = toInt(tokens[5]);
	this->levelReq = toInt(tokens[6]);
	this->rarity = toInt(tokens[7]);
    this->spawnable = toBool(tokens[8]);
	this->speed = toInt(tokens[9]);
    this->noDurability = toBool(tokens[10]);
	this->cost = toInt(tokens[11]);
	this->gambleCost = toInt(tokens[12]);
	this->autoPrefix = toInt(tokens[13]);

	this->alternateGfx = toString(tokens[15]);
	this->nameString = toString(tokens[16]);
	this->component = toInt(tokens[17]);
	this->invWidth = toInt(tokens[18]);
	this->invHeight = toInt(tokens[19]);
    this->hasInv = toBool(tokens[20]);
	this->gemSockets = toInt(tokens[21]);
	this->gemApplyType = toInt(tokens[22]);
	this->flippyFile = toString(tokens[23]);
	this->invFile = toString(tokens[24]);
	this->uniqueInvFile = toString(tokens[25]);
	this->Special = toString(tokens[26]);
	this->Transmogrify = toBool(tokens[27]);
	this->TMogType = toString(tokens[28]);
	this->TMogMin = toInt(tokens[29]);
	this->TMogMax = toInt(tokens[30]);
    this->useable = toBool(tokens[31]);
	this->Throwable = toBool(tokens[32]);

	this->dropSound = toString(tokens[35]);
	this->dropSfxFrame = toInt(tokens[36]);
	this->useSound = toString(tokens[37]);
    this->unique = toBool(tokens[38]);
    this->transparent = toBool(tokens[39]);
	this->transTbl = toInt(tokens[40]);
	this->lightRadius = toInt(tokens[41]);
    this->belt = toBool(tokens[42]);
	this->AutoBelt = toBool(tokens[43]);
	this->stackable = toBool(tokens[44]);
	this->minStack = toInt(tokens[45]);
	this->maxStack = toInt(tokens[46]);
	this->SpawnStack = toInt(tokens[47]);
	this->quest = toInt(tokens[48]);
	this->QuestDiffCheck = toBool(tokens[49]);
	this->missileType = toInt(tokens[50]);
	this->SpellIcon = toInt(tokens[51]);
	this->pSpell = toInt(tokens[52]);
	this->State = (StateType::StateType) toInt(tokens[53]);
	this->CState1 = (StateType::StateType) toInt(tokens[54]);
	this->CState2 = (StateType::StateType) toInt(tokens[55]);
	this->Len = toInt(tokens[56]);
	this->Stat1 = (StatType::StatType) toInt(tokens[57]);
	this->Calc1 = toInt(tokens[58]);
	this->Stat2 = (StatType::StatType) toInt(tokens[59]);
	this->Calc2 = toInt(tokens[60]);
	this->Stat3 = (StatType::StatType) toInt(tokens[61]);
	this->Calc3 = toInt(tokens[62]);
	this->SpellDesc = toInt(tokens[63]);
	this->SpellDescStr = toString(tokens[64]);
	this->SpellDescCalc = toInt(tokens[65]);
	this->durabilityWarning = toInt(tokens[66]);
	this->quantityWarning = toInt(tokens[67]);
	this->gemOffset = toInt(tokens[68]);
	this->BetterGem = (ItemType::ItemType) toInt(tokens[69]);
	this->bitField1 = toInt(tokens[70]);
	this->charsiMin = toInt(tokens[71]);
	this->charsiMax = toInt(tokens[72]);
	this->charsiMagicMin = toInt(tokens[73]);
	this->charsiMagicMax = toInt(tokens[74]);
	this->charsiMagicLvl = toInt(tokens[75]);
	this->gheedMin = toInt(tokens[76]);
	this->gheedMax = toInt(tokens[77]);
	this->gheedMagicMin = toInt(tokens[78]);
	this->gheedMagicMax = toInt(tokens[79]);
	this->gheedMagicLvl = toInt(tokens[80]);
	this->akaraMin = toInt(tokens[81]);
	this->akaraMax = toInt(tokens[82]);
	this->akaraMagicMin = toInt(tokens[83]);
	this->akaraMagicMax = toInt(tokens[84]);
	this->akaraMagicLvl = toInt(tokens[85]);
	this->faraMin = toInt(tokens[86]);
	this->faraMax = toInt(tokens[87]);
	this->faraMagicMin = toInt(tokens[88]);
	this->faraMagicMax = toInt(tokens[89]);
	this->faraMagicLvl = toInt(tokens[90]);
	this->lysanderMin = toInt(tokens[91]);
	this->lysanderMax = toInt(tokens[92]);
	this->lysanderMagicMin = toInt(tokens[93]);
	this->lysanderMagicMax = toInt(tokens[94]);
	this->lysanderMagicLvl = toInt(tokens[95]);
	this->drognanMin = toInt(tokens[96]);
	this->drognanMax = toInt(tokens[97]);
	this->drognanMagicMin = toInt(tokens[98]);
	this->drognanMagicMax = toInt(tokens[99]);
	this->drognanMagicLvl = toInt(tokens[100]);
	this->hraltiMin = toInt(tokens[101]);
	this->hraltiMax = toInt(tokens[102]);
	this->hraltiMagicMin = toInt(tokens[103]);
	this->hraltiMagicMax = toInt(tokens[104]);
	this->hraltiMagicLvl = toInt(tokens[105]);
	this->alkorMin = toInt(tokens[106]);
	this->alkorMax = toInt(tokens[107]);
	this->alkorMagicMin = toInt(tokens[108]);
	this->alkorMagicMax = toInt(tokens[109]);
	this->alkorMagicLvl = toInt(tokens[110]);
	this->ormusMin = toInt(tokens[111]);
	this->ormusMax = toInt(tokens[112]);
	this->ormusMagicMin = toInt(tokens[113]);
	this->ormusMagicMax = toInt(tokens[114]);
	this->ormusMagicLvl = toInt(tokens[115]);
	this->elzixMin = toInt(tokens[116]);
	this->elzixMax = toInt(tokens[117]);
	this->elzixMagicMin = toInt(tokens[118]);
	this->elzixMagicMax = toInt(tokens[119]);
	this->elzixMagicLvl = toInt(tokens[120]);
	this->ashearaMin = toInt(tokens[121]);
	this->ashearaMax = toInt(tokens[122]);
	this->ashearaMagicMin = toInt(tokens[123]);
	this->ashearaMagicMax = toInt(tokens[124]);
	this->ashearaMagicLvl = toInt(tokens[125]);
	this->cainMin = toInt(tokens[126]);
	this->cainMax = toInt(tokens[127]);
	this->cainMagicMin = toInt(tokens[128]);
	this->cainMagicMax = toInt(tokens[129]);
	this->cainMagicLvl = toInt(tokens[130]);
	this->halbuMin = toInt(tokens[131]);
	this->halbuMax = toInt(tokens[132]);
	this->halbuMagicMin = toInt(tokens[133]);
	this->halbuMagicMax = toInt(tokens[134]);
	this->halbuMagicLvl = toInt(tokens[135]);
	this->jamellaMin = toInt(tokens[136]);
	this->jamellaMax = toInt(tokens[137]);
	this->jamellaMagicMin = toInt(tokens[138]);
	this->jamellaMagicMax = toInt(tokens[139]);
	this->jamellaMagicLvl = toInt(tokens[140]);
	this->larzukMin = toInt(tokens[141]);
	this->larzukMax = toInt(tokens[142]);
	this->larzukMagicMin = toInt(tokens[143]);
	this->larzukMagicMax = toInt(tokens[144]);
	this->larzukMagicLvl = toInt(tokens[145]);
	this->malahMin = toInt(tokens[146]);
	this->malahMax = toInt(tokens[147]);
	this->malahMagicMin = toInt(tokens[148]);
	this->malahMagicMax = toInt(tokens[149]);
	this->malahMagicLvl = toInt(tokens[150]);
	this->drehyaMin = toInt(tokens[151]);
	this->drehyaMax = toInt(tokens[152]);
	this->drehyaMagicMin = toInt(tokens[153]);
	this->drehyaMagicMax = toInt(tokens[154]);
	this->drehyaMagicLvl = toInt(tokens[155]);
	this->sourceArt = toInt(tokens[156]);
	this->gameArt = toInt(tokens[157]);
	this->transform = toInt(tokens[158]);
	this->invTrans = toInt(tokens[159]);
	this->skipName = toInt(tokens[160]);

	this->minDamage = toInt(tokens[163]);
	this->maxDamage = toInt(tokens[164]);
	this->PermStoreItem = toBool(tokens[165]);
	this->MultiBuy = toBool(tokens[166]);
    this->nameable = toBool(tokens[167]);

	//std::cout << line << std::endl;
}
