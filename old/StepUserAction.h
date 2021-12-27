
#ifndef PERSON_H_STEPUSERACTION_H
#define PERSON_H_STEPUSERACTION_H
#include "Action.h"
#include "FieldShow.h"


class StepUserAction: public Action{
public:
    StepUserAction(FieldShow* f, int del_x, int del_y){
        field = f;
        dx = del_x;
        dy = del_y;
    }

    void Work();

private:
    FieldShow* field;
    int dx;
    int dy;
};

#endif //PERSON_H_STEPUSERACTION_H
