#ifndef PERSON_H_CONCMEDIATOR_H
#define PERSON_H_CONCMEDIATOR_H
#include "Print.h"
#include "SetLOG.h"
#include "Game.h"

class ConcMediator: public Mediator{
public:
    ConcMediator(Print* pr,SetLOG* lg):pr(pr),lg(lg){
        this->pr->set_mediator(this);
        this->lg->set_mediator(this);
    }
    void Send(Colleague* colleague,std::string str);
    void setGame(Game<Rule_CountMonster<int>, Rule_Finish<bool>>* it){
        g = it;
    }
private:
    Print* pr;
    SetLOG* lg;
    Game<Rule_CountMonster<int>, Rule_Finish<bool>>* g;
};


#endif //PERSON_H_CONCMEDIATOR_H
