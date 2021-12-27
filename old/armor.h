#ifndef UNTITLED1_ARMOR_H
#define UNTITLED1_ARMOR_H

#include "item.h"

class armor: public item{
public:
    armor(int val){
        valiue = val;
        type = Arm;
    };
    void what() override;
    void useItem(User *pl);
};

#endif //UNTITLED1_ARMOR_H
