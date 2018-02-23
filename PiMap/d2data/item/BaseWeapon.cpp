#include "BaseWeapon.h"
#include <iostream>
#include <fstream>
#include <sstream>

int toInt(std::string string);
bool toBool(std::string string);
std::string toString(std::string string);

BaseWeapon::BaseWeapon(std::string line)
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

	this->type = (ItemType::ItemType)Index;
	this->index = Index;
	this->tableIndex = Index - BaseItem::BASE_WEAPON_START;

	this->baseType = toString(tokens[1]) == "" ? NULL : BaseItemType::GetByCode(toString(tokens[1]));
	this->baseType2 = toString(tokens[2]) == "" ? NULL : BaseItemType::GetByCode(toString(tokens[2]));

    this->code = toString(tokens[3]);
    this->id = GetIdFromCode(toString(tokens[3]));

    this->nightmareUpgrade = toString(tokens[162]) == "xxx" ? 0 : GetIdFromCode(toString(tokens[162]));
    this->hellUpgrade = toString(tokens[163]) == "xxx" ? 0 : GetIdFromCode(toString(tokens[163]));

	this->NormalID = GetIdFromCode(toString(tokens[34]));
	this->ExceptionalID = GetIdFromCode(toString(tokens[35]));
	this->EliteID = GetIdFromCode(toString(tokens[36]));

	this->name = toString(tokens[0]);

    this->alternateGfx = toString(tokens[4]);
	this->nameString = toString(tokens[5]);
	this->version = toInt(tokens[6]);
	this->compactSave = toInt(tokens[7]);
	this->rarity = toInt(tokens[8]);
	this->spawnable = toBool(tokens[9]);
	this->minDamage = toInt(tokens[10]);
	this->maxDamage = toInt(tokens[11]);
	this->OneOrTwoHanded = toBool(tokens[12]);
	this->TwoHanded = toBool(tokens[13]);
	this->TwoHandMinDamage = toInt(tokens[14]);
	this->TwoHandMaxDamage = toInt(tokens[15]);
	this->MinMisDamage = toInt(tokens[16]);
	this->MaxMisDamage = toInt(tokens[17]);
	this->Unknown = toInt(tokens[18]);
	this->RangeAdder = toInt(tokens[19]);
	this->speed = toInt(tokens[20]);
	this->StrBonus = toInt(tokens[21]);
	this->DexBonus = toInt(tokens[22]);
	this->ReqStr = toInt(tokens[23]);
	this->ReqDex = toInt(tokens[24]);
	this->Durability = toInt(tokens[25]);
	this->noDurability = toBool(tokens[26]);
	this->level = toInt(tokens[27]);
	this->levelReq = toInt(tokens[28]);
	this->cost = toInt(tokens[29]);
	this->gambleCost = toInt(tokens[30]);
	this->MagicLevel = toInt(tokens[31]);
    this->autoPrefix = toInt(tokens[32]);
    this->OpenBetaGfx = toString(tokens[33]);

	this->WeaponClass = toString(tokens[37]);
	this->TwoHandedWeaponClass = toString(tokens[38]);
	this->component = toInt(tokens[39]);
	this->HitClass = toString(tokens[40]);
	this->invWidth = toInt(tokens[41]);
	this->invHeight = toInt(tokens[42]);
    this->stackable = toBool(tokens[43]);
	this->minStack = toInt(tokens[44]);
	this->maxStack = toInt(tokens[45]);
	this->SpawnStack = toInt(tokens[46]);
	this->flippyFile = toString(tokens[47]);
	this->invFile = toString(tokens[48]);
	this->uniqueInvFile = toString(tokens[49]);
	this->SetInvFile = toString(tokens[50]);
	this->hasInv = toBool(tokens[51]);
	this->gemSockets = toInt(tokens[52]);
	this->gemApplyType = toInt(tokens[53]);
	this->Special = toString(tokens[54]);
    this->useable = toBool(tokens[55]);
	this->dropSound = toString(tokens[56]);
	this->dropSfxFrame = toInt(tokens[57]);
	this->useSound = toString(tokens[58]);
	this->unique = toBool(tokens[59]);
    this->transparent = toBool(tokens[60]);
	this->transTbl = toInt(tokens[61]);
	this->Quivered = toBool(tokens[62]);
	this->lightRadius = toInt(tokens[63]);
    this->belt = toBool(tokens[64]);
	this->quest = toInt(tokens[65]);
	this->QuestDiffCheck = toBool(tokens[66]);

	this->missileType = toInt(tokens[67]);
	this->durabilityWarning = toInt(tokens[68]);
	this->quantityWarning = toInt(tokens[69]);
	this->gemOffset = toInt(tokens[70]);
	this->bitField1 = toInt(tokens[71]);
	this->charsiMin = toInt(tokens[72]);
	this->charsiMax = toInt(tokens[73]);
	this->charsiMagicMin = toInt(tokens[74]);
	this->charsiMagicMax = toInt(tokens[75]);
	this->charsiMagicLvl = toInt(tokens[76]);
	this->gheedMin = toInt(tokens[77]);
	this->gheedMax = toInt(tokens[78]);
	this->gheedMagicMin = toInt(tokens[79]);
	this->gheedMagicMax = toInt(tokens[80]);
	this->gheedMagicLvl = toInt(tokens[81]);
	this->akaraMin = toInt(tokens[82]);
	this->akaraMax = toInt(tokens[83]);
	this->akaraMagicMin = toInt(tokens[84]);
	this->akaraMagicMax = toInt(tokens[85]);
	this->akaraMagicLvl = toInt(tokens[86]);
	this->faraMin = toInt(tokens[87]);
	this->faraMax = toInt(tokens[88]);
	this->faraMagicMin = toInt(tokens[89]);
	this->faraMagicMax = toInt(tokens[90]);
	this->faraMagicLvl = toInt(tokens[91]);
	this->lysanderMin = toInt(tokens[92]);
	this->lysanderMax = toInt(tokens[93]);
	this->lysanderMagicMin = toInt(tokens[94]);
	this->lysanderMagicMax = toInt(tokens[95]);
	this->lysanderMagicLvl = toInt(tokens[96]);
	this->drognanMin = toInt(tokens[97]);
	this->drognanMax = toInt(tokens[98]);
	this->drognanMagicMin = toInt(tokens[99]);
	this->drognanMagicMax = toInt(tokens[100]);
	this->drognanMagicLvl = toInt(tokens[101]);
	this->hraltiMin = toInt(tokens[102]);
	this->hraltiMax = toInt(tokens[103]);
	this->hraltiMagicMin = toInt(tokens[104]);
	this->hraltiMagicMax = toInt(tokens[105]);
	this->hraltiMagicLvl = toInt(tokens[106]);
	this->alkorMin = toInt(tokens[107]);
	this->alkorMax = toInt(tokens[108]);
	this->alkorMagicMin = toInt(tokens[109]);
	this->alkorMagicMax = toInt(tokens[110]);
	this->alkorMagicLvl = toInt(tokens[111]);
	this->ormusMin = toInt(tokens[112]);
	this->ormusMax = toInt(tokens[113]);
	this->ormusMagicMin = toInt(tokens[114]);
	this->ormusMagicMax = toInt(tokens[115]);
	this->ormusMagicLvl = toInt(tokens[116]);
	this->elzixMin = toInt(tokens[117]);
	this->elzixMax = toInt(tokens[118]);
	this->elzixMagicMin = toInt(tokens[119]);
	this->elzixMagicMax = toInt(tokens[120]);
	this->elzixMagicLvl = toInt(tokens[121]);
	this->ashearaMin = toInt(tokens[122]);
	this->ashearaMax = toInt(tokens[123]);
	this->ashearaMagicMin = toInt(tokens[124]);
	this->ashearaMagicMax = toInt(tokens[125]);
	this->ashearaMagicLvl = toInt(tokens[126]);
	this->cainMin = toInt(tokens[127]);
	this->cainMax = toInt(tokens[128]);
	this->cainMagicMin = toInt(tokens[129]);
	this->cainMagicMax = toInt(tokens[130]);
	this->cainMagicLvl = toInt(tokens[131]);
	this->halbuMin = toInt(tokens[132]);
	this->halbuMax = toInt(tokens[133]);
	this->halbuMagicMin = toInt(tokens[134]);
	this->halbuMagicMax = toInt(tokens[135]);
	this->halbuMagicLvl = toInt(tokens[136]);
	this->jamellaMin = toInt(tokens[137]);
	this->jamellaMax = toInt(tokens[138]);
	this->jamellaMagicMin = toInt(tokens[139]);
	this->jamellaMagicMax = toInt(tokens[140]);
	this->jamellaMagicLvl = toInt(tokens[141]);
	this->larzukMin = toInt(tokens[142]);
	this->larzukMax = toInt(tokens[143]);
	this->larzukMagicMin = toInt(tokens[144]);
	this->larzukMagicMax = toInt(tokens[145]);
	this->larzukMagicLvl = toInt(tokens[146]);
	this->drehyaMin = toInt(tokens[147]);
	this->drehyaMax = toInt(tokens[148]);
	this->drehyaMagicMin = toInt(tokens[149]);
	this->drehyaMagicMax = toInt(tokens[150]);
	this->drehyaMagicLvl = toInt(tokens[151]);
	this->malahMin = toInt(tokens[152]);
	this->malahMax = toInt(tokens[153]);
	this->malahMagicMin = toInt(tokens[154]);
	this->malahMagicMax = toInt(tokens[155]);
	this->malahMagicLvl = toInt(tokens[156]);
	this->sourceArt = toInt(tokens[157]);
	this->gameArt = toInt(tokens[158]);
	this->transform = toInt(tokens[159]);
	this->invTrans = toInt(tokens[160]);
	this->skipName = toInt(tokens[161]);

	this->nameable = toBool(tokens[164]);
	this->PermStoreItem = toBool(tokens[165]);

	//std::cout << line << std::endl;
}
