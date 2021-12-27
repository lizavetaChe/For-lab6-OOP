#ifndef UNTITLED1_DRAGONFACTORY_H
#define UNTITLED1_DRAGONFACTORY_H

#include "Dragon.h"
#include "MonsterFactory.h"

class DragonFactory : public MonsterFactory{
public:
    Monster* CreateMob()  override;
};

#endif //UNTITLED1_DRAGONFACTORY_H
