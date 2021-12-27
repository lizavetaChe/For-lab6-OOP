
#include "Field.h"

Field::Field(int W, int H): size({W,H}){
    Map = new Cell *[size.width];
    for (int i = 0; i < size.height; i++) {
        Map[i] = new Cell[size.height];
    }
    for (int i = 0; i < size.width; i++) {
        for (int j = 0; j < size.height; j++) {
            Map[i][j].setCoord(i, j);
        }
    }
};

Field::Field(const Field &other): size(other.size), Map(new Cell *[size.width]){
    for (int i = 0; i < size.width; i++) {
        Map[i] = new Cell[size.height];
        for (int j = 0; j < size.height; j++) {
            Map[i][j] = other.Map[i][j];
        }
    }
    First = other.First;
    Last = other.Last;
}

Field& Field::operator=(const Field &other){
    if (this!=&other){
        for (int i = 0; i < size.width; i++){
            delete[] Map[i];
        }
        delete[] Map;
        size = other.size;
        Map = new Cell *[size.width];
        for (int i = 0; i < size.width; i++) {
            Map[i] = new Cell[size.height];
            for (int j = 0; j < size.height; j++) {
                Map[i][j] = other.Map[i][j];
            }
        }
        First = other.First;
        Last = other.Last;
    }
    return *this;
}
Field::Field(Field &&other) noexcept{
    std::swap(size, other.size);
    std::swap(Map, other.Map);
    std::swap(First, other.First);
    std::swap(Last, other.Last);
}
Field& Field::operator=(Field &&other) noexcept{
    if (this != &other) {
        std::swap(size, other.size);
        std::swap(Map, other.Map);
        std::swap(First, other.First);
        std::swap(Last, other.Last);
    }
    return *this;
};

Size Field::getSize() const{
    return size;
}
Cell** Field::getMap(){
    return Map;
}
void Field::setLast(Cell* it){
    Last = it;
}

void Field::setFirst(Cell* it){
    First= it;
}

int Field::getCountB(){
    return CountB;
}
int Field::getCountE(){
    return CountE;
}
Cell* Field::FirstCell(){
    return First;
}
Cell* Field::LastCell(){
    return Last;
}

Field::~Field() {
    for (int i = 0; i < size.width; i++) {
        delete[] Map[i];
    }
    delete[] Map;
}

int Field::CheckStep(Cell& dot){
    int flag = 1;
    int x = dot.getCoord().x;
    int y = dot.getCoord().y;
    if (Map[x][y].getCellModel() != e){
        flag = 0;
    }
    if (Map[x][y].getItem() != nullptr){
        flag = 0;
    }
    if(Map[x][y].getMonster() != nullptr){
        flag = 0;
    }
    return flag;

}

int Field::Check(Cell& dot) {
    int x = dot.getCoord().x;
    int y = dot.getCoord().y;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (((x + i) >= 0 && (x + i) < size.width) && ((y + j) >=0 && (y + j) < size.height)) {
                if (Map[x+i][y+j].getCellModel() == barrier){
                    return 0;
                }
            }
            else{
                return 0;
            }
        }
    }
    return 1;
}

