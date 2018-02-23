#include "Thread.h"
#include "Log.h"

Thread::Thread() :
	_aborting(false),
	_running(false),
	_handle(0),
	_result(0),
	_id(-1)
{
}

Thread::~Thread()
{
}

bool Thread::Create(bool suspended)
{
	if (!IsRunning())
	{
		_handle = CreateThread(0, 0,
			reinterpret_cast<LPTHREAD_START_ROUTINE>(Router),
			reinterpret_cast<LPDWORD>(this), suspended ? CREATE_SUSPENDED : 0,
			reinterpret_cast<LPDWORD>(&_id));

		if (_handle)
			_running = true;

		return _handle != 0;
	}

	return false;
}

void Thread::Abort()
{
	if (IsRunning())
	{
        _abort.Lock();
		_aborting = true;
        _abort.Unlock();
	}
}

void Thread::Join()
{
	if (IsRunning())
	{
		WaitForSingleObject(_handle, INFINITE);
	}
}

bool Thread::Pause()
{
	if (IsRunning())
	{
		return SuspendThread(_handle) != 0xffffffff;
	}

	return false;
}

bool Thread::Resume()
{
	if (IsRunning())
	{
		return ResumeThread(_handle) != 0xffffffff;
	}

	return false;
}

bool Thread::IsRunning() const
{
	return _running;
}

bool Thread::IsAborting()
{
    bool Result;
    _abort.Lock();
	Result =  _aborting;
    _abort.Unlock();
    return Result;
}

int Thread::GetResult() const
{
	return _result;
}

int Thread::Router(void* data)
{
	Thread* thread = static_cast<Thread*>(data);

	thread->_running = true;
	thread->_aborting = false;

	try
	{
		thread->Routine();

		thread->_running = false;
		thread->_aborting = false;
		CloseHandle(thread->_handle);
		thread->_result = 0;
	}
	catch (char * message)
	{
		LOG(logERROR) << message;
		thread->_running = false;
		thread->_aborting = false;
		thread->_result = -1;
	}
	catch (...)
	{
		LOG(logERROR) << "unknown exception in thread router";
		thread->_running = false;
		thread->_aborting = false;
		thread->_result = -1;
	}

	thread->_handle = 0;
	thread->_id = -1;

	return thread->_result;
}
