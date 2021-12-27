#ifndef UNTITLED1_GUN_H
#define UNTITLED1_GUN_H

#include "item.h"

class gun: public item{
public:
    gun(int val){
        valiue = val;
        type = Gun;
    };
    void what() override;
    void useItem(User *pl) ;
};


#endif //UNTITLED1_GUN_H
