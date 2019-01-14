#include "d2_client.h"
#include "d2_structs.h"
#include "d2_ptrs.h"
#include <iostream>
#include "json.h"

#define INPUT_BUFFER 1024

const char COMMAND_EXIT[] = "$EXIT";
const char COMMAND_MAP[] = "$MAP";
const char COMMAND_DIFF[] = "$DIFF";
const char COMMAND_SEED[] = "$SEED";

bool starts_with(const char *prefix, const char *search_string)
{
    if (strncmp(prefix, search_string, strlen(search_string)) == 0)
    {
        return 1;
    }
    return 0;
}

void dump_all_maps(int seed, int difficulty)
{
    BYTE bActLevels[] = {1, 40, 75, 103, 109, 142};

    // // // 138
    // int act = 1;
    // Act *pAct = D2COMMON_LoadAct(act, seed, TRUE, FALSE, difficulty, (DWORD)NULL, bActLevels[act], D2CLIENT_LoadAct_1, D2CLIENT_LoadAct_2);
    // dump_map(pAct, 32);
    // return;

    for (INT x = 0; x < 5; x++)
    {
        Act *pAct = D2COMMON_LoadAct(x, seed, TRUE, FALSE, difficulty, (DWORD)NULL, bActLevels[x], D2CLIENT_LoadAct_1, D2CLIENT_LoadAct_2);
        if (pAct)
        {
            // printf("Loading Act %d [%d -> %d] \n", pAct->dwAct + 1, bActLevels[pAct->dwAct], bActLevels[pAct->dwAct + 1]);
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

int main(int argc, char *argv[])
{

    if (argc < 1)
    {
        printf("pimap.exe <D2 Game Path>");
        return 1;
    }

    /** Init the D2 client using the provided path */
    char *foldername = argv[1];
    d2_game_init(foldername);
    printf("{\"message\": \"InitDone\"}\n");

    /** Seed/Diff has been passed in just generate the map that is required */
    if (argc > 2)
    {
        int arg_seed = atoi(argv[2]);
        int arg_diff = atoi(argv[3]);
        json_start();
        json_key_value("seed", arg_seed);
        json_key_value("diff", arg_diff);
        json_end();

        dump_all_maps(arg_seed, arg_diff);
        return 0;
    }

    char buffer[INPUT_BUFFER];

    int seed;
    int difficulty;
    int rtn;
    char c[INPUT_BUFFER];
    /** Read in seed/Difficulty then generate all the maps */
    while (fgets(buffer, INPUT_BUFFER, stdin) != NULL)
    {
        if (starts_with(buffer, COMMAND_EXIT) == 1)
        {
            return 0;
        }
        else if (starts_with(buffer, COMMAND_MAP) == 1)
        {
            dump_all_maps(seed, difficulty);
            printf("{\"message\": \"DONE\"}\n");
        }
        else if (starts_with(buffer, COMMAND_SEED) == 1)
        {
            rtn = sscanf(buffer, "%s %d", &c, &seed);
            printf("{\"seed\": %d, \"difficulty\": %d}\n", seed, difficulty);
        }
        else if (starts_with(buffer, COMMAND_DIFF) == 1)
        {
            rtn = sscanf(buffer, "%s %d", &c, &difficulty);
            printf("{\"seed\": %d, \"difficulty\": %d}\n", seed, difficulty);
        }
    }
    return 0;
}
