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

void CreateFolder(const char * path)
{
    if(!CreateDirectory(path ,NULL))
    {
		LOG(logERROR) << "Could not create folder " << path;
        return;
    }
	LOG(logINFO) << "Create folder " << path;

}

int main(int argc, char *argv[])
{

	if (argc < 3)
	{
		printf("PiMap.exe <path> <seed> <difficulty>");
		return 1;
	}

	char *foldername = argv[1];
	int seed = atoi(argv[2]);
	int diff = atoi(argv[3]);

	Log::of.open("logs\\core.log", std::ios::app);
	LOG(logINFO) << "Opening Folder \"" << foldername<< "\"";

	init(foldername);

	Maps *maps = new Maps();

	LOG(logINFO) << "Creating maps for seed:" << seed << " difficulty: " << diff;
	// 1203530293
	maps->setMapId(seed, diff);

	//Sleep(500);
	// maps->setLevel(AreaLevel::Maps1);
	// maps->loadMap(ActLocation::Act5, AreaLevel::Maps1);
	// maps->getMap(AreaLevel::Maps1)->DumpMap("e:\\maprender\\maps1.json");


	CHAR szPath[128] = "";
	sprintf_s(szPath, sizeof(szPath), "e:\\maprender\\maps\\%d_%X", diff, seed);
	CreateFolder(szPath);

	for (int i = 1; i < 130; i ++) {
			AreaLevel::AreaLevel leveId = static_cast<AreaLevel::AreaLevel>(i);
			CHAR szMapName[64] = "";
			CHAR szFileName[128] = "";
			LOG(logINFO) << "Trying to create mapId:" << i << " seed:" << seed << " difficulty: " << diff;
			sprintf_s(szMapName, sizeof(szMapName), "%s", D2COMMON_GetLevelText(i)->szName);
			sprintf_s(szFileName, sizeof(szFileName), "%s\\%X.json", szPath, i);

			maps->setLevel(leveId);
			maps->loadMap(ActLocation::Act5, leveId);
			maps->getMap(leveId)->DumpMap(szFileName);
	}

	return 0;
}
