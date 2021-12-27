#ifndef UNTITLED1_CHICKENFACTORY_H
#define UNTITLED1_CHICKENFACTORY_H

#include "MonsterFactory.h"
#include "Chicken.h"

class ChickenFactory : public MonsterFactory{
public:
    Monster* CreateMob() override;
};

#endif //UNTITLED1_CHICKENFACTORY_H
