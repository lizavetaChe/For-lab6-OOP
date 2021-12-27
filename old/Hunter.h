#ifndef UNTITLED1_HUNTER_H
#define UNTITLED1_HUNTER_H

#include "Monster.h"

class Hunter : public Monster{
public:
    Hunter(){
        hp_MAX=70;
        hp_NOW=hp_MAX;
        att=70;
        type=HU;
    }
    void battleCry() override;
};


#endif //UNTITLED1_HUNTER_H
