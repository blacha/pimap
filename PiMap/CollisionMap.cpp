// CollisionMap.cpp: implementation of the CCollisionMap class.
//
//////////////////////////////////////////////////////////////////////
#include "D2Map.h"
#include "d2data/AreaLevel.h"
#include "d2data/NpcCode.h"
#include <limits>
#include <time.h>

bool dumpMaps = true;
//////////////////////////////////////////////////////////////////////
// Static Variables
//////////////////////////////////////////////////////////////////////

CriticalSection CCollisionMap::loading;
CCollisionMap *CCollisionMap::last;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCollisionMap::CCollisionMap(Act *lpAct, DWORD ldwAreaId)
{
	this;
	this->m_iCurMap = 0x00;
	this->dwLevelId = 0x00;
	this->pAct = lpAct;
	this->dwAreaId = ldwAreaId;
	::memset(&m_ptLevelOrigin, 0, sizeof(POINT));
}

CCollisionMap::~CCollisionMap()
{
	//Abort();
	//Join();
	// -----	 // LOG(logDEBUG1) << "Destructing " << AreaLevel::toString((AreaLevel::AreaLevel)this->dwAreaId);
}

void CCollisionMap::AddCollisionData(const CollMap *pCol)
{
	if (pCol == NULL)
		return;

	int x = pCol->dwPosGameX - m_ptLevelOrigin.x;
	int y = pCol->dwPosGameY - m_ptLevelOrigin.y;
	int cx = pCol->dwSizeGameX;
	int cy = pCol->dwSizeGameY;

	if (!m_map.IsValidIndex(x, y))
	{
		return;
	}

	int nLimitX = x + cx;
	int nLimitY = y + cy;

	WORD *p = pCol->pMapStart;
	for (int j = y; j < nLimitY; j++)
	{
		for (int i = x; i < nLimitX; i++)
		{
			m_map[i][j] = *p;
			if (m_map[i][j] == 1024)
				m_map[i][j] = MAP_DATA_AVOID;

			p++;
		}
	}
}

void CCollisionMap::AddUnitData(const Room2 *pRoom2)
{
	AddUnitData(pRoom2, 2); // default is 2
}

void CCollisionMap::AddUnitData(const Room2 *pRoom2, unsigned thickenBy)
{
	for (PresetUnit *pPresetUnit = pRoom2->pPreset; pPresetUnit; pPresetUnit = pPresetUnit->pPresetNext)
	{
		// npcs
		if (pPresetUnit->dwType == UNIT_TYPE_NPC)
		{
			// -----			 LOG(logDEBUG4) << "Npc = " << pPresetUnit->dwTxtFileNo << ", x = " << pRoom2->dwPosX * 5 + pPresetUnit->dwPosX << " y = " << pRoom2->dwPosY * 5 + pPresetUnit->dwPosY;
			npcs[pPresetUnit->dwTxtFileNo].push_back(std::pair<short, short>((short)pRoom2->dwPosX * 5 + pPresetUnit->dwPosX, (short)pRoom2->dwPosY * 5 + pPresetUnit->dwPosY));
		}

		// objects
		if (pPresetUnit->dwType == UNIT_TYPE_OBJECT)
		{
			if (thickenBy < 0) // make sure?
				thickenBy = 0;

			// -----			 LOG(logDEBUG4) << "Object = " << pPresetUnit->dwTxtFileNo << ", x = " << pRoom2->dwPosX * 5 + pPresetUnit->dwPosX << " y = " << pRoom2->dwPosY * 5 + pPresetUnit->dwPosY;
			objects[pPresetUnit->dwTxtFileNo].push_back(std::pair<short, short>((short)pRoom2->dwPosX * 5 + pPresetUnit->dwPosX, (short)pRoom2->dwPosY * 5 + pPresetUnit->dwPosY));

			GameObjectID::GameObjectID oid = static_cast<GameObjectID::GameObjectID>(pPresetUnit->dwTxtFileNo);
			if (!isGoodObject(oid) && thickenBy > 0)
			{
				Invalidate(pRoom2->dwPosX * 5 + pPresetUnit->dwPosX, pRoom2->dwPosY * 5 + pPresetUnit->dwPosY);
			}
		}

		// level exits
		if (pPresetUnit->dwType == UNIT_TYPE_TILE)
		{
			for (RoomTile *pRoomTile = pRoom2->pRoomTiles; pRoomTile; pRoomTile = pRoomTile->pNext)
			{
				if (*pRoomTile->nNum == pPresetUnit->dwTxtFileNo)
				{
					// -----// ----					LOG(logDEBUG3) << pRoom2->dwPosX * 5 + pPresetUnit->dwPosX << "/"
					//						<< pRoom2->dwPosY * 5 + pPresetUnit->dwPosY << " = "
					//						<< AreaLevel::toString((AreaLevel::AreaLevel)pLevel->dwLevelNo) << "->" << AreaLevel::toString((AreaLevel::AreaLevel)pRoomTile->pRoom2->pLevel->dwLevelNo);

					exits[pRoomTile->pRoom2->pLevel->dwLevelNo].first = (short)pRoom2->dwPosX * 5 + pPresetUnit->dwPosX;
					exits[pRoomTile->pRoom2->pLevel->dwLevelNo].second = (short)pRoom2->dwPosY * 5 + pPresetUnit->dwPosY;
				}
			}
		}
	}
}

