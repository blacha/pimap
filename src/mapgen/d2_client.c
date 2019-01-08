
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <fstream>
#include <string>
#include "d2_structs.h"
#include "d2_ptrs.h"
#include "offset.h"
#include "d2data/d2_area_level.h"
#include "d2data/d2_game_object.h"
#include "d2data/d2_npc_type.h"
#include "map.h"
#include "json.h"

#define MAP_DATA_INVALID -1      // Invalid
#define MAP_DATA_CLEANED 11110   // Cleaned for start/end positions
#define MAP_DATA_FILLED 11111    // Filled gaps
#define MAP_DATA_THICKENED 11113 // Wall thickened
#define MAP_DATA_AVOID 11115     // Should be avoided

#define UNIT_TYPE_PLAYER 0
#define UNIT_TYPE_NPC 1
#define UNIT_TYPE_OBJECT 2
#define UNIT_TYPE_MISSILE 3
#define UNIT_TYPE_ITEM 4
#define UNIT_TYPE_TILE 5

d2client_struct D2Client;
char D2_DIR[MAX_PATH] = "game/Path of Diablo";

DWORD D2ClientInterface(VOID)
{
    return D2Client.dwInit;
}

VOID __stdcall ExceptionHandler(VOID)
{
    printf("\n] We got a big Error here! [\n");
    ExitProcess(0);
}

/** If this value changes, update __asm JMP */
int D2CLIENT_InitGameMisc_I_P = 0x6faf559b;
void /* __declspec(naked) */ D2CLIENT_InitGameMisc()
{
    __asm(
        "MOVL %EBP, %ESP\n"
        "POPL %EBP\n"
        ".intel_syntax noprefix\n"
        "PUSH ECX\n"
        "PUSH EBP\n"
        "PUSH ESI\n"
        "PUSH EDI\n"
        ".att_syntax prefix\n"
        "JMP 0x6faf559b\n" // Magic Jump
        "PUSHL %EBP\n");
}

CHAR *DIABLO_2 = (CHAR *)"Diablo II";
CHAR *DIABLO_2_VERSION = (CHAR *)"v1.xy";

int d2_game_init(char *folderName)
{

    printf("InitGame %s\n", folderName);
    sprintf_s(D2_DIR, sizeof(D2_DIR), "%s\\", folderName);

    char GAME[MAX_PATH] = "";
    sprintf_s(GAME, sizeof(GAME), "%s\\game.exe", folderName);
    std::ifstream ifs(GAME, std::ifstream::in);
    if (!ifs)
    {
        printf("Cannot find Game.exe in '%s'\n", folderName);
        exit(1);
    }
    ifs.close();

    CHAR szPath[MAX_PATH] = {0};
    GetCurrentDirectory(MAX_PATH, szPath);

    printf("SetDir, %s \n", D2_DIR);
    SetCurrentDirectory("game/Path of Diablo");
    memset(&D2Client, (DWORD)NULL, sizeof(d2client_struct));

    DefineOffsets();
    // printf("Offsets defined.\n");
    DWORD dwFogBase = (DWORD)GetModuleHandle("FOG.dll") + 0x2505C;           //updated 1.13d
    DWORD dwStormBase = (DWORD)GetModuleHandle("Storm.dll") + 0x43230;       //updated 1.13d
    DWORD dwD2ClientBase = (DWORD)GetModuleHandle("D2CLIENT.dll") + 0xCFFA4; //updated 1.13d
    DWORD dwD2Common = (DWORD)GetModuleHandle("D2COMMON.dll") + 0x8D11C;     //updated 1.13d

    DWORD dwOld;
    *p_STORM_MPQHashTable = (DWORD)NULL;

    D2Client.dwInit = 1;
    D2Client.fpInit = (DWORD)D2ClientInterface;

    printf("FOG_10021 - ");
    FOG_10021(DIABLO_2);
    printf("Done\n");

    printf("FOG_10019 - ");
    FOG_10019(DIABLO_2, (DWORD)ExceptionHandler, DIABLO_2_VERSION, 1);
    printf("Done\n");

    printf("FOG_10101 - ");
    FOG_10101(1, 0);
    printf("Done\n");

    printf("FOG_10089 - ");
    FOG_10089(1);
    printf("Done\n");

    printf("FOG_10218 - ");
    DWORD fog10218 = FOG_10218();
    printf("Done (%d)\n", fog10218);

    if (!fog10218)
    {
        printf("Unable to load FOG_10218\n");
        return 1;
    }

    printf("D2WIN_10174 - ");
    DWORD win10174 = D2WIN_10174();
    if (!win10174)
    {
        printf("Unable to load MPQ Files\n");
        return 1;
    }
    printf("Done (%d)\n", win10174);

    printf("D2WIN_10072 - ");
    DWORD win10072 = D2WIN_10072((DWORD)NULL, (DWORD)NULL, (DWORD)NULL, &D2Client);
    printf("Done (%d)\n", win10072);
    if (!win10072)
    {
        printf("Unable to load MPQ Files\n");
        return 1;
    }

    printf("D2LANG_10009 - ");
    D2LANG_10009(0, (CHAR *)"ENG", 0);
    printf("Done\n");

    printf("D2COMMON_InitDataTables - ");
    DWORD initDataTables = D2COMMON_InitDataTables(0, 0, 0);
    printf("Done (%d)\n", initDataTables);
    if (!initDataTables)
    {
        printf("Unable to init datatables");
        return 1;
    }

    if ((int)D2CLIENT_InitGameMisc_I != D2CLIENT_InitGameMisc_I_P)
    {
        printf("D2Client_InitGameMisc has changed to 0x%x\n", D2CLIENT_InitGameMisc_I);
        exit(1);
    }

    printf("D2CLIENT_InitGameMisc - Jump: (0x%x) ", D2CLIENT_InitGameMisc_I);
    D2CLIENT_InitGameMisc();
    printf("Done\n");

    SetCurrentDirectory(folderName);
    return 0;
}

