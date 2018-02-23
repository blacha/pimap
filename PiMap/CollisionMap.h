//////////////////////////////////////////////////////////////////////
// CollisionMap.h: interface for the CCollisionMap class.
//
// Abin (abinn32@yahoo.com)
//////////////////////////////////////////////////////////////////////

#ifndef __COLLISIONMAP_H__
#define __COLLISIONMAP_H__

#define MAP_DATA_INVALID -1		 // Invalid
#define MAP_DATA_CLEANED 11110   // Cleaned for start/end positions
#define MAP_DATA_FILLED 11111	// Filled gaps
#define MAP_DATA_THICKENED 11113 // Wall thickened
#define MAP_DATA_AVOID 11115	 // Should be avoided

#define UNIT_TYPE_PLAYER 0
#define UNIT_TYPE_NPC 1
#define UNIT_TYPE_OBJECT 2
#define UNIT_TYPE_MISSILE 3
#define UNIT_TYPE_ITEM 4
#define UNIT_TYPE_TILE 5

#include <map>
#include <vector>
//#include "ArrayEx.h"
#include "Matrix.h"
#include "D2Structs.h"
#include "Thread.h"
#include "Objects.h"

class AwesomO;

//typedef CArrayEx<DWORD, DWORD> DwordArray;
//typedef CArrayEx<WORD, WORD> WordArray;
typedef CMatrix<WORD, WORD> WordMatrix;

typedef struct LevelExit_t
{
	POINT ptPos;
	DWORD dwTargetLevel;
} LevelExit, *LPLevelExit;

////////////////////////////////////////////////////////////////
// The CCollisionMap class. Synchronized access required.
////////////////////////////////////////////////////////////////
class CCollisionMap : public Thread
{
  public:
	static CCollisionMap *last;

	////////////////////////////////////////////////////////////
	// Constructor & Destructor
	////////////////////////////////////////////////////////////
	//CCollisionMap();
	CCollisionMap(Act *lpAct, DWORD ldwAreaId);
	virtual ~CCollisionMap();

	////////////////////////////////////////////////////////////
	// Threads
	////////////////////////////////////////////////////////////
	virtual int Routine();

	////////////////////////////////////////////////////////////
	// Operations
	////////////////////////////////////////////////////////////
	//BOOL CreateMap(Act* lpAct, DWORD AreaId, AwesomO * awesomo); // Create the map data
	void DestroyMap();
	BOOL DumpMap(LPCSTR lpszFilePath) const; // Dump map data into a disk file
	//void Search(Room2 *ro, UnitAny* ptPlayer, DwordArray &aSkip);

	////////////////////////////////////////////////////////////
	// Attributes & Operations
	////////////////////////////////////////////////////////////
	POINT GetMapOrigin() const;						  // Map origin point(top-left)
	SIZE GetMapSize() const;						  // map size
	int GetMapQSize() const;						  // map size
	WORD GetMapData(long x, long y, BOOL bAbs) const; // Retrieve map data at a particular location
	BOOL IsValidIndex(long x, long y) const;
	BOOL IsValidIndex(POINT p) const;
	BOOL IsValidAbsLocation(long x, long y) const; // Map location verification
	BOOL IsValidAbsLocation(POINT p) const;
	SIZE CopyMapData(WORD **ppBuffer, int cx, int cy) const;
	void Invalidate(int x, int y);

	////////////////////////////////////////////////////////////
	// Generate Path
	////////////////////////////////////////////////////////////
	POINT pathToLevel(int id);
	POINT pathToObject(int id);
	POINT pathToNpc(int id);
	int getWp();
	std::vector<POINT> explore(int x, int y);
	std::vector<POINT> pathTo(int start_x, int start_y, int end_x, int end_y, bool teleport = true, int range = 25);
	POINT teleportTo(std::vector<POINT> &points, int x, int y, int dist);
	bool CheckLineOfSight(int x1, int y1, int x2, int y2);

	////////////////////////////////////////////////////////////
	// Convertions
	////////////////////////////////////////////////////////////
	void AbsToRelative(POINT &pt) const; // Convert an absolute map location into a graph index
	void RelativeToAbs(POINT &pt) const; // Convert a graph index into an absolute map location
	BOOL ThickenWalls(int nThickenBy = 1);
	void FindExits();
	BOOL IsGap(int x, int y);
	BOOL CheckCollision(INT x, INT y);

	static CriticalSection loading;

  private:
	////////////////////////////////////////////////////////////
	// Private Data
	////////////////////////////////////////////////////////////

	AwesomO *awesomo;

	////////////////////////////////////////////////////////////
	// Private Methods
	////////////////////////////////////////////////////////////
	BOOL BuildMapData(DWORD AreaId);
	void AddCollisionData(const CollMap *pCol);
	void AddUnitData(const Room2 *pRoom2);
	void AddUnitData(const Room2 *pRoom2, unsigned thickenBy);
	char IsMarkPoint(INT asd, int x, int y, std::vector<POINT> ptPath) const;

	void FillGaps();

	////////////////////////////////////////////////////////////
	// Member Data
	////////////////////////////////////////////////////////////

	DWORD m_iCurMap;	   // Current map ID
	POINT m_ptLevelOrigin; // level top-left
	DWORD dwLevelId;
	DWORD dwAreaId;
	Act *pAct;
	Level *pLevel;

	std::map<DWORD, std::pair<short, short>> exits;
	std::map<DWORD, std::vector<std::pair<POINT, POINT>>> levelsnear;
	std::map<DWORD, std::vector<std::pair<short, short>>> npcs;
	std::map<DWORD, std::vector<std::pair<short, short>>> objects;
	WordMatrix m_map; // The map
};

#endif // __COLLISIONMAP_H__
