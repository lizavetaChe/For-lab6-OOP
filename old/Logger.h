#ifndef PERSON_H_LOGGER_H
#define PERSON_H_LOGGER_H
#include <vector>
#include <string>
#include <iostream>


class Logger{
public:
    ~Logger() = default;
    virtual void print(std::string logString) = 0;
    void setLog(std::string logString);
    void addLog(std::string logString);
    std::string log;
private:
    int count = 0;

};



#endif //PERSON_H_LOGGER_H
