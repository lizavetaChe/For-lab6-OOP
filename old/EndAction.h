
#ifndef PERSON_H_ENDACTION_H
#define PERSON_H_ENDACTION_H
#include "Action.h"
#include "Colleague.h"

class EndAction: public Action, public Colleague{
public:
    EndAction(Mediator* m){
        mediator = m;
    }
    void Work(){
        mediator->Send(this, "End");
    }

private:
    Mediator* mediator;
};


#endif //PERSON_H_ENDACTION_H
