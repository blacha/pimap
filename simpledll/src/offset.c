
#define _DEFINE_VARS
#include "D2Ptrs.h"
#include <stdio.h>

const char *dlls[] = {"D2Client.DLL", "D2Common.DLL", "D2Gfx.DLL", "D2Lang.DLL",
                      "D2Win.DLL", "D2Net.DLL", "D2Game.DLL", "D2Launch.DLL", "Fog.DLL", "BNClient.DLL",
                      "Storm.DLL", "D2Cmp.DLL"};

DWORD GetDllOffset(const char *DllName, int Offset)
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
	printf("hMod %x", hMod); 
        return ((DWORD)hMod) + Offset;
    }
    catch (...)
    {
        printf("Filed loadingDllOffset %s:%d", DllName, Offset);
    }

    return 0;
}

DWORD GetDllOffset(int num)
{

    if ((num & 0xff) > 12)
        return 0;
    return GetDllOffset(dlls[num & 0xff], num >> 8);
}

void DefineOffsets()
{
    DWORD *p = (DWORD *)&_D2PTRS_START;
    do
    {
        *p = GetDllOffset(*p);
    } while (++p <= (DWORD *)&_D2PTRS_END);
}