BOOL CCollisionMap::IsValidIndex(long x, long y) const
{
	return x >= 0 && x < m_map.GetCX() && y >= 0 && y < m_map.GetCY();
}

BOOL CCollisionMap::IsValidIndex(POINT p) const
{
	return IsValidIndex(p.x, p.y);
}

BOOL CCollisionMap::IsValidAbsLocation(long x, long y) const
{
	x -= m_ptLevelOrigin.x;
	y -= m_ptLevelOrigin.y;

	return IsValidIndex(x, y);
}

BOOL CCollisionMap::IsValidAbsLocation(POINT p) const
{
	p.x -= m_ptLevelOrigin.x;
	p.y -= m_ptLevelOrigin.y;

	return IsValidIndex(p);
}

WORD CCollisionMap::GetMapData(long x, long y, BOOL bAbs) const
{
	if (bAbs)
	{
		x -= m_ptLevelOrigin.x;
		y -= m_ptLevelOrigin.y;
	}

	WORD wVal = MAP_DATA_INVALID;

	if (IsValidIndex(x, y))
		wVal = m_map[x][y];

	return wVal;
}

BOOL CCollisionMap::BuildMapData(DWORD AreaId)
{

	dwLevelId = AreaId;
	pLevel = GetLevel(pAct->pMisc, AreaId);
	// -----	// LOG(logDEBUG1) << "GetLevelDone";

	if (!pLevel)
		return FALSE;

	if (!pLevel->pRoom2First)
		D2COMMON_InitLevel(pLevel);
	// -----	// LOG(logDEBUG1) << "InitLevelDone";

	if (!pLevel->pRoom2First)
		return NULL;

	dwLevelId = AreaId;

	m_ptLevelOrigin.x = pLevel->dwPosX * 5;
	m_ptLevelOrigin.y = pLevel->dwPosY * 5;

	if (!m_map.Create(pLevel->dwSizeX * 5, pLevel->dwSizeY * 5, MAP_DATA_INVALID))
	{
		return FALSE;
	}

	for (unsigned int x = 0; x < m_map.GetCX(); x++)
	{
		for (unsigned int y = 0; y < m_map.GetCY(); y++)
		{
			m_map[x][y] = MAP_DATA_INVALID;
		}
	}
	// -----	// LOG(logDEBUG1) << "MapInitDone";

	//DwordArray aSkip;
	//Search(pLevel->pRoom2First, NULL, aSkip);

	for (Room2 *pRoom2 = pLevel->pRoom2First; pRoom2; pRoom2 = pRoom2->pRoom2Next)
	{
		BOOL bAdded = FALSE;

		if (!pRoom2->pRoom1)
		{
			bAdded = TRUE;
			D2COMMON_AddRoomData(pAct, pLevel->dwLevelNo, pRoom2->dwPosX, pRoom2->dwPosY, NULL);
			// -----			// LOG(logDEBUG4) << "AddRoomData";
		}

		// levels near
		for (int i = 0; i < pRoom2->dwRoomsNear; i++)
		{
			DWORD prev = pLevel->dwLevelNo;
			if (pLevel->dwLevelNo != pRoom2->pRoom2Near[i]->pLevel->dwLevelNo)
			{
				std::pair<POINT, POINT> newlevel;

				newlevel.first.x = pRoom2->pRoom2Near[i]->pLevel->dwPosX * 5;
				newlevel.first.y = pRoom2->pRoom2Near[i]->pLevel->dwPosY * 5;
				newlevel.second.x = pRoom2->pRoom2Near[i]->pLevel->dwSizeX * 5;
				newlevel.second.y = pRoom2->pRoom2Near[i]->pLevel->dwSizeY * 5;

				if (prev != pRoom2->pRoom2Near[i]->pLevel->dwLevelNo)
				{
					// -----					 // LOG(logDEBUG1) << pRoom2->pRoom2Near[i]->pLevel->dwPosX * 5 << "/" << pRoom2->pRoom2Near[i]->pLevel->dwPosY * 5 << " = " << AreaLevel::toString((AreaLevel::AreaLevel)pLevel->dwLevelNo) << "->" << AreaLevel::toString((AreaLevel::AreaLevel)pRoom2->pRoom2Near[i]->pLevel->dwLevelNo);
					prev = pRoom2->pRoom2Near[i]->pLevel->dwLevelNo;
				}
				levelsnear[pRoom2->pRoom2Near[i]->pLevel->dwLevelNo].push_back(newlevel);
			}
		}

		if (pRoom2->pRoom1)
			AddCollisionData(pRoom2->pRoom1->Coll);

		switch (AreaId)
		{
		case AreaLevel::Harrogath:
			AddUnitData(pRoom2, 2);
			break;
		case AreaLevel::ThePandemoniumFortress:
		case AreaLevel::KurastDocks:
		case AreaLevel::LutGholein:
			AddUnitData(pRoom2, 0);
			break;
		case AreaLevel::RogueEncampment:
			AddUnitData(pRoom2, 2);
			break;
		case AreaLevel::CatacombsLevel4:
		case AreaLevel::ThroneOfDestruction:
			AddUnitData(pRoom2, 0);
			break;
		default:
			AddUnitData(pRoom2, 0);
			break;
		}
		/*
		if(AreaId == AreaLevel::Harrogath) // we want the stairs to be walkable
			AddUnitData(pRoom2, 1);        // hence we thicken objects by only 1
		//else
		//	AddUnitData(pRoom2,0);           // thicken by 2 is default
		*/
		if (bAdded)
			D2COMMON_RemoveRoomData(pAct, pLevel->dwLevelNo, pRoom2->dwPosX, pRoom2->dwPosY, NULL);
	}

	return TRUE;
}
BOOL CCollisionMap::Routine()
{
	return TRUE;
}