void Field::FieldGen(int C, int W, int H){
    srand(time(nullptr));
    int f = rand() % size.width;
    int l = rand() % size.width;
    Map[f][0].setCellModel(start);
    Map[l][size.height - 1].setCellModel(finish);
    First = &Map[f][0];
    Map[f][0].setUser(new User());
    Last = &Map[l][size.height - 1];
    ItemFactory* F1 = new medicineFactory();
    ItemFactory* F2 = new armorFactory();
    ItemFactory* F3 = new gunFactory();
    for (int i = 0; i < size.width; i++) {
        for (int j = 0; j < size.height; j++) {\
                if (i%2==1 && j%2==1 && j<size.height-1) {
                Map[i][j].setCellModel(barrier);
                CountB++;
            }
            if(Map[i][j].getCellModel() == e && (i==j || size.width-i-1==j)){
                int sub = rand() % 4;
                CountB++;
                switch(sub){
                    case 0:
                        Map[i][j].setItem(F1->CreateItem());
                        break;
                    case 1:
                        Map[i][j].setItem(F2->CreateItem());
                        break;
                    case 2:
                        Map[i][j].setItem(F3->CreateItem());
                        break;
                    case 3:
                        Map[i][j].setItem(nullptr);
                        break;
                }
            }
        }
    }
    CountChick = C;
    CountWitch = W;
    CountHunter = H;
    MonsterFactory* f1 = new ChickenFactory();
    MonsterFactory* f2 = new WitchFactory();
    MonsterFactory* f3 = new HunterFactory();
    MonsterFactory* f4 = new DragonFactory();
    for (int i = 0; i <size.width; i++) {
        for (int j = 0; j <size.height; j++) {
            if (CountWitch == 0 && CountHunter==0) {
                if (Map[i][j].getCellModel() == e && Map[i][j].getItem() == nullptr) {
                    Map[i][j].setMonster(f1->CreateMob());
                    CountChick--;
                }
            }
            else {
                if (Map[i][j].getCellModel() == e && Map[i][j].getItem() == nullptr) {
                    if (CountChick > 0 && j < size.height / 2 + 1 && i % 2 == 0 && j % 2 == 0) {
                        Map[i][j].setMonster(f1->CreateMob());
                        CountChick--;
                    }
                    if (CountWitch > 0 && Map[i][j].getMonster() == nullptr && (j % 3 == 0 && i % 2 == 1)) {
                        Map[i][j].setMonster(f2->CreateMob());
                        CountWitch--;
                    }
                    if (CountHunter > 0 && Map[i][j].getMonster() == nullptr) {
                        if ((i % 2 == 0 || j % 3 == 0) && j > size.height / 2) {
                            Map[i][j].setMonster(f3->CreateMob());
                            CountHunter--;
                        }
                    }
                }
            }
            if (Map[i][j].getCellModel() == finish){
                Map[i][j].setMonster(f4->CreateMob());
            }
        }
    }
}

void Field::change(){
    for (int i = 0; i < size.width; i++) {
        for (int j = 0; j < size.height; j++) {
            if (Map[i][j].getMonster() != nullptr) {
                if (Map[i][j].getMonster()->getMT() == CH){
                    Cell tmp;
                    int stepC = rand()%4;
                    switch(stepC) {
                        case 0:
                            if (i - 1 >= 0 && Map[i - 1][j].getUser()==nullptr) {
                                if (CheckStep(Map[i - 1][j]) == 1) {
                                    Map[i - 1][j].setMonster(Map[i][j].getMonster());
                                    Map[i][j].setMonster(nullptr);
                                }
                            }
                            break;
                        case 1:
                            if (j - 1 >= 0 && Map[i][j - 1].getUser()==nullptr) {
                                if (CheckStep(Map[i][j - 1]) == 1) {
                                    Map[i][j - 1].setMonster(Map[i][j].getMonster());
                                    Map[i][j].setMonster(nullptr);
                                }
                            }
                            break;
                        case 2:
                            if (i + 1 < size.width && Map[i + 1][j].getUser()==nullptr) {
                                if (CheckStep(Map[i + 1][j]) == 1) {
                                    Map[i + 1][j].setMonster(Map[i][j].getMonster());
                                    Map[i][j].setMonster(nullptr);
                                }
                            }
                            break;
                        case 3:
                            if (j + 1 < size.height && Map[i][j + 1].getUser()==nullptr) {
                                if (CheckStep(Map[i][j + 1]) == 1) {
                                    Map[i][j + 1].setMonster(Map[i][j].getMonster());
                                    Map[i][j].setMonster(nullptr);;
                                }
                            }
                            break;
                    }
                    continue;
                }
                if (Map[i][j].getMonster()->getMT() == HU){
                    Cell tmp;
                    int stepH = rand()%4;
                    switch(stepH){
                        case 0:
                            if (i-1>=0 && j-1>=0 && Map[i - 1][j - 1].getUser()==nullptr) {
                                if (CheckStep(Map[i - 1][j - 1]) == 1) {
                                    Map[i - 1][j - 1].setMonster(Map[i][j].getMonster());
                                    Map[i][j].setMonster(nullptr);
                                }
                            }
                            break;
                        case 1:
                            if (i+1<size.width && j+1<size.height && Map[i + 1][j - 1].getUser()==nullptr) {
                                if (CheckStep(Map[i + 1][j - 1]) == 1) {
                                    Map[i + 1][j - 1].setMonster(Map[i][j].getMonster());
                                    Map[i][j].setMonster(nullptr);
                                }
                            }
                            break;
                        case 2:
                            if (i-1>=0 && j+1<size.height && Map[i - 1][j + 1].getUser()==nullptr) {
                                if (CheckStep(Map[i - 1][j + 1]) == 1) {
                                    Map[i - 1][j + 1].setMonster(Map[i][j].getMonster());
                                    Map[i][j].setMonster(nullptr);
                                }
                            }
                            break;
                        case 3:
                            if(i+1<size.width && j-1>=0 && Map[i + 1][j - 1].getUser()==nullptr) {
                                if (CheckStep(Map[i + 1][j - 1]) == 1) {
                                    Map[i + 1][j - 1].setMonster(Map[i][j].getMonster());
                                    Map[i][j].setMonster(nullptr);;
                                }
                            }
                            break;
                    }
                    continue;
                }
            }
        }
    }
}

