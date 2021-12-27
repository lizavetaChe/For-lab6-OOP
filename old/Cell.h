#ifndef UNTITLED1_CELL_H
#define UNTITLED1_CELL_H

#include "Monster.h"
#include "User.h"
#include "item.h"
typedef struct Point{
    int x;
    int y;
}Point;

enum Type{e, barrier, start, finish};
class Cell{
public:
    explicit Cell(): CellModel(e), Coord({0,0}), it(nullptr), enemy(nullptr){};

    void setCellModel(Type model);
    void setCoord(int xi, int yi);
    void setItem(item* obj);
    void setMonster(Monster* M);
    void setUser(User* I);
    Type getCellModel() const;
    Point getCoord() const;
    Monster* getMonster();
    User* getUser();
    item* getItem() const;

private:
    Type CellModel;
    Point Coord;
    item* it;
    Monster* enemy;
    User* player;
};


#endif //UNTITLED1_CELL_H
