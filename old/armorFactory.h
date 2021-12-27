#ifndef UNTITLED1_ARMORFACTORY_H
#define UNTITLED1_ARMORFACTORY_H

#include "ItemFactory.h"
#include "armor.h"

class armorFactory : public ItemFactory{
public:
    item* CreateItem()  override;
};


#endif //UNTITLED1_ARMORFACTORY_H
