//
// Created by Chaz on 8/27/2017.
//

#ifndef DUNGEONENGINE_LOGGER_H
#define DUNGEONENGINE_LOGGER_H

#include <string>
#include <boost/iostreams/stream.hpp>
#include "Formatter.h"

enum class Severity
{
    Info = 0,
    Debug = 1,
    Warning = 2,
    Error = 3,
    Critical = 4
};

class LoggerBase {
public:
    LoggerBase(Severity lowest):mLowestSeverity(lowest){}
    ~LoggerBase(){}

    template <typename ...Args>
    void log(Severity s, Args... a)
    {
        if(s >= mLowestSeverity)
        {
            mFormatter << s << ... << a << "\n";
            log_internal(mFormatter.str());
            mFormatter.clear();
        }
    }

private:
    Severity mLowestSeverity;
    Formatter mFormatter;

    virtual void log_internal(const std::string&) = 0;
};

class NullLogger : public LoggerBase
{
public:
    NullLogger(): LoggerBase(Severity::Info){}

    virtual void log_internal(const std::string&){}
};

class StreamLogger : public LoggerBase
{
public:
    StreamLogger(Severity severity, std::ostream& stream) : LoggerBase(severity), mStream(stream){}

    virtual void log_internal(const std::string& str){mStream << str;}

private:
    std::ostream& mStream;
};


#endif //DUNGEONENGINE_LOGGER_H
