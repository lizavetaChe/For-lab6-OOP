#ifndef UNTITLED1_MONSTER_H
#define UNTITLED1_MONSTER_H

#include <iostream>
#include "Person.h"


enum monster_type{CH, WI, HU, DR};
class Monster : public Person, public Observable{
public:
    virtual void battleCry() =0;
    monster_type getMT();
protected:
    monster_type type;
};

#endif //UNTITLED1_MONSTER_H
