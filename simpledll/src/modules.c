// #include <windows.h>
// #include <stdio.h>

// const char *modules[] =
//     {"D2Client.dll", "D2Common.dll", "D2Gfx.dll", "D2Lang.dll", "D2Win.dll",
//      "D2Net.dll", "D2Game.dll", "D2Launch.dll", "Fog.dll", "BNClient.dll",
//      "Storm.dll", "D2Cmp.dll", "D2Multi.dll"};

// void DefineOffsets()
// {
//     DWORD *p = (DWORD *)&_D2PTRS_START;
//     do
//     {
//         *p = GetDllOffset(*p);
//     } while (++p <= (DWORD *)&_D2PTRS_END);
// }

// DWORD GetDllOffset(char *DllName, int Offset)
// {
//     try
//     {
//         HMODULE hMod = GetModuleHandle(DllName);

//         if (!hMod)
//             hMod = LoadLibrary(DllName);

//         if (!hMod)
//             return 0;

//         if (Offset < 0)
//             return (DWORD)GetProcAddress(hMod, (LPCSTR)(-Offset));

//         return ((DWORD)hMod) + Offset;
//     }
//     catch (...)
//     {
//         printf("GetDllOffset");
//     }

//     return 0;
// }

// DWORD GetDllOffset(int num)
// {
//     static char *dlls[] = {"D2Client.DLL", "D2Common.DLL", "D2Gfx.DLL", "D2Lang.DLL",
//                            "D2Win.DLL", "D2Net.DLL", "D2Game.DLL", "D2Launch.DLL", "Fog.DLL", "BNClient.DLL",
//                            "Storm.DLL", "D2Cmp.DLL"};
//     if ((num & 0xff) > 12)
//         return 0;
//     return GetDllOffset(dlls[num & 0xff], num >> 8);
// }
