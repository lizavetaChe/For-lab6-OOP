#ifndef UNTITLED1_ITEM_H
#define UNTITLED1_ITEM_H

#include <iostream>
#include "User.h"
#include "Observable.h"

enum item_type{Med, Arm, Gun};

class item: public Observable{
public:
    virtual void what() = 0;
    int getValiue();
    virtual void useItem(User* pl) = 0;
    item_type getItemType();
protected:
    int valiue;
    item_type type;
};

#endif //UNTITLED1_ITEM_H
