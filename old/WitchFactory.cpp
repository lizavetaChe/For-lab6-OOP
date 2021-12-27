
#include "WitchFactory.h"

Monster* WitchFactory::CreateMob(){
    return new Witch();
}