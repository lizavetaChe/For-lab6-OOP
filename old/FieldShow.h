#ifndef UNTITLED1_FIELDSHOW_H
#define UNTITLED1_FIELDSHOW_H

#include <iostream>
#include "Cell.h"
#include "Field.h"
#include "View.h"

class FieldShow{
public:
    Cell* place;
    Field* Card;
    FieldShow(int H, int W);
    Field* getCard();
    void FieldView();
    Cell* getPlace();
    Logger* setPROXY(Logger* p);
    bool getCont();
    void setCont(bool c);
    void TURN();
    Logger* getProxy(){
        return proxy;
    }

private:
    bool Cont = true;
    Logger* proxy;
};

#endif //UNTITLED1_FIELDSHOW_H
