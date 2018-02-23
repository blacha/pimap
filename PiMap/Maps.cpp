#include "Maps.h"
#include "D2Ptrs.h"
#include "Log.h"
#include <time.h>

Maps::Maps()
{
	mapid = 0;
	difficulty = 0;
	townPreloadDone = false;
}

Maps::~Maps()
{
	if (this->mapid)
	{
		for (int i = 0; i < 5; i++)
		{
			try
			{
				D2COMMON_UnloadAct(pAct[i]);
				LOG(logDEBUG1) << "Unloaded Act " << i + 1;
			}
			catch (...)
			{
				LOG(logERROR) << "Failed to Unload Act " << i + 1;
			}
		}
	}

	for (std::map<AreaLevel::AreaLevel, CCollisionMap *>::iterator iter = maps.begin(); iter != maps.end(); iter++)
	{
		delete iter->second;
	}
}

int Maps::Routine()
{
	CCollisionMap::loading.Lock();

	try
	{
		BYTE bActLevels[] = {1, 40, 75, 103, 109, 137};

		for (int i = 0; i < 5; i++)
		{
			pAct[i] = D2COMMON_LoadAct(i, mapid, TRUE, FALSE, difficulty, NULL, bActLevels[i], D2CLIENT_LoadAct_1, D2CLIENT_LoadAct_2);
			LOG(logDEBUG1) << "Loaded Act " << i + 1 << " pointer = " << pAct[i];
		}

		// LOG(logDEBUG1) << "Loading map " << AreaLevel::toString(AreaLevel::RogueEncampment);
		// maps[AreaLevel::RogueEncampment] = new CCollisionMap(pAct[0], AreaLevel::RogueEncampment);
		// maps[AreaLevel::RogueEncampment]->Create(false);

		// LOG(logDEBUG1) << "Loading map " << AreaLevel::toString(AreaLevel::LutGholein);
		// maps[AreaLevel::LutGholein] = new CCollisionMap(pAct[1], AreaLevel::LutGholein);
		// maps[AreaLevel::LutGholein]->Create(false);

		// LOG(logDEBUG1) << "Loading map " << AreaLevel::toString(AreaLevel::KurastDocks);
		// maps[AreaLevel::KurastDocks] = new CCollisionMap(pAct[2], AreaLevel::KurastDocks);
		// maps[AreaLevel::KurastDocks]->Create(false);

		// LOG(logDEBUG1) << "Loading map " << AreaLevel::toString(AreaLevel::ThePandemoniumFortress);
		// maps[AreaLevel::ThePandemoniumFortress] = new CCollisionMap(pAct[3], AreaLevel::ThePandemoniumFortress);
		// maps[AreaLevel::ThePandemoniumFortress]->Create(false);


		LOG(logDEBUG1) << "Loading map " << AreaLevel::toString(AreaLevel::Harrogath);
		maps[AreaLevel::Harrogath] = new CCollisionMap(pAct[4], AreaLevel::Harrogath);
		maps[AreaLevel::Harrogath]->Create(false);

	}
	catch (...)
	{
		CCollisionMap::loading.Unlock();
		throw "error loading act pointers";
	}

	CCollisionMap::loading.Unlock();
	return 1;
}

// void Maps::setAwesomO(AwesomO *awesomo)
// {
// 	this->awesomo = awesomo;
// }

void Maps::JoinAll()
{
	Join();

	for (std::map<AreaLevel::AreaLevel, CCollisionMap *>::iterator iter = maps.begin(); iter != maps.end(); iter++)
	{
		clock_t start = clock();
		iter->second->Abort();
		iter->second->Join();

		if (clock() - start > 0)
			LOG(logDEBUG1) << "had to wait " << clock() - start << " ms for " <<  AreaLevel::toString((AreaLevel::AreaLevel)iter->first)  << " to finish loading";
	}
}

void Maps::setMapId(unsigned int mapid, unsigned int difficulty) throw(...)
{
	_maps.clear();

	if (!this->mapid)
	{
		this->mapid = mapid;
		this->difficulty = difficulty;
		Create(false);
		SwitchToThread();
	}
}

void Maps::setLevel(AreaLevel::AreaLevel level) throw(...)
{
	LOG(logDEBUG1) << "Changed Levels from " << this->level  << " to " << AreaLevel::toString((AreaLevel::AreaLevel)level);
	this->level = level;
}


