
#include "armorFactory.h"

item* armorFactory::CreateItem(){
    return new armor(30);
}