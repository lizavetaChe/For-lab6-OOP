
#include "Read.h"

void Read::setINPUT() {
    char command;
    std::cin >> command;
    switch (command){
        case 'w':
            act = new StepUserAction(f, -1, 0);
            break;
        case 's':
            act = new StepUserAction(f, 1, 0);
            break;
        case 'd':
            act = new StepUserAction(f, 0, 1);
            break;
        case 'a':
            act = new StepUserAction(f, 0, -1);
            break;
        case 'e':
            act = new EndAction(mediator);
            break;
        case 'q':
            act = new PrintAction(mediator);
            break;
        case 'x':
            act = new SaveAction(mediator);
            break;
        case 'z':
            act = new LoadAction(mediator);
            break;
    }
    act->Work();
}