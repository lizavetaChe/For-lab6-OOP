#ifndef PERSON_H_COLLEAGUE_H
#define PERSON_H_COLLEAGUE_H

#include "Mediator.h"

class Colleague{
public:
    Colleague(Mediator* Manager=nullptr):mediator(Manager){};
    void set_mediator(Mediator* mediator1);
protected:
    Mediator* mediator;
};


#endif //PERSON_H_COLLEAGUE_H
