
#ifndef PERSON_H_SETLOG_H
#define PERSON_H_SETLOG_H

#include "Colleague.h"
#include "LogProxy.h"


class SetLOG : public Colleague{
public:
    LogProxy* setLogger();
    LogProxy* setLogger_old();
    void mess();
    void mess_old();
    LogProxy* getLog();
private:
    LogProxy* proxy;
};


#endif //PERSON_H_SETLOG_H
