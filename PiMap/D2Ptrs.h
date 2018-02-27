#include "D2Structs.h"

/*
	Game.exe	00400000
	D2Lang	 	00020000
	D2Net	 	02C70000
	D2Game	 	05760000
	D2Gdi	 	6F870000
	D2Win	 	6F8E0000
	D2Sound	 	6F9B0000
	D2MCPClient	6FA20000
	D2Launch	6FA40000
	D2GFX 		6FA80000
	D2Client	6FAB0000
	Storm 		6FBF0000
	D2Common 	6FD50000
	D2CMP 		6FE10000
	BNClient 	6FF20000
	Fog 		6FF50000
*/

#ifdef _DEFINE_VARS

enum
{
	DLLNO_D2CLIENT,
	DLLNO_D2COMMON,
	DLLNO_D2GFX,
	DLLNO_D2LANG,
	DLLNO_D2WIN,
	DLLNO_D2NET,
	DLLNO_D2GAME,
	DLLNO_D2LAUNCH,
	DLLNO_FOG,
	DLLNO_BNCLIENT,
	DLLNO_STORM,
	DLLNO_D2CMP,
	DLLNO_D2MULTI,
	DLLNO_D2SOUND
};

#define DLLOFFSET(a1, b1) ((DLLNO_##a1) | ((b1) << 8))
#define FUNCPTR(d1, v1, t1, t2, o1) \
	typedef t1 d1##_##v1##_t t2;    \
	d1##_##v1##_t *d1##_##v1 = (d1##_##v1##_t *)DLLOFFSET(d1, o1);
#define VARPTR(d1, v1, t1, o1) \
	typedef t1 d1##_##v1##_t;  \
	d1##_##v1##_t *p_##d1##_##v1 = (d1##_##v1##_t *)DLLOFFSET(d1, o1);
#define ASMPTR(d1, v1, o1) DWORD d1##_##v1 = DLLOFFSET(d1, o1);

#else

#define FUNCPTR(d1, v1, t1, t2, o1) \
	typedef t1 d1##_##v1##_t t2;    \
	extern d1##_##v1##_t *d1##_##v1;
#define VARPTR(d1, v1, t1, o1) \
	typedef t1 d1##_##v1##_t;  \
	extern d1##_##v1##_t *p_##d1##_##v1;
#define ASMPTR(d1, v1, o1) extern DWORD d1##_##v1;

#endif
#define _D2PTRS_START D2CLIENT_InitGameMisc_I

FUNCPTR(D2CLIENT, InitGameMisc_I, VOID __stdcall, (DWORD Dummy1, DWORD Dummy2, DWORD Dummy3), 0x4559B)					 //  1.13d
VARPTR(STORM, MPQHashTable, DWORD, 0x52A60)																				 // 1.13d
ASMPTR(D2CLIENT, LoadAct_1, 0x737F0)																					 // 1.13d
ASMPTR(D2CLIENT, LoadAct_2, 0x2B420)																					 // 1.13d
// ASMPTR(D2CLIENT, LoadAct_1, 0x62AAE) // Updated 1.13c
// ASMPTR(D2CLIENT, LoadAct_2, 0x62760) // Updated 1.13c
FUNCPTR(D2COMMON, AddRoomData, void __stdcall, (Act * ptAct, int LevelId, int Xpos, int Ypos, Room1 *pRoom), 0x24990)	// 1.13d
FUNCPTR(D2COMMON, RemoveRoomData, void __stdcall, (Act * ptAct, int LevelId, int Xpos, int Ypos, Room1 *pRoom), 0x24930) // 1.13d
FUNCPTR(D2COMMON, GetLevel, Level *__fastcall, (ActMisc * pMisc, DWORD dwLevelNo),  0x6D440) // Orig 1.13d
// FUNCPTR(D2COMMON, GetLevel, Level *__fastcall, (ActMisc * pMisc, DWORD dwLevelNo),  -10207) // SemiWorks
// FUNCPTR(D2COMMON, GetLevel, Level *__fastcall, (ActMisc * pMisc, DWORD dwLevelNo),  -11020) // ??
// FUNCPTR(D2COMMON, GetLevel, Level *__fastcall, (ActMisc * pMisc, DWORD dwLevelNo),  -10283) // ??							 // 1.13d
						 // 1.13d
FUNCPTR(D2COMMON, GetLevelText, LevelTxt *__stdcall, (DWORD levelno), 0x30CA0)

