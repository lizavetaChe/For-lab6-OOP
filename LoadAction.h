
#ifndef PERSON_H_LOADACTION_H
#define PERSON_H_LOADACTION_H
#include "Action.h"
#include "Colleague.h"

class LoadAction: public Action, public Colleague{
public:
    LoadAction(Mediator* m){
        mediator = m;
    }
    void Work(){
        mediator->Send(this,"load");
    }

private:
    Mediator* mediator;
};

#endif //PERSON_H_LOADACTION_H
