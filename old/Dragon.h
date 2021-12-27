#ifndef UNTITLED1_DRAGON_H
#define UNTITLED1_DRAGON_H

#include "Monster.h"

class Dragon : public Monster{
public:
    Dragon(){
        hp_MAX=150;
        hp_NOW=hp_MAX;
        att=100;
        type=DR;
    }
    void battleCry() override;
};


#endif //UNTITLED1_DRAGON_H