Level *__fastcall d2_get_level(ActMisc *misc, DWORD levelno)
{

    for (Level *pLevel = misc->pLevelFirst; pLevel; pLevel = pLevel->pNextLevel)
    {
        if (!pLevel)
            continue;

        if (pLevel->dwLevelNo == levelno)
        {
            return pLevel;
        }
    }
    printf("D2COMMON_GetLevel %d - %s\n", levelno, D2COMMON_GetLevelText(levelno)->szName);
    return D2COMMON_GetLevel(misc, levelno);
}

void add_collision_data(CollMap *pCol, int originX, int originY)
{
    if (pCol == NULL)
        return;

    int x = pCol->dwPosGameX - originX;
    int y = pCol->dwPosGameY - originY;
    int cx = pCol->dwSizeGameX;
    int cy = pCol->dwSizeGameY;

    int nLimitX = x + cx;
    int nLimitY = y + cy;

    WORD *p = pCol->pMapStart;
    for (int j = y; j < nLimitY; j++)
    {
        for (int i = x; i < nLimitX; i++)
        {
            int pVal = *p;
            if (pVal == 1024)
            {
                pVal = 1;
            }
            map_set(i, j, pVal);
            p++;
        }
    }
}

char *get_object_type(int code)
{
    if (isWaypoint(code))
    {
        return "waypoint";
    }

    if (isShrine(code))
    {
        return "shrine";
    }

    if (isChest(code))
    {
        return "chest";
    }

    if (isDoor(code))
    {
        return NULL;
    }

    return "object";
}

int dump_objects(Act *pAct, Level *pLevel, Room2 *pRoom2)
{
    int offsetX = pLevel->dwPosX * 5;
    int offsetY = pLevel->dwPosY * 5;

    int roomOffsetX = pRoom2->dwPosX * 5 - offsetX;
    int roomOffsetY = pRoom2->dwPosY * 5 - offsetY;

    for (PresetUnit *pPresetUnit = pRoom2->pPreset; pPresetUnit; pPresetUnit = pPresetUnit->pPresetNext)
    {
        char *objectType = NULL;
        int coordX = roomOffsetX + pPresetUnit->dwPosX;
        int coordY = roomOffsetY + pPresetUnit->dwPosY;

        if (pPresetUnit->dwType == UNIT_TYPE_NPC)
        {
            if (pPresetUnit->dwTxtFileNo >= SuperUniqueNpc::Bishibosh)
            {
                objectType = "npc";
            }
        }
        else if (pPresetUnit->dwType == UNIT_TYPE_OBJECT)
        {
            objectType = get_object_type(pPresetUnit->dwTxtFileNo);
        }
        else if (pPresetUnit->dwType == UNIT_TYPE_TILE)
        {
            for (RoomTile *pRoomTile = pRoom2->pRoomTiles; pRoomTile; pRoomTile = pRoomTile->pNext)
            {
                if (*pRoomTile->nNum == pPresetUnit->dwTxtFileNo)
                {
                    objectType = "waypoint";
                }
            }
        }

        if (objectType)
        {
            json_object_start();
            json_key_value("id", pPresetUnit->dwTxtFileNo);
            json_key_value("type", objectType);
            json_key_value("x", coordX);
            json_key_value("y", coordY);
            json_object_end();
        }
    }
}

