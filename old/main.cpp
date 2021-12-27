#include <iostream>
#include "FieldShow.h"
#include "View.h"
#include "SetLOG.h"
#include "Print.h"
#include "Logger.h"
#include "ConcMediator.h"


using namespace std;

void RUN(){
    int c;
    std::cout << "Если вы хотите продолжить старую игру введите: 0\n";
    std::cout << "При вводе иного символа - начнётся новая игра\n";
    std::cin >> c;
    Print* pr=new Print();
    SetLOG* lg=new SetLOG();
    ConcMediator* mediator=new ConcMediator(pr,lg);
    Logger* proxy;
    if (c==0){
        Game<Rule_CountMonster<int>, Rule_Finish<bool>>* g=new Game<Rule_CountMonster<int>, Rule_Finish<bool>>(0, 0);
        try{
            g->Load();
        }
        catch (New_Exception& exception) {
            std::cerr << exception.getMessage();
            return;
        }
        mediator->setGame(g);
        g->setMediator(mediator);
        proxy = lg->setLogger_old();
        lg->mess_old();
        return;
    }
    else{
        int l;
        std::cout << "ВЫБЕРИТЕ УРОВЕНЬ СЛОЖНОСТИ:\n";
        std::cout << "Easy: 1\n";
        std::cout << "Medium: 2\n";
        std::cout << "Hard: 3\n";
        std::cout << "Surprise: other :)\n";
        cin >> l;
        Rule_CountMonster<int> L = Rule_CountMonster<int>(l);
        Rule_Finish<bool> R = Rule_Finish<bool>(false);
        Game<Rule_CountMonster<int>, Rule_Finish<bool>>* g=new Game<Rule_CountMonster<int>, Rule_Finish<bool>>(L, R);
        mediator->setGame(g);
        g->setMediator(mediator);
        lg->setLogger();
        lg->mess();
    }
}

int main(){
    setlocale(LC_ALL, "Russian");
    RUN();
    return 0;
}