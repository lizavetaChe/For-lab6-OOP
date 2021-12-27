#include "Observable.h"

void Observable::setObserver(Observer* obs){
    this->obs = obs;
}
void Observable::notify(std::string logString){
    obs->update(logString);
}