
#include "ConcMediator.h"

void ConcMediator::Send(Colleague* colleague,std::string str){
    if(str=="LVL"){
        g->Gameplay();
    }
    if (str=="Logger setted up"){
        g->setLogger(lg->getLog());
        pr->Menu();
    }
    if (str=="OLD")
    {
        lg->setLogger_old();
        g->setLogger(lg->getLog());
        g->f->setPROXY(lg->getLog());
        g->Gameplay();
    }
    if (str=="Menu done"){
        g->setField(pr->getFieldShow());
        g->generator();
    }
    if (str=="End"){
        g->ChangeStatus();
    }
    if (str=="NEED INFO"){
        pr->Condition();
    }
    if (str=="YA VSE SDELAL"){
        g->Gameplay();
    }
    if (str=="save"){
        g->Save();
    }
    if (str=="load"){
        g->Load();
    }
}