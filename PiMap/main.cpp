#include <iostream>
#include <string>
#include <ctime>
#include "Thread.h";
#include "Log.h"
#include "D2Map.h"
#include "d2data/BaseStat.h"
#include "d2data/item/BaseProperty.h"
#include "d2data/item/BaseItemType.h"
#include "d2data/item/BaseItem.h"
#include "d2data/item/ItemSet.h"
#include "d2data/item/SetItem.h"
#include "d2data/item/BaseRuneword.h"
#include "d2data/item/UniqueItem.h"
#include "Maps.h"


bool stealth;
int newServerIp;

int main(int argc, char *argv[])
{

	for (int i = 0; i < argc; ++i)
    {
        printf("argv[%d]: %s\n", i, argv[i]);
    }


	Log::of.open("logs\\core.log", std::ios::app);

	std::string foldername = "E:\\game\\Path of Diablo\\";
	init(foldername.c_str());

	Maps *maps = new Maps();;

	maps->setMapId(1203530293, 2);

	//Sleep(500);
	maps->setLevel(AreaLevel::DuranceOfHateLevel2);
	maps->loadMap(ActLocation::Act3, AreaLevel::DuranceOfHateLevel2);
	maps->getMap(AreaLevel::DuranceOfHateLevel2)->DumpMap("e:\\maprender\\durance.json");


	return 0;
}
