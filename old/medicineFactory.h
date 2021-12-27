#ifndef UNTITLED1_MEDICINEFACTORY_H
#define UNTITLED1_MEDICINEFACTORY_H

#include "ItemFactory.h"
#include "medicine.h"

class medicineFactory : public ItemFactory{
public:
    item* CreateItem() override;
};


#endif //UNTITLED1_MEDICINEFACTORY_H
