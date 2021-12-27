#ifndef PERSON_H_OBSERVABLE_H
#define PERSON_H_OBSERVABLE_H

#include "Observer.h"
#include <string>

class Observable{
    Observer* obs;
public:
    void setObserver(Observer* obs);
    void notify(std::string logString);
};

#endif //PERSON_H_OBSERVABLE_H
