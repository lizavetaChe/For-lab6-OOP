
#include "Cell.h"

void Cell::setCellModel(Type model){
    CellModel = model;
}

void Cell::setCoord(int xi, int yi){
    Coord.x=xi;
    Coord.y=yi;
}

void Cell::setItem(item* obj){
    it = obj;
}

void Cell::setMonster(Monster* M){
    enemy = M;
}

void Cell::setUser(User* I){
    player = I;
}

Type Cell::getCellModel() const{
    return CellModel;
}
item* Cell::getItem() const{
    return it;
}

Point Cell::getCoord() const{
    return Coord;
}

Monster* Cell::getMonster(){
    return enemy;
}

User* Cell::getUser(){
    return player;
}