FUNCPTR(D2COMMON, InitLevel, void __stdcall, (Level * pLevel), 0x6DDF0)																												 // 1.13d
FUNCPTR(D2COMMON, LoadAct, Act *__stdcall, (DWORD ActNumber, DWORD MapId, DWORD Unk, DWORD Unk_2, DWORD Unk_3, DWORD Unk_4, DWORD TownLevelId, DWORD Func_1, DWORD Func_2), 0x24810) // 1.13d
FUNCPTR(D2COMMON, UnloadAct, VOID __stdcall, (Act * pAct), 0x24590)																													 // 1.13d

FUNCPTR(FOG, 10021, VOID __fastcall, (CHAR * szProg), -10021)														// 1.13d
FUNCPTR(FOG, 10019, DWORD __fastcall, (CHAR * szAppName, DWORD pExceptionHandler, CHAR *szTitle, DWORD _1), -10019) //1.13d
FUNCPTR(FOG, 10101, DWORD __fastcall, (DWORD _1, DWORD _2), -10101)													// 1.13d
FUNCPTR(FOG, 10089, DWORD __fastcall, (DWORD _1), -10089)															// 1.13d
FUNCPTR(FOG, 10218, DWORD __fastcall, (VOID), -10218)																// 1.13d

FUNCPTR(D2WIN, 10174, DWORD __fastcall, (VOID), -10174)														//  1.13d
FUNCPTR(D2WIN, 10072, DWORD __fastcall, (DWORD _1, DWORD _2, DWORD _3, d2client_struct *pD2Client), -10072) //1.13d

FUNCPTR(D2LANG, 10009, DWORD __fastcall, (DWORD _1, CHAR *_2, DWORD _3), -10009)		   //  1.13d
FUNCPTR(D2COMMON, InitDataTables, DWORD __stdcall, (DWORD _1, DWORD _2, DWORD _3), -10081) //  1.13d

#define _D2PTRS_END D2COMMON_InitDataTables

#undef FUNCPTR
#undef VARPTR
#undef ASMPTR

#define GetItemFlag(Unit, Flag) (D2COMMON_GetItemFlag(Unit, Flag, 0, "?"))
#define D2CLIENT_TestPvpFlag(dwId1, dwId2, dwFlag) (TestPvpFlag_STUB(dwId1, dwId2, dwFlag))
#define GetUnitStat(unit, stat) (D2COMMON_GetUnitStat(unit, stat, 0))
#define GetBaseStat(unit, stat) (D2COMMON_GetBaseStat(unit, stat, 0))
#define D2CLIENT_GetUIState(dwVarNo) (D2CLIENT_GetUIVar_STUB(dwVarNo))
//#define D2CLIENT_InitAutomapLayer(layerlvl)	((AutomapLayer*)D2CLIENT_InitAutomapLayer_STUB(layerlvl))
#define D2CLIENT_GetUnitName(x) (wchar_t *)D2CLIENT_GetUnitName_STUB((DWORD)x)
#define D2CLIENT_SetSelectedUnit(x) (D2CLIENT_SetSelectedUnit_STUB((DWORD)x))
//#define D2CLIENT_LoadUIImage(x)				((CellFile*)D2CLIENT_LoadUIImage_ASM(x))
#define D2CLIENT_Interact_(x) (D2CLIENT_Interact_ASM((DWORD)x))
#define D2CLIENT_clickParty(x, y) (D2CLIENT_clickParty_ASM((DWORD)x, (DWORD)y))
#define D2CLIENT_ClickShopItem(x, y, z) (D2CLIENT_ClickShopItem_ASM(x, y, z))
#define D2CLIENT_RightClickItem(X, Y, LOCATION, PLAYER, INVENTORYDATA) D2CLIENT_clickItemRight_ASM(X, Y, LOCATION, (DWORD)PLAYER, (DWORD)INVENTORYDATA)
#define D2CLIENT_clickBeltRight(pPlayer, pInventory, dwShift, dwPotPos) D2CLIENT_clickBeltRight_ASM((DWORD)pPlayer, (DWORD)pInventory, dwShift, dwPotPos)
#define D2CLIENT_GetItemDesc(pUnit, pBuffer) D2CLIENT_GetItemDesc_ASM((DWORD)pUnit, pBuffer)
#define D2COMMON_DisplayOverheadMsg(pUnit) D2COMMON_DisplayOverheadMsg_ASM((DWORD)pUnit)
#define D2CLIENT_MercItemAction(bPacketType, dwSlotId) D2CLIENT_MercItemAction_ASM(bPacketType, dwSlotId)
#define D2CLIENT_PickItem(Unit) (D2CLIENT_PickItem_ASM((DWORD)Unit))
#define D2WIN_GetHwnd D2GFX_GetHwnd
#define D2GFX_DrawFrame(Rect) DrawRectFrame_STUB(Rect)
