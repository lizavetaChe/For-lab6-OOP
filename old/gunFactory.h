#ifndef UNTITLED1_GUNFACTORY_H
#define UNTITLED1_GUNFACTORY_H

#include "ItemFactory.h"
#include "gun.h"

class gunFactory : public ItemFactory{
public:
    item* CreateItem()  override;
};

#endif //UNTITLED1_GUNFACTORY_H