BOOL CCollisionMap::CreateMap()
{
	BuildMapData(dwAreaId);
	return TRUE;
}

POINT CCollisionMap::GetMapOrigin() const
{
	return m_ptLevelOrigin;
}

void CCollisionMap::AbsToRelative(POINT &pt) const
{
	pt.x -= m_ptLevelOrigin.x;
	pt.y -= m_ptLevelOrigin.y;
}

void CCollisionMap::RelativeToAbs(POINT &pt) const
{
	pt.x += m_ptLevelOrigin.x;
	pt.y += m_ptLevelOrigin.y;
}

BOOL CCollisionMap::DumpMap(LPCSTR lpszFilePath) const
{
	if (!dumpMaps)
		return false;

	if (lpszFilePath == NULL)
		return FALSE;

	CHAR szMapName[64] = "";

	sprintf_s(szMapName, sizeof(szMapName), "%s", D2COMMON_GetLevelText(dwLevelId)->szName);

	FILE *fp = fopen(lpszFilePath, "w+");
	try
	{

		if (fp == NULL)
			return FALSE;

		fprintf(fp, "{\n");
		fprintf(fp, "\t\"id\": %d,\n", dwLevelId);
		fprintf(fp, "\t\"name\": \"%s\",\n", szMapName);
		fprintf(fp, "\t\"origin\": { \"x\":%d, \"y\":%d },\n", m_ptLevelOrigin.x, m_ptLevelOrigin.y);
		fprintf(fp, "\t\"size\": { \"width\":%d, \"height\":%d },\n", m_map.GetCX(), m_map.GetCY());
		fprintf(fp, "\t\"npcs\": [\n");
		int objectCount = 0;
		int npcCount = 0;

		// Find all the waypoints

		for (std::map<DWORD, std::vector<std::pair<short, short>>>::const_iterator iter1 = npcs.begin(); iter1 != npcs.end(); iter1++)
		{
			for (std::vector<std::pair<short, short>>::const_iterator iter2 = iter1->second.begin(); iter2 != iter1->second.end(); iter2++)
			{
				// if (iter1->first == SuperUniqueNpc::TheSummoner ||
				// 	iter1->first == SuperUniqueNpc::NihlathakBoss ||
				// 	iter1->first == SuperUniqueNpc::TheCountess)
				// {
				POINT p = {iter2->first, iter2->second};
				AbsToRelative(p);

				if (npcCount > 0)
				{
					fprintf(fp, ",\n");
				}
				fprintf(fp, "\t\t{ \"id\":%d, \"x\":%d, \"y\":%d }", (unsigned int)iter1->first, p.x, p.y);
				npcCount++;
				// }
			}
		}

		fprintf(fp, "\n\t],\n");

		fprintf(fp, "\t\"objects\": [\n");

		for (std::map<DWORD, std::pair<short, short>>::const_iterator iter = exits.begin(); iter != exits.end(); iter++)
		{

			POINT p = {iter->second.first, iter->second.second};
			AbsToRelative(p);

			if (objectCount > 0)
			{
				fprintf(fp, ",\n");
			}
			fprintf(fp, "\t\t\{ \"id\":%d, \"x\":%d, \"y\":%d, \"type\": \"Exit\" }", (unsigned int)iter->first, p.x, p.y);
			objectCount++;
		}

		for (std::map<DWORD, std::vector<std::pair<short, short>>>::const_iterator iter1 = this->objects.begin(); iter1 != objects.end(); iter1++)
		{
			for (std::vector<std::pair<short, short>>::const_iterator iter2 = iter1->second.begin(); iter2 != iter1->second.end(); iter2++)
			{

				//is there an enum for the object id's like the one for the npc's...?
				if (iter1->first == 0x0077 ||
					iter1->first == 0x009D ||
					iter1->first == 0x009C ||
					iter1->first == 0x0143 ||
					iter1->first == 0x0120 ||
					iter1->first == 0x0192 ||
					iter1->first == 0x00ED ||
					iter1->first == 0x0144 ||
					iter1->first == 0x018E ||
					iter1->first == 0x00EE ||
					iter1->first == 0x01AD ||
					iter1->first == 0x01F0 ||
					iter1->first == 0x01FF ||
					iter1->first == 0x01EE)
				{
					POINT p = {iter2->first, iter2->second};
					AbsToRelative(p);
					if (objectCount > 0)
					{
						fprintf(fp, ",\n");
					}
					fprintf(fp, "\t\t{ \"id\":%d, \"x\":%d, \"y\":%d, \"type\": \"Waypoint\" }", (unsigned int)iter1->first, p.x, p.y);
					objectCount++;
				}
				else
				{
					POINT p = {iter2->first, iter2->second};
					AbsToRelative(p);
					if (objectCount > 0)
					{
						fprintf(fp, ",\n");
					}
					fprintf(fp, "\t\t{ \"id\":%d, \"x\":%d, \"y\":%d, \"type\": \"Object\" }", (unsigned int)iter1->first, p.x, p.y);
					objectCount++;
				}
			}
		}
		fprintf(fp, "\n\t],\n");

		fprintf(fp, "\t\"map\":[\n");
		const int CX = m_map.GetCX();
		const int CY = m_map.GetCY();

		for (int y = 0; y < CY; y++)
		{
			char last = 'X';
			int count = 0;
			fprintf(fp, "\t\t[");
			int outputCount = 0;
			for (int x = 0; x < CX; x++)
			{
				char ch = (m_map[x][y] % 2) ? 'X' /* m_map[x][y] */ : ' ';

				if (ch == last)
				{
					count++;
				}
				else
				{
					if (outputCount > 0)
					{
						fprintf(fp, ", ");
					}

					if (outputCount == 0 && last == ' ')
					{
						fprintf(fp, "-1, ");
					}

					fprintf(fp, "%d", count + 1);
					outputCount++;
					count = 0;
					last = ch;
				}
			}

			fprintf(fp, "]");
			if (y + 1 < CY)
			{
				fprintf(fp, ",\n");
			}
		}
		fprintf(fp, "\t]\n");
		fprintf(fp, "}\n");
	}
	catch (...)
	{
		printf("Error dumping map");
	}

	fclose(fp);

	return TRUE;
}

