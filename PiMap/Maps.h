#ifndef MAPS_H
#define MAPS_H

#include <set>
#include <vector>
#include "CollisionMap.h"
#include "d2data/AreaLevel.h"


class Maps : public Thread { // tolua_export

private:
	unsigned int mapid;
	unsigned int difficulty;
	//CCollisionMap maps[136];
	std::map<AreaLevel::AreaLevel, CCollisionMap *> maps;
	Act* pAct[5];

	//std::set<std::pair<int, int>> _maps[136];
	std::map<AreaLevel::AreaLevel, std::set<std::pair<int, int>>> _maps;

	// AwesomO * awesomo;

	AreaLevel::AreaLevel level;
	int x;
	int y;

	bool townPreloadDone;

public:
	Maps();
	~Maps();

	virtual int Routine();

	// void setAwesomO(AwesomO * awesomo);
	void JoinAll();

	void setMapId(unsigned int mapid, unsigned int difficulty);

	void setPosition(int x, int y);
	bool loadMap(int act, AreaLevel::AreaLevel level);
	CCollisionMap* getMap(AreaLevel::AreaLevel level);
	void Invalidate(int x, int y);

	//tolua_begin

	void setLevel(AreaLevel::AreaLevel level);

	POINT pathToLevel(AreaLevel::AreaLevel id);
	POINT pathToObject(int id);
	POINT pathToNpc(int id);
	int getWp();

	std::vector<POINT> explore();
	std::vector<POINT> pathTo(int x, int y, bool teleport = true, int range = 15);
	POINT getDistantPoint(std::vector<POINT> &points, int x, int y, int dist);
	bool CheckLineOfSight(int a, int b, int x, int y);

	bool IsValidIndex(AreaLevel::AreaLevel level, long x, long y);
	bool IsValidAbsLocation(AreaLevel::AreaLevel level, long x, long y);

	void mapAdd(AreaLevel::AreaLevel level, int x, int y);
	void mapRemove(AreaLevel::AreaLevel level, int x, int y);
	AreaLevel::AreaLevel GetCorrectTomb();

	AreaLevel::AreaLevel getLevel();
	bool inTown();
	std::vector<AreaLevel::AreaLevel> getPath(AreaLevel::AreaLevel from, AreaLevel::AreaLevel to);
};
// tolua_end

#endif //MAPS_H
