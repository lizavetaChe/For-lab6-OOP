#ifndef UNTITLED1_HUNTERFACTORY_H
#define UNTITLED1_HUNTERFACTORY_H

#include "Hunter.h"
#include "MonsterFactory.h"

class HunterFactory : public MonsterFactory{
public:
    Monster* CreateMob()  override;
};

#endif //UNTITLED1_HUNTERFACTORY_H