BOOL CCollisionMap::CheckCollision(INT x, INT y)
{
	if (x > m_map.GetCX() || y > m_map.GetCY())
		return FALSE;
	BOOL Works = FALSE;
	Works = (m_map[x][y] % 2) ? FALSE : TRUE;
	return Works;
}

char CCollisionMap::IsMarkPoint(INT asd, int x, int y, const std::vector<POINT> ptPath) const
{
	char ch = 0;

	for (DWORD i = 0; i < ptPath.size(); i++)
	{
		if (ptPath[i].x == x && ptPath[i].y == y)
		{
			if (i == 0)
				return 'S'; // start
			else if (i == ptPath.size() - 1)
				return 'E'; // end
			else
				return 'a' + i; //'*'; // nodes
		}
	}

	return ch;
}

SIZE CCollisionMap::GetMapSize() const
{
	SIZE cz = {0};
	cz.cx = m_map.GetCX();
	cz.cy = m_map.GetCY();
	return cz;
}

int CCollisionMap::GetMapQSize() const
{
	int s = 0;
	s = m_map.GetCX();
	s *= m_map.GetCY();
	return s;
}

SIZE CCollisionMap::CopyMapData(WORD **ppBuffer, int cx, int cy) const
{
	SIZE copied = {0};
	//m_map.Lock();
	//	copied = m_map.ExportData(ppBuffer, cx, cy);
	//m_map.Unlock();
	return copied;
}

