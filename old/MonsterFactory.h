#ifndef UNTITLED1_MONSTERFACTORY_H
#define UNTITLED1_MONSTERFACTORY_H

#include "Monster.h"

class MonsterFactory{
public:
    virtual ~MonsterFactory() = default;
    virtual Monster* CreateMob() =0;
};


#endif //UNTITLED1_MONSTERFACTORY_H
