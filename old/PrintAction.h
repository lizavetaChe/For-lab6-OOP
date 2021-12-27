
#ifndef PERSON_H_PRINTACTION_H
#define PERSON_H_PRINTACTION_H
#include "Action.h"
#include "Colleague.h"


class PrintAction: public Action, public Colleague{
public:
    PrintAction(Mediator* m){
        mediator = m;
    }
    void Work(){
        mediator->Send(this,"NEED INFO");
    }

private:
    Mediator* mediator;
};


#endif //PERSON_H_PRINTACTION_H
