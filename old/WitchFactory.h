#ifndef UNTITLED1_WITCHFACTORY_H
#define UNTITLED1_WITCHFACTORY_H

#include "Witch.h"
#include "MonsterFactory.h"

class WitchFactory : public MonsterFactory{
public:
    Monster* CreateMob() override;
};


#endif //UNTITLED1_WITCHFACTORY_H