void dump_map_collision(int width, int height)
{
    for (int y = 0; y < height; y++)
    {
        json_array_start();
        char last = 'X';
        int count = 0;
        int outputCount = 0;
        for (int x = 0; x < width; x++)
        {
            char mapVal = map_value(x, y) % 2 ? 'X' : ' ';
            if (mapVal == last)
            {
                count++;
                continue;
            }

            if (outputCount == 0 && last == ' ')
            {
                printf("-1, ");
            }

            json_value(count);

            outputCount++;
            count = 1;
            last = mapVal;
        }
        json_array_end();
    }
}

int dump_map(Act *pAct, int levelCode)
{
    if (!pAct)
    {
        return 1;
    }
    if (levelCode == 20 || levelCode == 59 || levelCode == 63 || levelCode == 93 || levelCode == 99)
    {
        return 0;
    }
    Level *pLevel = d2_get_level(pAct->pMisc, levelCode); // Loading Town Level

    char *levelName = D2COMMON_GetLevelText(levelCode)->szName;
    if (!pLevel)
    {
        printf("Skipping level %d %s\n", levelCode, levelName);
        return 1;
    }

    if (!pLevel->pRoom2First)
    {
        printf("Init Level %d %s\n", pLevel->dwLevelNo, levelName);
        D2COMMON_InitLevel(pLevel);
    }

    if (!pLevel->pRoom2First)
    {
        printf("Failed Init %d\n", levelCode);
        return 1;
    }

    int originX = pLevel->dwPosX * 5;
    int originY = pLevel->dwPosY * 5;

    int mapWidth = pLevel->dwSizeX * 5;
    int mapHeight = pLevel->dwSizeY * 5;

    printf("DumpMap %s \n\toffset: %dx%d\n\tsize: %dx%d\n", levelName, originX, originY, mapWidth, mapHeight);
    map_reset();

    // Start JSON DUMP
    json_start();
    json_key_value("id", levelCode);
    json_key_value("name", levelName);

    json_object_start("offset");
    json_key_value("x", originX);
    json_key_value("y", originY);
    json_object_end();

    json_array_start("objects");

    for (Room2 *pRoom2 = pLevel->pRoom2First; pRoom2; pRoom2 = pRoom2->pRoom2Next)
    {
        BOOL bAdded = FALSE;

        if (!pRoom2->pRoom1)
        {
            bAdded = TRUE;
            D2COMMON_AddRoomData(pAct, pLevel->dwLevelNo, pRoom2->dwPosX, pRoom2->dwPosY, NULL);
        }

        dump_objects(pAct, pLevel, pRoom2);

        if (pRoom2->pRoom1)
            add_collision_data(pRoom2->pRoom1->Coll, originX, originY);

        if (bAdded)
            D2COMMON_RemoveRoomData(pAct, pLevel->dwLevelNo, pRoom2->dwPosX, pRoom2->dwPosY, NULL);
    }

    json_array_end();

    json_array_start("map");
    dump_map_collision(mapWidth, mapHeight);
    json_array_end();
    json_end();
}

int dump_all_maps(int seed, int difficulty)
{
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
    d2_game_init(foldername);

    printf("InitDone...\n");
    BYTE bActLevels[] = {1, 40, 75, 103, 109, 142};

    // INT i = 35;
    INT x = 0;
    // for (INT x = 0; x < 1; x++)
    // {
    Act *pAct = D2COMMON_LoadAct(x, seed, TRUE, FALSE, diff, (DWORD)NULL, bActLevels[x], D2CLIENT_LoadAct_1, D2CLIENT_LoadAct_2);
    printf("LoadingAct 0x%08x_%d %x \n", seed, diff, pAct);

    dump_map(pAct, 13);

    return 0;
}