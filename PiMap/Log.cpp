// #include "AwesomO.h"
#include "Log.h"
#include <time.h>

std::ofstream Log::of;

TLogLevel Log::ReportingLevel = logDEBUG3;

CriticalSection Log::cs;

std::string ToString(TLogLevel level)
{
	switch (level)
	{
		case logERROR: return "Error";
		case logWARNING: return "Warning";
		case logINFO: return "Info";
		default: return "Debug";
	}
}

std::ostringstream& Log::Get(TLogLevel level)
{
	cs.Lock();
	time_t t;
	t = time(0);
	struct tm *lt = localtime( &t );
	char tme[20];
	sprintf_s(tme, sizeof(tme), "%02d-%02d-%02d %02d:%02d:%02d", lt->tm_year + 1900, lt->tm_mon+1, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
	os << tme << " | " << ToString(level) << ": ";
	messageLevel = level;
	cs.Unlock();
	return os;
}


Log::Log() {

}

Log::~Log()
{
	cs.Lock();
	std::cout << os.str() << std::endl;
	fflush(stdout);

	if(Log::of.is_open())
	{
		Log::of <<  os.str() << std::endl;
		Log::of.flush();
	}
	cs.Unlock();
}
