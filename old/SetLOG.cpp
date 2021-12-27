
#include "SetLOG.h"

LogProxy*   SetLOG::setLogger(){
    proxy = nullptr;
    std::cout << "Выполнить логиррование в :" << std::endl;
    std::cout << "1: Файле\n2: Терминале\nother: Оба варианта" << std::endl;
    int choice;
    std::cin >> choice;
    switch (choice) {
        case 1:
            proxy = new LogProxy(1);
            break;
        case 2:
            proxy = new LogProxy(2);
            break;
        default:
            proxy = new LogProxy(3);
            break;
    }
    return proxy;
}

LogProxy*  SetLOG::setLogger_old(){
    proxy = new LogProxy(1);
    return proxy;
}

LogProxy* SetLOG::getLog(){
    return proxy;
}

void SetLOG::mess(){
    mediator->Send(this,"Logger setted up");
}

void SetLOG::mess_old(){
    mediator->Send(this,"OLD");
}
