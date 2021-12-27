#ifndef PERSON_H_FILELOGGER_H
#define PERSON_H_FILELOGGER_H

#include "Logger.h"
#include <utility>
#include "fstream"

class FileLogger: public Logger{
public:
    explicit FileLogger() : fileName("LOG.txt"), count(0){out.open(fileName); out.close(); out.open(fileName, std::ios::app);};
    ~FileLogger() {out.close();};
    void print(std::string logString) final;
    friend std::ostream& operator<< (std::ostream &out, const FileLogger &logger);
private:
    std::string fileName;
    std::ofstream out;
    int count;
};



#endif //PERSON_H_FILELOGGER_H
