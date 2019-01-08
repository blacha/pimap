#include "d2_client.h"
#include "d2_structs.h"
#include "d2_ptrs.h"

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
    d2_game_init(foldername);
    printf("InitDone...\n");
    BYTE bActLevels[] = {1, 40, 75, 103, 109, 142};

    // // 138
    // Act *pAct = D2COMMON_LoadAct(5, seed, TRUE, FALSE, diff, (DWORD)NULL, bActLevels[5], D2CLIENT_LoadAct_1, D2CLIENT_LoadAct_2);
    // dump_map(pAct, 138);
    // return 0;

    for (INT x = 0; x < 5; x++)
    {
        Act *pAct = D2COMMON_LoadAct(x, seed, TRUE, FALSE, diff, (DWORD)NULL, bActLevels[x], D2CLIENT_LoadAct_1, D2CLIENT_LoadAct_2);
        if (pAct)
        {
            printf("Loading Act %d [%d -> %d] \n", pAct->dwAct + 1, bActLevels[pAct->dwAct], bActLevels[pAct->dwAct + 1]);
            // LOG(logDEBUG1) << "Loaded Act" << pAct->dwAct + 1 << " pointer = " << pAct;

            for (INT levelCode = bActLevels[pAct->dwAct]; levelCode < bActLevels[pAct->dwAct + 1]; levelCode++)
            {
                if (levelCode == 20 || levelCode == 59 || levelCode == 63 || levelCode == 93 || levelCode == 99)
                {
                    continue;
                }

                dump_map(pAct, levelCode);
            }
        }
    }
}
