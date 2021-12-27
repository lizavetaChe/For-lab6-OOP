#ifndef UNTITLED1_PERSON_H
#define UNTITLED1_PERSON_H

#include "Observable.h"

class Person{
public:
    void setHP_NOW(int hp);
    void setAtt(int at);
    void setSH(int sh);
    int getHp_NOW();
    int getAtt();
    int getShield();

protected:
    int hp_MAX;
    int hp_NOW;
    int att;
    int shield;
};


#endif //UNTITLED1_PERSON_H