void CCollisionMap::Invalidate(int x, int y)
{

	for (int i = -2; i <= 2; i++)
	{
		for (int j = -2; j <= 2; j++)
		{
			POINT p = {x + i, y + j};
			AbsToRelative(p);

			if (IsValidIndex(p))
			{
				m_map[p.x][p.y] = 1;
			}
		}
	}
}

BOOL CCollisionMap::IsGap(int x, int y)
{
	if (m_map[x][y] % 2)
		return FALSE;

	int nSpaces = 0;
	int i = 0;

	// Horizontal check
	for (i = x - 2; i <= x + 2 && nSpaces < 3; i++)
	{
		if (i < 0 || i >= m_map.GetCX() || (m_map[i][y] % 2))
			nSpaces = 0;
		else
			nSpaces++;
	}

	if (nSpaces < 3)
		return TRUE;

	// Vertical check
	nSpaces = 0;
	for (i = y - 2; i <= y + 2 && nSpaces < 3; i++)
	{
		if (i < 0 || i >= m_map.GetCY() || (m_map[x][i] % 2))
			nSpaces = 0;
		else
			nSpaces++;
	}

	return nSpaces < 3;
}

void CCollisionMap::FillGaps()
{
	const int CX = m_map.GetCX();
	const int CY = m_map.GetCY();

	for (int x = 0; x < CX; x++)
	{
		for (int y = 0; y < CY; y++)
		{
			if (IsGap(x, y))
			{
				m_map[x][y] = MAP_DATA_FILLED;
			}
		}
	}
}

BOOL CCollisionMap::ThickenWalls(int nThickenBy)
{
	if (nThickenBy <= 0)
	{
		return FALSE;
	}

	const int CX = m_map.GetCX();
	const int CY = m_map.GetCY();

	for (int i = 0; i < CX; i++)
	{
		for (int j = 0; j < CY; j++)
		{
			if ((m_map[i][j] % 2) == 0 || m_map[i][j] == MAP_DATA_THICKENED)
				continue;

			for (int x = i - nThickenBy; x <= i + nThickenBy; x++)
			{
				for (int y = j - nThickenBy; y <= j + nThickenBy; y++)
				{
					if (!IsValidIndex(x, y))
						continue;

					if ((m_map[x][y] % 2) == 0)
						m_map[x][y] = MAP_DATA_THICKENED;
				}
			}
		}
	}

	return TRUE;
}

void CCollisionMap::DestroyMap()
{
	//m_map.Lock();
	//m_map.Destroy();
	m_map.Destroy();
	//m_map.Unlock();
	m_iCurMap = 0x00;
	//m_aCollisionTypes.RemoveAll();
	::memset(&m_ptLevelOrigin, 0, sizeof(POINT));
}
