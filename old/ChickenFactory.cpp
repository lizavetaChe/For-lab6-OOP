
#include "ChickenFactory.h"

Monster* ChickenFactory::CreateMob(){
    return new Chicken();
}