#include "LogProxy.h"

LogProxy::LogProxy(int loggerType){
    switch (loggerType){
        case 1:
            vec.push_back(new FileLogger());
            break;
        case 2:
            vec.push_back(new TerminalLogger());
            break;
        case 3:
            vec.push_back(new FileLogger());
            vec.push_back(new TerminalLogger());
            break;
    }
}

void LogProxy::addLog(std::string logString){
    for(int i = 0; i<vec.size(); i++){
        vec[i]->addLog(logString);
    }
}

void LogProxy::print(std::string logString){
    addLog(logString);
   for(int i = 0; i<vec.size(); i++){
       vec[i]->print(" ");
   }
}