Cell* Field::StepUser(Cell* Place, int dx, int dy){
    int x = Place->getCoord().x;
    int y = Place->getCoord().y;
    if (x+dx>=0 && y+dy>=0 && x+dx<size.width && y+dy<size.height){
        if (Map[x+dx][y+dy].getCellModel()!= barrier){
            Map[x+dx][y+dy].setUser(Map[x][y].getUser());
            Map[x][y].setUser(nullptr);
            return &Map[x+dx][y+dy];
        }
    }
    return Place;
}

void Field::find(Cell& dom){
    if (dom.getUser()!=nullptr && dom.getItem()!=nullptr){
        dom.getItem()->what();
        dom.getItem()->useItem(dom.getUser());
        dom.setItem(nullptr);
    }

}
int Field::battle(Cell& dom){
    if (dom.getUser()!=nullptr && dom.getMonster()!=nullptr){
        dom.getMonster()->battleCry();
        if (dom.getMonster()->getMT() == DR){
            if (dom.getMonster()->getHp_NOW()-(dom.getUser()->getHp_NOW())<=0){
                //, Rule_Finish<bool>* Result
                //Result->SetRule_F(true);
                notify("Enemy defeated");
                notify("GAME OVER: positive ending");
                return 2;
            }
        }
        if (dom.getMonster()->getAtt()>=dom.getUser()->getHp_NOW()+dom.getUser()->getShield()){
            notify("GAME OVER: negative ending");
            return 0;
        }
        else{
            if (dom.getUser()->getAtt()>=dom.getMonster()->getHp_NOW()){
                dom.getUser()->setAtt(dom.getUser()->getAtt()-15);
                if (dom.getUser()->getAtt()<0){
                    dom.getUser()->setAtt(0);
                }
                dom.getUser()->setSH(dom.getUser()->getShield()-20);
                if (dom.getUser()->getShield()<0){
                    dom.getUser()->setHP_NOW(dom.getUser()->getHp_NOW()+dom.getUser()->getShield());
                    dom.getUser()->setSH(0);
                }
                notify("Enemy defeated");
                dom.setMonster(nullptr);
            }
            else{
                dom.getUser()->setSH(dom.getUser()->getShield()-dom.getMonster()->getAtt());
                dom.getUser()->setAtt(dom.getUser()->getAtt()-15);
                if(dom.getUser()->getAtt()<0){
                    dom.getUser()->setAtt(0);
                }
                if (dom.getUser()->getShield()<0){
                    dom.getUser()->setHP_NOW(dom.getUser()->getHp_NOW()+dom.getUser()->getShield());
                    dom.getUser()->setSH(0);
                }
                notify("Enemy is not defeated");
            }
        }
    }
    return 1;
}