
#include "FieldShow.h"

FieldShow::FieldShow(int H, int W){
    Card=new Field(H, W);
};

Field* FieldShow::getCard(){
    return Card;
}
void FieldShow::FieldView(){
    for (int i=0; i<Card->getSize().height;i++){
        for (int j=0; j<Card->getSize().width;j++) {
            if (Card->getMap()[i][j].getUser()!=nullptr){
                std::cout << '^' << ' ';
                continue;
            }
            else {
                if (Card->getMap()[i][j].getMonster() != nullptr) {
                    if (Card->getMap()[i][j].getMonster()->getMT() == CH) {
                        std::cout << "C" << ' ';
                        continue;
                    }
                    if (Card->getMap()[i][j].getMonster()->getMT() == WI) {
                        std::cout << "W" << ' ';
                        continue;
                    }
                    if (Card->getMap()[i][j].getMonster()->getMT() == HU) {
                        std::cout << "H" << ' ';
                        continue;
                    }
                }
                if (Card->getMap()[i][j].getCellModel() == 2) {
                    std::cout << "#" << ' ';
                    continue;
                }
                if (Card->getMap()[i][j].getCellModel() == 3){
                    std::cout << "D" << ' ';
                    continue;
                }
                if (Card->getMap()[i][j].getItem() != nullptr) {
                    std::cout << "+" << ' ';
                    continue;
                }
                else {
                    std::cout << Card->getMap()[i][j].getCellModel() << ' ';
                }
            }
        }
        std::cout << '\n';
    }
}

Cell* FieldShow::getPlace(){
    return place;
}

Logger* FieldShow::setPROXY(Logger* p){
    proxy = p;
}

bool FieldShow::getCont(){
    return Cont;
}

void FieldShow::setCont(bool c){
    Cont = c;
}

void FieldShow::TURN(){
    int l;
    this->getCard()->change();
    if (this->getCard()->getMap()[this->place->getCoord().x][this->place->getCoord().y].getItem()!= nullptr){
        View v1=View(this->getCard()->getMap()[this->place->getCoord().x][this->place->getCoord().y].getItem(),proxy);
    }
    this->getCard()->find(this->getCard()->getMap()[this->place->getCoord().x][this->place->getCoord().y]);
    if (this->getCard()->getMap()[this->place->getCoord().x][this->place->getCoord().y].getMonster()!= nullptr){
        View v2=View(this->getCard()->getMap()[this->place->getCoord().x][this->place->getCoord().y].getMonster(),proxy);
    }
    View v3 = View(this->getCard(), proxy);
    l = this->getCard()->battle(this->getCard()->getMap()[this->place->getCoord().x][this->place->getCoord().y]);
    if (l==0){
        std::cout << "    [You died]";
        Cont = false;
    }
    if (l==2){
        std::cout << "    [You win]";
        Cont = false;
    }
}