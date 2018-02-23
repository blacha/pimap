#include "CriticalSection.h"

CriticalSection::CriticalSection()
{
  InitializeCriticalSection(&_criticalsection);
}

CriticalSection::~CriticalSection()
{
  DeleteCriticalSection(&_criticalsection);
}

void CriticalSection::Lock()
{
  EnterCriticalSection(&_criticalsection);
}

void CriticalSection::Unlock()
{
  LeaveCriticalSection(&_criticalsection);
}