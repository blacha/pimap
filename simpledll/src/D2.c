
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <fstream>
#include <string>
#include "D2Structs.h"
#include "D2Ptrs.h"
#include "offset.h"

d2client_struct D2Client;
char D2_DIR[MAX_PATH] = "game/Path of Diablo";

DWORD D2ClientInterface(VOID)
{
    return D2Client.dwInit;
}

VOID __stdcall ExceptionHandler(VOID)
{
    printf("\n] We got a big Error here! [\n");
    ExitProcess(NULL);
}

int D2GameInit(char *folderName)
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
    memset(&D2Client, NULL, sizeof(d2client_struct));

    DefineOffsets();
    printf("Offsets defined.\n");
    DWORD dwFogBase = (DWORD)GetModuleHandle("FOG.dll") + 0x2505C;           //updated 1.13d
    DWORD dwStormBase = (DWORD)GetModuleHandle("Storm.dll") + 0x43230;       //updated 1.13d
    DWORD dwD2ClientBase = (DWORD)GetModuleHandle("D2CLIENT.dll") + 0xCFFA4; //updated 1.13d
    DWORD dwD2Common = (DWORD)GetModuleHandle("D2COMMON.dll") + 0x8D11C;     //updated 1.13d

    DWORD dwOld;
    *p_STORM_MPQHashTable = NULL;

    printf("stormbase : %08X\tfog \t: %08X\nClient \t  : %08X\tcommon\t: %08X\n", dwStormBase, dwFogBase, dwD2ClientBase, dwD2Common);

    D2Client.dwInit = 1;
    D2Client.fpInit = (DWORD)D2ClientInterface;

    printf("FOG_10021 - ");
    FOG_10021("Diablo II");
    printf("Done\n");

    printf("FOG_10019 - ");
    FOG_10019("Diablo II", (DWORD)ExceptionHandler, "v1.xy", 1);
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
    DWORD win10072 = D2WIN_10072(NULL, NULL, NULL, &D2Client);
    printf("Done (%d)\n", win10072);
    if (!win10072)
    {
        printf("Unable to load MPQ Files\n");
        return 1;
    }

    printf("D2LANG_10009 - ");
    D2LANG_10009(0, "ENG", 0);
    printf("Done\n");

    printf("D2COMMON_InitDataTables - ");
    DWORD initDataTables = D2COMMON_InitDataTables(0, 0, 0);
    printf("Done (%d)\n", initDataTables);
    if (!initDataTables)
    {
        printf("Unable to init datatables");
        return 1;
    }
    printf("D2CLIENT_InitGameMisc - ");
    // D2CLIENT_InitGameMisc_I(NULL, NULL, NULL);

    // D2CLIENT_InitGameMisc();
    printf("Done\n");

    SetCurrentDirectory(folderName);
    return 0;
}

Level *__fastcall GetLevel(ActMisc *misc, DWORD levelno)
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

// VOID __declspec(naked) D2CLIENT_InitGameMisc()
// {
//     __asm(
//         "PUSH ECX"
//         "PUSH EBP"
//         "PUSH ESI"
//         "PUSH EDI"
//         "jmp *%0"
//         :
//         : "r"(D2CLIENT_InitGameMisc_I));
//     // {
//     // 	PUSH ECX
//     // 	PUSH EBP
//     // 	PUSH ESI
//     // 	PUSH EDI
//     // 	JMP D2CLIENT_InitGameMisc_I
//     // 	RETN
//     // }
// }
typedef VOID __stdcall D2CLIENT_InitGameMisc_I_t(DWORD Dummy1, DWORD Dummy2, DWORD Dummy3);
// D2CLIENT_InitGameMisc_I_t(DWORD Dummy1, DWORD Dummy2, DWORD Dummy3);
extern "C" D2CLIENT_InitGameMisc_I_t *InitGameMisc_I;
DWORD GetDllOffsets(const char *DllName, int Offset)
{
    try
    {
        HMODULE hMod = GetModuleHandle(DllName);
        printf("loading DLL %s:%d\n", DllName, Offset);

        if (!hMod)
            hMod = LoadLibrary(DllName);

        if (!hMod)
            return 0;

        if (Offset < 0)
            return (DWORD)GetProcAddress(hMod, (LPCSTR)(-Offset));
	printf("+Offset: %d", ((DWORD)hMod) + Offset);
        return ((DWORD)hMod) + Offset;
    }
    catch (...)
    {
        printf("Filed loadingDllOffset %s:%d", DllName, Offset);
    }

    return 0;
}

// extern "C" DWORD D2CLIENT_InitGameMisc_I(DWORD a, DWORD b, DWORD c);
VOID /* __declspec(naked) */ D2CLIENT_InitGameMisc(VOID)
{
/*    DWORD *igm = (DWORD *)GetDllOffsets("D2Client.dll", 0x4559B);
    __asm(
        "MOVL %EBP, %ESP\n"
        "POPL %EBP\n"
        ".intel_syntax noprefix\n"
        "PUSH ECX\n"
        "PUSH EBP\n"
        "PUSH ESI\n"
        "PUSH EDI\n");
	__asm(
	".att_syntax noprefix\n"
	"JMP %P0\n"
//        "PUSHL %EBP\n" 
	: :	 
	  "i"(*igm)); */
}

int main(int argc, char *argv[])
{

    printf("---%d\n", GetDllOffsets("D2Client.dll", 0x4559B));
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
            //LOG(logDEBUG1) << "Loaded Act" << pAct->dwAct+1 << " pointer = " << pAct;;

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
