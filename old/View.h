#ifndef PERSON_H_VIEW_H
#define PERSON_H_VIEW_H

#include "Observer.h"
#include "item.h"
#include "Monster.h"
#include "Logger.h"
#include "Field.h"


class View: public Observer{
public:
    View(item* it,Logger* log_);
    View(Monster* M, Logger* log_);
    View(Field* f, Logger* log_);
    void update(std::string logString);
    ~View()=default;
private:
    Logger *LOG;
    item* it;
    Monster* M;
    Field* f;
};


#endif //PERSON_H_VIEW_H
