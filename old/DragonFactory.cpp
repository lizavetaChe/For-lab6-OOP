
#include "DragonFactory.h"

Monster* DragonFactory::CreateMob(){
    return new Dragon();
}