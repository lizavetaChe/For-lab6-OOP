#ifndef PERSON_H_OBSERVER_H
#define PERSON_H_OBSERVER_H

#include <string>

class Observer{
public:
    virtual void update(std::string logString) = 0;
};

#endif //PERSON_H_OBSERVER_H
