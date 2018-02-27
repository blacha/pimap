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
		// LOG(logERROR) << "Could not create folder " << path;
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
	// char *foldername = argv[1];
	// int seed = atoi(argv[2]);
	// int diff = atoi(argv[3]);

	if (argc < 3)
	{
		printf("PiMap.exe <path> <seed> <difficulty> <mapid>");
		return 1;
	} else {

	}

	char *foldername = argv[1];
	int seed = atoi(argv[2]);
	int diff = atoi(argv[3]);

	Log::of.open("logs\\core.log", std::ios::app);
	// LOG(logINFO) << "Opening Folder \"" << foldername<< "\"";

	init(foldername);


	// BYTE bActLevels[] = {1, 40, 75, 103, 109, 142};
	BYTE bActLevels[] = {1, 40, 75, 103, 109, 142};


	int levelGenerated[150];
	for(int i =0; i < 150; i ++) {
		levelGenerated[i] = 0;
	}


   for(INT x = 0; x < 2; x++)
   {
      Act* pAct = D2COMMON_LoadAct(x, seed, TRUE, FALSE, diff, NULL, bActLevels[x], D2CLIENT_LoadAct_1, D2CLIENT_LoadAct_2);
      if(pAct)
      {
		  printf("Loading Act %d @ %d - seed:%08X diff:%d %\n", pAct->dwAct + 1, pAct, seed, diff);
         	//LOG(logDEBUG1) << "Loaded Act" << pAct->dwAct+1 << " pointer = " << pAct;;

         for(INT i = bActLevels[pAct->dwAct]; i < bActLevels[pAct->dwAct+1]; i++)
         {

			 if (i == 20 || i == 59 || i == 63 || i == 93 || i == 99)  {
				 continue;
			 }

            Level* pLevel = GetLevel(pAct->pMisc, i); // Loading Town Level

            if(!pLevel){
				printf("Skipping level %d\n", i); //, D2COMMON_GetLevelText(i)->szName);
				// LOG(logDEBUG1) << "Skipping level " <<  i << " " << D2COMMON_GetLevelText(i)->szName;
				continue;
			}

            // printf("Loading Level %d\n",pLevel->dwLevelNo);

            if(!pLevel->pRoom2First){
				// printf("Init Level %d\n",pLevel->dwLevelNo);
               	D2COMMON_InitLevel(pLevel);
			}

            if(!pLevel->pRoom2First){
				printf("Failed Init %d\n", i);
				continue;
			}

			// printf("Create-Directory");
			CHAR szFolderName[64] = "";
			sprintf(szFolderName, "maps/0x%08x_%d", seed, diff);
			CreateDirectory(szFolderName, NULL);
			// printf("%s - Done", szFolderName);

            CHAR szMapName[128] = "";
            sprintf(szMapName,"%s/%02x.json", szFolderName, i);

			printf("DumpMap %s\n", szMapName);
			CCollisionMap* cMap = new CCollisionMap(pAct, pLevel->dwLevelNo);
            cMap->CreateMap();
            cMap->DumpMap(szMapName);

			levelGenerated[i] = 1;
         }
      }
   }


	printf("$$DONE\n");
	ExitProcess(NULL);
	exit(0);

	// LOG(logINFO) << "Creating maps for seed:" << seed << " difficulty: " << diff;
	// // 1203530293
	// maps->setMapId(seed, diff);
	// maps->JoinAll();
	// //Sleep(500);
	// // maps->setLevel(AreaLevel::Maps1);
	// // maps->loadMap(ActLocation::Act5, AreaLevel::Maps1);
	// // maps->getMap(AreaLevel::Maps1)->DumpMap("e:\\maprender\\maps1.json");


	// CHAR szPath[128] = "";
	// sprintf_s(szPath, sizeof(szPath), "e:\\maprender\\maps\\%d_%08X", diff, seed);
	// CreateFolder(szPath);
	// // Sleep(1000);

	// // for (int i = AreaLevel::BloodMoor; i < 130; i ++) {

	// int actId = getActs(levelId);
	// CHAR szMapName[64] = "";
	// CHAR szFileName[128] = "";
	// LOG(logINFO) << "Trying to create mapId:" << levelId << " seed:" << seed << " difficulty: " << diff;
	// sprintf_s(szMapName, sizeof(szMapName), "%s", AreaLevel::toString((AreaLevel::AreaLevel) levelId));
	// sprintf_s(szFileName, sizeof(szFileName), "%s\\%02X.json", szPath, levelId);

	// maps->setLevel(levelId);
	// maps->loadMap(actId, levelId);
	// maps->JoinAll();
	// Sleep(1000);

	// maps->getMap(levelId)->DumpMap(szFileName);
	// }

	return 0;
}
