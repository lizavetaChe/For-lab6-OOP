#ifndef PERSON_H_LOGPROXY_H
#define PERSON_H_LOGPROXY_H

#include "Logger.h"
#include "FileLogger.h"
#include "TerminalLogger.h"
#include <vector>

class LogProxy: public Logger{
public:
    explicit LogProxy(int loggerType);
    void print(std::string logString);
    void addLog(std::string logString);
    ~LogProxy()=default;
private:
    Logger *logger;
    std::vector< Logger* > vec;
};

#endif //PERSON_H_LOGPROXY_H
