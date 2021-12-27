#ifndef UNTITLED1_ITEMFACTORY_H
#define UNTITLED1_ITEMFACTORY_H

#include "item.h"

class ItemFactory{
public:
    virtual ~ItemFactory() = default;
    virtual item* CreateItem() =0;
};



#endif //UNTITLED1_ITEMFACTORY_H
