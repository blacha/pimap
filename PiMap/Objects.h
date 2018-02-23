#pragma once

#include "CriticalSection.h"
#include <list>
#include <vector>
#include "d2data/GameObjects.h"
#include "d2data/AreaLevel.h"
#include <cmath>

//tolua_begin
struct OBJECT
{
	GameObjectID::GameObjectID objectID;
	GameObjectInteractType::GameObjectInteractType interactType;
	GameObjectMode::GameObjectMode objectMode;
	unsigned int ownerUID;
    unsigned int uid;
    unsigned int x;
    unsigned int y;
	AreaLevel::AreaLevel destination;
	bool canChangeBack;

	OBJECT()
	{
		ownerUID = 0;
		uid = 0;
		x = 0;
		y = 0;
	}
	
	int getDistance(short x, short y)
	{
		return (int)::sqrt((double)((this->x - x) * (this->x - x) + (this->y - y) * (this->y - y)));
	}
};
//tolua_end

class Objects { // tolua_export

private:
	CriticalSection cs;
	std::list<OBJECT> list;
	bool isDoor(OBJECT object);
	bool isRack(OBJECT object);
	bool isChest(OBJECT object);
	int Objects::distance(OBJECT object, short x, short y);
	
public:
	Objects();
	~Objects();
	//tolua_begin
	void add(OBJECT object);
	void add_owner(unsigned int uid, unsigned int ownerUID);
	void remove(unsigned int uid);
	OBJECT find(unsigned int uid);
	OBJECT find(GameObjectID::GameObjectID objectID);
	std::vector<OBJECT> findMultiple(GameObjectID::GameObjectID objectID);
	std::vector<OBJECT> findInRadius(short x, short y, int radius);
	void update(unsigned int uid, short x, short y);
	int distance(unsigned int uid, short x, short y);
	int FindWaypoint();
	OBJECT FindChest(short x, short y);
	std::vector<OBJECT> FindDoors(short x, short y, int radius);
	std::vector<OBJECT> FindChests(short x, short y, int radius);
	std::vector<OBJECT> FindRacks(short x, short y, int radius);
	OBJECT FindShrine(GameObjectType::GameObjectType type);
	int FindPortal();
	int FindBank();
	int FindTownPortal();
	int FindTownPortalByOwner(unsigned int ownerUID);
	OBJECT FindPermanentPortalByDestination(AreaLevel::AreaLevel destination);
	OBJECT FindTownPortalByDestination(AreaLevel::AreaLevel destination);
	void SetGameObjectMode(unsigned int uid, bool canChangeBack, GameObjectMode::GameObjectMode objectMode);
};
// tolua_end
