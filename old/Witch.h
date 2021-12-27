#ifndef UNTITLED1_WITCH_H
#define UNTITLED1_WITCH_H

#include "Monster.h"

class Witch : public Monster{
public:
    Witch(){
        hp_MAX=30;
        hp_NOW=hp_MAX;
        att=50;
        type=WI;
    }
    void battleCry() override;
};

#endif //UNTITLED1_WITCH_H
