
#ifndef PERSON_H_MEDIATOR_H
#define PERSON_H_MEDIATOR_H

#include "FieldShow.h"
class Colleague;

class Mediator{
public:
    virtual void Send(Colleague* colleague,std::string str)=0;
};


#endif //PERSON_H_MEDIATOR_H
