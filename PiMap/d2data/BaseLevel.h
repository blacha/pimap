#pragma once

#include <string>

/// <summary>
/// Summary description for Levels.
/// </summary>
class BaseLevel { // tolua_export

public:
	//tolua_begin
	std::string Name;
	int Id;
	int Pal;
	int Act;
	int QuestFlag;
	int QuestFlagEx;
	int Layer;
	int SizeX;
	int SizeY;
	int SizeXNM;
	int SizeYNM;
	int SizeXHell;
	int SizeYHell;
	int OffsetX;
	int OffsetY;
	int Depend;
	int Teleport;
	int Rain;
	int Mud;
	int NoPer;
	int LOSDraw;
	int FloorFilter;
	int BlankScreen;
	int DrawEdges;
	int IsInside;
	int DrlgType;
	int LevelType;
	int SubType;
	int SubTheme;
	int SubWaypoint;
	int SubShrine;
	int Vis0;
	int Vis1;
	int Vis2;
	int Vis3;
	int Vis4;
	int Vis5;
	int Vis6;
	int Vis7;
	int Warp0;
	int Warp1;
	int Warp2;
	int Warp3;
	int Warp4;
	int Warp5;
	int Warp6;
	int Warp7;
	int Intensity;
	int Red;
	int Green;
	int Blue;
	int Portal;
	int Position;
	int SaveMonsters;
	int Quest;
	int WarpDist;
	int MonLvl1;
	int MonLvl2;
	int MonLvl3;
	int MonLvl1Ex;
	int MonLvl2Ex;
	int MonLvl3Ex;
	int MonDen;
	int MonDenNM;
	int MonDenHell;
	int MonUMin;
	int MonUMax;
	int MonUMinNM;
	int MonUMaxNM;
	int MonUMinHell;
	int MonUMaxHell;
	int MonWndr;
	int MonSpcWalk;
	int NumMon;
	std::string mon1;
	std::string mon2;
	std::string mon3;
	std::string mon4;
	std::string mon5;
	std::string mon6;
	std::string mon7;
	std::string mon8;
	std::string mon9;
	std::string mon10;
	int rangedspawn;
	std::string nmon1;
	std::string nmon2;
	std::string nmon3;
	std::string nmon4;
	std::string nmon5;
	std::string nmon6;
	std::string nmon7;
	std::string nmon8;
	std::string nmon9;
	std::string nmon10;
	std::string umon1;
	std::string umon2;
	std::string umon3;
	std::string umon4;
	std::string umon5;
	std::string umon6;
	std::string umon7;
	std::string umon8;
	std::string umon9;
	std::string umon10;
	std::string cmon1;
	std::string cmon2;
	std::string cmon3;
	std::string cmon4;
	int cpct1;
	int cpct2;
	int cpct3;
	int cpct4;
	int camt1;
	int camt2;
	int camt3;
	int camt4;
	int Themes;
	int SoundEnv;
	int Waypoint;
	std::string LevelName;
	std::string LevelWarp;
	std::string EntryFile;
	int ObjGrp0;
	int ObjGrp1;
	int ObjGrp2;
	int ObjGrp3;
	int ObjGrp4;
	int ObjGrp5;
	int ObjGrp6;
	int ObjGrp7;
	int ObjPrb0;
	int ObjPrb1;
	int ObjPrb2;
	int ObjPrb3;
	int ObjPrb4;
	int ObjPrb5;
	int ObjPrb6;
	int ObjPrb7;

	BaseLevel(std::string Name, int Id, int Pal, int Act, int QuestFlag, int QuestFlagEx, int Layer, int SizeX, int SizeY, 
		int SizeXNM, int SizeYNM, int SizeXHell, int SizeYHell, int OffsetX, int OffsetY, int Depend, int Teleport, int Rain, 
		int Mud, int NoPer, int LOSDraw, int FloorFilter, int BlankScreen, int DrawEdges, int IsInside, int DrlgType, int LevelType, 
		int SubType, int SubTheme, int SubWaypoint, int SubShrine, int Vis0, int Vis1, int Vis2, int Vis3, int Vis4, 
		int Vis5, int Vis6, int Vis7, int Warp0, int Warp1, int Warp2, int Warp3, int Warp4, int Warp5, 
		int Warp6, int Warp7, int Intensity, int Red, int Green, int Blue, int Portal, int Position, int SaveMonsters, 
		int Quest, int WarpDist, int MonLvl1, int MonLvl2, int MonLvl3, int MonLvl1Ex, int MonLvl2Ex, int MonLvl3Ex, int MonDen, 
		int MonDenNM, int MonDenHell, int MonUMin, int MonUMax, int MonUMinNM, int MonUMaxNM, int MonUMinHell, int MonUMaxHell, int MonWndr, 
		int MonSpcWalk, int NumMon, std::string mon1, std::string mon2, std::string mon3, std::string mon4, std::string mon5,
		std::string mon6, std::string mon7, std::string mon8, std::string mon9, std::string mon10, int rangedspawn, std::string nmon1,
		std::string nmon2, std::string nmon3, std::string nmon4, std::string nmon5, std::string nmon6, std::string nmon7, std::string nmon8,
		std::string nmon9, std::string nmon10, std::string umon1, std::string umon2, std::string umon3, std::string umon4, std::string umon5, 
		std::string umon6, std::string umon7, std::string umon8, std::string umon9, std::string umon10, std::string cmon1, std::string cmon2,
		std::string cmon3, std::string cmon4, int cpct1, int cpct2, int cpct3, int cpct4, int camt1, int camt2, int camt3, int camt4, 
		int Themes, int SoundEnv, int Waypoint, std::string LevelName, std::string LevelWarp, std::string EntryFile, int ObjGrp0, int ObjGrp1,
		int ObjGrp2, int ObjGrp3, int ObjGrp4, int ObjGrp5, int ObjGrp6, int ObjGrp7, int ObjPrb0, int ObjPrb1, int ObjPrb2, int ObjPrb3, 
		int ObjPrb4, int ObjPrb5, int ObjPrb6, int ObjPrb7);

	static BaseLevel *Levels[];
};
// tolua_end
