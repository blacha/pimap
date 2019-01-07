#include <windows.h>
#include "D2Structs.h"
#include "D2Ptrs.h"

DWORD D2ClientInterface(VOID);
VOID __stdcall ExceptionHandler(VOID);
int D2GameInit(char *folderName);
Level *__fastcall GetLevel(ActMisc *misc, DWORD levelno);
void D2CLIENT_InitGameMisc(void);
DWORD GetDllOffsets(int num);
