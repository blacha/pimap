#pragma once

#include <sstream>
#include <iostream>
#include <fstream>
#include "CriticalSection.h"

enum TLogLevel
{
    logERROR,
    logWARNING,
    logINFO,
    logDEBUG,
    logDEBUG1,
    logDEBUG2,
    logDEBUG3,
    logDEBUG4
};

#define LOG(level)                   \
    if (level > Log::ReportingLevel) \
        ;                            \
    else                             \
        Log().Get(level)

class Log
{
  public:
    Log();

    virtual ~Log();
    std::ostringstream &Get(TLogLevel level = logINFO);

  public:
    static TLogLevel ReportingLevel;
    static std::ofstream of;
    static CriticalSection cs;

  protected:
    std::ostringstream os;

  private:
    Log(const Log &);
    Log &operator=(const Log &);

  private:
    TLogLevel messageLevel;
};
