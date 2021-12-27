
#include "medicineFactory.h"

item* medicineFactory::CreateItem(){
    return new medicine(50);
}