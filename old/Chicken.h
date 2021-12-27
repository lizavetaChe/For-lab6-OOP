#ifndef UNTITLED1_CHICKEN_H
#define UNTITLED1_CHICKEN_H

#include "Monster.h"

class Chicken : public Monster{
public:
    Chicken(){
        hp_MAX=10;
        hp_NOW=hp_MAX;
        att=10;
        type=CH;
    }
    void battleCry() override;
};


#endif //UNTITLED1_CHICKEN_H
