#include "Logger.h"

void Logger::setLog(std::string logString){
    this->log = logString;
}
void Logger::addLog(std::string logString){
    log = " ";
    log += logString;
}

