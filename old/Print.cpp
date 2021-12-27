
#include "Print.h"

#include <iostream>


void Print::Menu(){
    int W, H;
    std::cout << "Введите размер игрового поля в формате: высота ширина\n";
    std::cin >> H >> W;
    std::cout << "Для движения по карте используйте клавиши - {w,s,a,d}; \n";
    std::cout << "Для получния инфорации о состоянии героя - {q}; \n";
    std::cout << "Для завершения игры - {e}. \n";
    std::cout << "Для сохранения игры - {x}. \n";
    std::cout << "Для запуска сохранённой игры - {z}. \n";
    f=new FieldShow(H,W);
    mediator->Send(this,"Menu done");
}

FieldShow* Print::getFieldShow() {
    return f;
}

void Print::Condition(){
    std::cout << "HP = "<<f->getCard()->getMap()[f->place->getCoord().x][f->place->getCoord().y].getUser()->getHp_NOW() <<'\n';
    std::cout << "ATT = "<<f->getCard()->getMap()[f->place->getCoord().x][f->place->getCoord().y].getUser()->getAtt() <<'\n';
    std::cout << "SH = "<<f->getCard()->getMap()[f->place->getCoord().x][f->place->getCoord().y].getUser()->getShield() <<'\n';
    mediator->Send(this,"YA VSE SDELAL");
}