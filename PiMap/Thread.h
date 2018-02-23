#ifndef THREAD_H
#define THREAD_H

#include <windows.h>
#include "CriticalSection.h"

class Thread
{
public:
	Thread();
	virtual ~Thread();

	bool Create(bool suspended);
	void Abort();
	void Join();
	bool Pause();
	bool Resume();
	bool IsRunning() const;
	bool IsAborting();
	int GetResult() const;

protected:
	virtual int Routine() = 0;

private:
	static int Router(void* data);

	CriticalSection _abort;
	HANDLE _handle;
	int _result;
	bool _running;
	bool _aborting;
	int _id;
};

#endif //THREAD_H
