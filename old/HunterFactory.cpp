
#include "HunterFactory.h"

Monster* HunterFactory::CreateMob(){
    return new Hunter();
}