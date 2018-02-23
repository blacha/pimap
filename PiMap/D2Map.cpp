// #include "AwesomO.h"
#include "D2Map.h"
#include "D2Structs.h"
#include "d2data/AreaLevel.h"
#include <set>
#include <time.h>
#include <fstream>
#include "Log.h"

d2client_struct D2Client;

char D2_DIR[MAX_PATH] = "";

HANDLE __stdcall myCreateFile(LPCTSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile)
{
	std::string szPath(lpFileName);

	if (szPath.find('\\') != std::string::npos)
	{
		szPath = szPath.substr(szPath.rfind('\\') + 1);
	}

	szPath.insert(0, D2_DIR);

	return CreateFile(szPath.c_str(), dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
}

void init(const char *dir)
{
	sprintf_s(D2_DIR, sizeof(D2_DIR), "%s\\", dir);

	char GAME[MAX_PATH] = "";
	sprintf_s(GAME, sizeof(GAME), "%s\\game.exe", dir);
	std::ifstream ifs(GAME, std::ifstream::in);
	if (!ifs)
	{
		LOG(logERROR) << "Incorrect Folder Name";
		exit(1);
	}
	ifs.close();

	CHAR szPath[MAX_PATH] = {0};
	GetCurrentDirectory(MAX_PATH, szPath);
	memset(&D2Client, NULL, sizeof(d2client_struct));
	SetCurrentDirectory(D2_DIR);
	LOG(logDEBUG2) << "Loading D2 Libs ..";
	DefineOffsets();
	InstallPatchs();

	//LOG(logDEBUG2) << szPath;

	// DWORD dwFogBase = (DWORD)GetModuleHandle("FOG.dll") + 0x2505C;			 //updated 1.13d
	// DWORD dwStormBase = (DWORD)GetModuleHandle("Storm.dll") + 0x43230;		 //updated 1.13d
	// DWORD dwD2ClientBase = (DWORD)GetModuleHandle("D2CLIENT.dll") + 0xCFFA4; //updated 1.13d
	// DWORD dwD2Common = (DWORD)GetModuleHandle("D2COMMON.dll") + 0x8D11C;	 //updated 1.13d

	// printf("stormbase : %08X\nfog : %08X\nClient : %08X\ncommon : %08X\n", dwStormBase, dwFogBase, dwD2ClientBase, dwD2Common);

	// DWORD dwOld;
	// VirtualProtect((VOID *)dwFogBase, 4, PAGE_READWRITE, &dwOld);
	// *(DWORD *)dwFogBase = (DWORD)myCreateFile;
	// VirtualProtect((VOID *)dwFogBase, 4, dwOld, &dwOld);

	// VirtualProtect((VOID *)dwStormBase, 4, PAGE_READWRITE, &dwOld);
	// *(DWORD *)dwStormBase = (DWORD)myCreateFile;
	// VirtualProtect((VOID *)dwStormBase, 4, dwOld, &dwOld);

	// VirtualProtect((VOID *)dwD2ClientBase, 4, PAGE_READWRITE, &dwOld);
	// *(DWORD *)dwD2ClientBase = (DWORD)myCreateFile;
	// VirtualProtect((VOID *)dwD2ClientBase, 4, dwOld, &dwOld);

	// VirtualProtect((VOID *)dwD2Common, 4, PAGE_READWRITE, &dwOld);
	// *(DWORD *)dwD2Common = (DWORD)myCreateFile;
	// VirtualProtect((VOID *)dwD2Common, 4, dwOld, &dwOld);

	*p_STORM_MPQHashTable = NULL;
	LOG(logDEBUG2) << "Finished loading D2 Libs!";
	D2Client.dwInit = 1;
	D2Client.fpInit = (DWORD)D2ClientInterface;

	FOG_10021("D2");
	// FOG_10019("D2", (DWORD)ExceptionHandler, "D2", 1);
	FOG_10101(1, NULL);
	FOG_10089(1);

	if (FOG_10218())
	{
		LOG(logDEBUG2) << "Game Server Initialized";
	}
	else
	{
		LOG(logERROR) << "Game Server Initialize Failed!";
		ExitProcess(NULL);
	}

	LOG(logDEBUG2) << "Loading Data Files!";
	if (D2WIN_10174())
	{
		if (D2WIN_10072(NULL, NULL, NULL, &D2Client))
		{
			LOG(logDEBUG2) << "Game Data Files Initialized!";
		}
		else
		{
			LOG(logERROR) << "Couldn't load Diablo 2 MPQ files. Please make sure you have a full install of Diablo II and copy the D2XMUSIC.MPQ and D2XVIDEO.MPQ from the Expansion CD";
			ExitProcess(NULL);
		}
	}
	LOG(logDEBUG2) << "Loading Language Tables...";
	D2LANG_10009(0, "ENG", 0);

	LOG(logDEBUG2) << "Initalized String table...";

	if (D2COMMON_InitDataTables(0, 0, 0))
	{
		LOG(logDEBUG2) << "Succesfully initalized D2 Libs!";
	}
	else
	{
		LOG(logERROR) << "Couldn't initialize sqptDataTable!";
		ExitProcess(NULL);
	}

	D2CLIENT_InitGameMisc();

	SetCurrentDirectory(szPath);

	LOG(logDEBUG2) << "Initalized Game Misc...";
}

Level *__fastcall GetLevel(ActMisc *misc, DWORD levelno)
{

	for (Level *pLevel = misc->pLevelFirst; pLevel; pLevel = pLevel->pNextLevel)
	{
		if (!pLevel)
         continue;

		if (pLevel->dwLevelNo == levelno){
			// LOG(logDEBUG1) << "GetLevel pLevel " << levelno << " " <<  D2COMMON_GetLevelText(levelno)->szName;;
			return pLevel;
		}
	}
	LOG(logDEBUG1) << "D2COMMON_GetLevel " << levelno << " " <<  D2COMMON_GetLevelText(levelno)->szName;;
	return D2COMMON_GetLevel(misc, levelno);
	// LOG(logDEBUG1) << "D2COMMON_GetLevel Done" << levelno;

	// return foo;
}

VOID __declspec(naked) D2CLIENT_InitGameMisc(VOID)
{
	__asm
	{
		PUSH ECX
		PUSH EBP
		PUSH ESI
		PUSH EDI
		JMP D2CLIENT_InitGameMisc_I
		RETN
	}
}

DWORD D2ClientInterface(VOID)
{
	return D2Client.dwInit;
}

VOID __stdcall ExceptionHandler(VOID)
{
	LOG(logERROR) << "] We got a big Error here! [";
	//ExitProcess(NULL);
}

VOID __fastcall D2OpenFile(CHAR *szFile)
{
	LOG(logDEBUG4) << "Loading: " << szFile;
}

DWORD dwJmpBck = 0x6FD5B5E0 + 6; // 1.13d
VOID __declspec(naked) D2OpenFile_ASM()
{
	__asm {
		PUSH ECX
		PUSH EBP
		MOV EBP, DWORD PTR SS:[ESP+0x10]

		PUSHAD
		MOV ECX, EAX
		CALL D2OpenFile
		POPAD
		JMP dwJmpBck
	}
}
