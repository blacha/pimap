#pragma once

#include <windows.h>
#include <stdio.h>

#include "D2Structs.h"
#include "D2Ptrs.h"
#include "Offset.h"


#include "CollisionMap.h"

#include "Log.h"
//#include "CommonMath.h"
// #include "WalkPath.h"
// #include "TeleportPath.h"
//#include <pthread.h>

#define ArraySize(x) (sizeof(x) / sizeof(x[0]))

void init(const char* dir);

VOID __fastcall D2OpenFile(CHAR* szFile);
VOID D2OpenFile_ASM();
Level* __fastcall GetLevel(ActMisc *misc, DWORD levelno);
VOID D2CLIENT_InitGameMisc(VOID);

VOID __stdcall ExceptionHandler(VOID);
DWORD D2ClientInterface(VOID);
DWORD D2LAUNCH_QueryInterface(VOID);