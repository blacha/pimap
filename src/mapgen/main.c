#include "D2.h"
#include "D2Structs.h"
#include "D2Ptrs.h"

#include <iostream>

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
    D2GameInit(foldername);
    printf("InitDone...\n");
    BYTE bActLevels[] = {1, 40, 75, 103, 109, 142};

    for (INT x = 0; x < 5; x++)
    {
        Act *pAct = D2COMMON_LoadAct(x, seed, TRUE, FALSE, diff, NULL, bActLevels[x], D2CLIENT_LoadAct_1, D2CLIENT_LoadAct_2);
        printf("LoadingAct 0x%08x_%d \n", seed, diff);
        if (pAct)
        {
            printf("Loading Act %d @%d \n", pAct->dwAct + 1, pAct);
            // LOG(logDEBUG1) << "Loaded Act" << pAct->dwAct + 1 << " pointer = " << pAct;

            for (INT i = bActLevels[pAct->dwAct]; i < bActLevels[pAct->dwAct + 1]; i++)
            {
                if (i == 20 || i == 59 || i == 63 || i == 93 || i == 99)
                {
                    continue;
                }

                Level *pLevel = GetLevel(pAct->pMisc, i); // Loading Town Level

                if (!pLevel)
                {
                    printf("Skipping level %d\n", i, D2COMMON_GetLevelText(i)->szName);
                    continue;
                }

                if (!pLevel->pRoom2First)
                {
                    printf("Init Level %d\n", pLevel->dwLevelNo);
                    // D2COMMON_InitLevel(pLevel);
                }

                if (!pLevel->pRoom2First)
                {
                    printf("Failed Init %d\n", i);
                    continue;
                }

                printf("MakeFolders");
                CHAR szFolder[32] = "";
                sprintf(szFolder, "maps/0x%08x_%d", seed, diff);

                CHAR szMapName[64] = "";
                sprintf(szMapName, "%s/0x%02x.json", szFolder, i);
                printf("DumpMap %s\n", szMapName);
                //     CCollisionMap *cMap = new CCollisionMap(pAct, pLevel->dwLevelNo);
                //     cMap->CreateMap();
                //     cMap->DumpMap(szMapName);

                //     levelGenerated[i] = 1;
            }
        }
    }
}
