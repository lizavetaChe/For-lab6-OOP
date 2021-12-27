#ifndef UNTITLED1_MEDICINE_H
#define UNTITLED1_MEDICINE_H

#include "item.h"

class medicine: public item{
public:
    medicine(int val){
        valiue = val;
        type = Med;
    };
    void what() override;
    void useItem(User *pl);
};


#endif //UNTITLED1_MEDICINE_H
