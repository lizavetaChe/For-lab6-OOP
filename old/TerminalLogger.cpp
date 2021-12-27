#include "TerminalLogger.h"

void TerminalLogger::print(std::string logString) {
    count++;
    std::cout << *this  << std::endl;
}

std::ostream& operator<< (std::ostream &out, const TerminalLogger &logger){
    out << logger.count << " [LOG] : " << logger.log;
    return out;
}
