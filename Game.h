#ifndef PERSON_H_GAME_H
#define PERSON_H_GAME_H
#include "Logger.h"
#include <iostream>
using namespace std;
#include "FieldShow.h"
#include "View.h"
#include "Colleague.h"
#include "Rule_Finish.h"
#include "Read.h"
#include "New_Exception.h"

template <typename LVL, typename RES>
class Game:public Colleague {
public:
    Game(LVL l, RES R): Rule(l), Result(R){}

    void setLogger(Logger* lg){
        proxy=lg;
    }

    void setField(FieldShow* f1){
        f=f1;
    }

    void generator(){
        int E = f->Card->getSize().width * f->Card->getSize().height;
        f->Card->FieldGen(Rule.CountChicken(E), Rule.CountWitch(E), Rule.CountHunter(E));
        f->place = f->Card->FirstCell();
        f->setPROXY(proxy);
        mediator->Send(this, "LVL");
    }
    void setMediator(Mediator* m){
        mediator = m;
    }
    bool ChangeStatus(){
        f->setCont(false);
    }
    void Gameplay(){
        read = new Read(f, mediator);
        f->FieldView();
        while(f->getCont()){
            read->setINPUT();
            if (f->getCont()==true)
                f->FieldView();
            if (loaded){
                read->setF(f);
                loaded=false;
            }
        }
    }

    void Save(){
        std::ofstream out("Save.txt");
        int H = f->getCard()->getSize().height;
        int W = f->getCard()->getSize().height;
        int st = f->getCont();
        out << st << std::endl;
        out << H << ' ' << W << std::endl;
        for (int i=0;i<H;i++){
            for (int j=0;j<W;j++){
                out << i << ' ' << j << ' ' << f->getCard()->getMap()[i][j].getCellModel();
                if (f->getCard()->getMap()[i][j].getItem() != nullptr) {
                    out << ' ' << 1;
                    out << ' ' << f->getCard()->getMap()[i][j].getItem()->getItemType() << std::endl;
                }
                else{
                    if (f->getCard()->getMap()[i][j].getMonster() != nullptr) {
                        out << ' ' << 2;
                        out << ' ' << f->getCard()->getMap()[i][j].getMonster()->getMT() << std::endl;
                    }
                    else{
                        out << ' ' << 0 << ' ' << 0 << std::endl;
                    }
                }
            }
        }
        out << f->getPlace()->getCoord().x << ' ' << f->getPlace()->getCoord().y << std::endl;
        out << f->getPlace()->getUser()->getHp_NOW() << ' '
            << f->getPlace()->getUser()->getShield() << ' '
            << f->getPlace()->getUser()->getAtt() << std::endl;
        out.close();
    }

    void Load(){
        std::ifstream in("Save.txt");
        if (!in.is_open()) {
            throw New_Exception(ErrFile);
        }
        bool st;
        int a,b,c,d;
        int H,W;
        in >> st;
        if (st == false){
            throw New_Exception(No_game);
        }
        in >> a >> b;
        H=a;
        W=b;
        if (a<2 || b<2)
           throw New_Exception(ErrValue);
        FieldShow* TMP_Field = new FieldShow(H, W);
        for (int i=0;i<a;i++){
            for (int j=0;j<b;j++){
                int h, w, type_cell, obj, type_obj;
                Cell* tempCell=new Cell();
                in >> h >> w >> type_cell >> obj >> type_obj;
                if (h>=a || w>=b || h<0 || w<0){
                    if (type_cell>3 || type_cell<0){
                        if (obj>2 || obj<0){
                            if (type_obj>4 || type_obj<0) {
                                delete tempCell;
                                delete TMP_Field;
                                throw New_Exception(ErrValue);
                            }
                        }
                    }
                }
                tempCell->setCoord(h,w);
                switch(type_cell){
                    case 0:
                        tempCell->setCellModel(e);
                        break;
                    case 1:
                        tempCell->setCellModel(barrier);
                        break;
                    case 2:
                        tempCell->setCellModel(start);
                        TMP_Field->getCard()->setFirst(tempCell);
                        break;
                    case 3:
                        tempCell->setCellModel(finish);
                        TMP_Field->getCard()->setFirst(tempCell);
                        break;
                }
                switch(obj){
                    case 0:
                        break;
                    case 1:
                        switch (type_obj){
                            case 0:
                                tempCell->setItem(new medicine(50));
                                break;
                            case 1:
                                tempCell->setItem(new armor(30));
                                break;
                            case 2:
                                tempCell->setItem(new gun(50));
                                break;
                        }
                        break;
                    case 2:
                        switch (type_obj){
                            case 0:
                                tempCell->setMonster(new Chicken);
                                break;
                            case 1:
                                tempCell->setMonster(new Witch);
                                break;
                            case 2:
                                tempCell->setMonster(new Hunter);
                                break;
                            case 3:
                                tempCell->setMonster(new Dragon);
                                break;
                        }
                        break;
                    break;
                }
                TMP_Field->getCard()->getMap()[h][w]=*tempCell;
            }
        }
        User* TMP_User=new User();
        in >> a >> b;
        if (a>=H || b >= W || a<0 || b<0) {
            delete TMP_Field;
            throw New_Exception(ErrValue);
         }
        TMP_Field->getCard()->getMap()[a][b].setUser(TMP_User);
        TMP_Field->place=&TMP_Field->getCard()->getMap()[a][b];
        in >> a >> b >> c;
        if (a<0 || b<0 || c<0) {
            delete TMP_Field;
            delete TMP_User;
            throw New_Exception(ErrValue);
        }
        TMP_User->setHP_NOW(a);
        TMP_User->setSH(b);
        TMP_User->setAtt(c);
        TMP_Field->setPROXY(f->getProxy());
        f=TMP_Field;
        loaded=true;
    }
    FieldShow* f;
private:
    Logger* proxy;
    LVL Rule;
    RES Result;
    Read* read;
    Mediator* mediator;
    bool loaded;
};


#endif //PERSON_H_GAME_H
