
#ifndef PERSON_H_SAVEACTION_H
#define PERSON_H_SAVEACTION_H
#include "Action.h"
#include "Colleague.h"

class SaveAction: public Action, public Colleague{
public:
    SaveAction(Mediator* m){
        mediator = m;
    }
    void Work(){
        mediator->Send(this,"save");
    }

private:
    Mediator* mediator;
};


#endif //PERSON_H_SAVEACTION_H
