
#include "gunFactory.h"

item* gunFactory::CreateItem(){
    return new gun(40);
}