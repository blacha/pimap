#ifndef CRITICALSECTION_H
#define CRITICALSECTION_H

#include <windows.h>

class CriticalSection
{
public:
    CriticalSection();
    ~CriticalSection();

    void Lock();

    void Unlock();
private:
    CRITICAL_SECTION _criticalsection;
};

#endif //CRITICALSECTION_H
