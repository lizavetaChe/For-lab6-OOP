
#include "FileLogger.h"

void FileLogger::print(std::string logString){
    if (out.is_open()){
        count++;
        out << *this << std::endl;
    }
}

std::ostream& operator<< (std::ostream &out, const FileLogger &logger){
    out << logger.count << " [ LOG ] : " << logger.log;
    return out;
}