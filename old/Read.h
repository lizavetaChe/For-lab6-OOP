
#ifndef PERSON_H_READ_H
#define PERSON_H_READ_H

#include <iostream>
#include "PrintAction.h"
#include "EndAction.h"
#include "StepUserAction.h"
#include "SaveAction.h"
#include "LoadAction.h"


class Read{
public:
    Read(FieldShow* field, Mediator* m){
        f = field;
        mediator = m;
    }

    void setF(FieldShow* f_){
        f=f_;
    }

    void setINPUT();

private:
    Action* act;
    FieldShow* f;
    Mediator* mediator;
};


#endif //PERSON_H_READ_H