bool Maps::loadMap(int act, AreaLevel::AreaLevel level) throw(...)
{
	bool result = false;

	try
	{
		Join();

		if (maps.find(level) != maps.end())
		{
			LOG(logDEBUG1) << "Found already loaded map " << AreaLevel::toString(level);
			result = true;
		}
		else if (mapid)
		{
			if (pAct[act - 1])
			{
				maps[level] = new CCollisionMap(pAct[act - 1], level);
				maps[level]->Create(false);
				LOG(logDEBUG1) << "Loading map " << AreaLevel::toString((AreaLevel::AreaLevel) level);
				SwitchToThread();
				result = true;
			}
		}
	}
	catch (...)
	{
		LOG(logERROR) << "Exception Caught In loadMap";
	}

	return result;
}

int getAct(AreaLevel::AreaLevel level)
{
	char bActLevels[] = {1, 40, 75, 103, 109, 137};

	for (int i = 0; i < 5; i++)
	{
		if (level < bActLevels[i + 1])
		{
			return i;
		}
	}

	return 0;
}

CCollisionMap *Maps::getMap(AreaLevel::AreaLevel level) throw(...)
{
	Join();
	CCollisionMap *map = maps[level];
	map->Join();

	if (map->GetResult())
	{
		delete map;
		maps[level] = new CCollisionMap(pAct[getAct(level)], level);
		maps[level]->Create(false);
		maps[level]->Join();
	}

	return map;
}

void Maps::Invalidate(int x, int y) throw(...)
{
	getMap(level)->Invalidate(x, y);
}

// POINT Maps::pathToLevel(AreaLevel::AreaLevel id) throw(...)
// {
// 	CCollisionMap *map = getMap(level);
// 	return map->pathToLevel(id);
// }

// POINT Maps::pathToObject(int id) throw(...)
// {
// 	return getMap(level)->pathToObject(id);
// }

// POINT Maps::pathToNpc(int id) throw(...)
// {
// 	return getMap(level)->pathToNpc(id);
// }

// int Maps::getWp() throw(...)
// {
// 	return getMap(level)->getWp();
// }

// std::vector<POINT> Maps::explore() throw(...)
// {
// 	return getMap(level)->explore(x, y);
// }

// std::vector<POINT> Maps::pathTo(int x, int y, bool teleport, int range) throw(...)
// {
// 	return getMap(level)->pathTo(this->x, this->y, x, y, teleport, range);
// }

// POINT Maps::getDistantPoint(std::vector<POINT> &points, int x, int y, int dist) throw(...)
// {
// 	return getMap(level)->teleportTo(points, x, y, dist);
// }

// bool Maps::CheckLineOfSight(int a, int b, int x, int y)
// {
// 	return getMap(level)->CheckLineOfSight(a, b, x, y);
// }

// bool Maps::IsValidIndex(AreaLevel::AreaLevel level, long x, long y) throw(...)
// {
// 	return getMap(level)->IsValidIndex(x, y);
// }

// bool Maps::IsValidAbsLocation(AreaLevel::AreaLevel level, long x, long y) throw(...)
// {
// 	return getMap(level)->IsValidAbsLocation(x, y);
// }

// void Maps::mapAdd(AreaLevel::AreaLevel level, int x, int y) throw(...)
// {
// 	_maps[level].insert(std::pair<int, int>(x, y));
// }

// void Maps::mapRemove(AreaLevel::AreaLevel level, int x, int y) throw(...)
// {
// 	_maps[level].erase(std::pair<int, int>(x, y));
// }

AreaLevel::AreaLevel Maps::GetCorrectTomb() throw(...)
{
	return (AreaLevel::AreaLevel)pAct[1]->pMisc->dwStaffTombLevel;
}

// std::vector<AreaLevel::AreaLevel> Maps::getPath(AreaLevel::AreaLevel from, AreaLevel::AreaLevel to)
// {
// 	std::vector<AreaLevel::AreaLevel> result;
// 	return result;
// }

// bool Maps::inTown()
// {
// 	AreaLevel::AreaLevel level = this->getLevel();
// 	return (level == AreaLevel::RogueEncampment || level == AreaLevel::LutGholein || level == AreaLevel::KurastDocks || level == AreaLevel::ThePandemoniumFortress || level == AreaLevel::Harrogath);
// }
