#ifndef PERSON_H_TERMINALLOGGER_H
#define PERSON_H_TERMINALLOGGER_H

#include "Logger.h"

class TerminalLogger : public Logger{
public:
    TerminalLogger() : count(0) {};
    void print(std::string logString) final;
    friend std::ostream& operator<< (std::ostream &out, const TerminalLogger &logger);
    ~TerminalLogger()=default;
private:
    int count;
};



#endif //PERSON_H_TERMINALLOGGER_H
