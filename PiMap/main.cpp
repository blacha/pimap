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

int getActs(AreaLevel::AreaLevel level)
{
	char bActLevels[] = {1, 40, 75, 103, 109, 137};

	for (int i = 0; i < 5; i++)
	{
		if (level < bActLevels[i + 1])
		{
			return i;
		}
	}

	return 0;
}

int main(int argc, char *argv[])
{

	if (argc < 3)
	{
		printf("PiMap.exe <path> <seed> <difficulty> <mapid>");
		return 1;
	}

	char *foldername = argv[1];
	int seed = atoi(argv[2]);
	int diff = atoi(argv[3]);
	int mapid = atoi(argv[4]);
	AreaLevel::AreaLevel levelId = static_cast<AreaLevel::AreaLevel>(mapid);

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

	// for (int i = AreaLevel::BloodMoor; i < 130; i ++) {

	int actId = getActs(levelId);
	CHAR szMapName[64] = "";
	CHAR szFileName[128] = "";
	LOG(logINFO) << "Trying to create mapId:" << levelId << " seed:" << seed << " difficulty: " << diff;
	sprintf_s(szMapName, sizeof(szMapName), "%s", D2COMMON_GetLevelText(levelId)->szName);
	sprintf_s(szFileName, sizeof(szFileName), "%s\\%X.json", szPath, levelId);

	maps->setLevel(levelId);
	maps->loadMap(actId, levelId);
	maps->getMap(levelId)->DumpMap(szFileName);
	// }

	return 0;
}
