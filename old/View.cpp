
#include "View.h"
#include <iostream>

View::View(item* it,Logger* log_){
    this->it = it;
    LOG=log_;
    it->setObserver(this);
}

View::View(Monster* M,Logger* log_){
    this->M = M;
    LOG=log_;
    M->setObserver(this);
}

View::View(Field* f,Logger* log_){
    this-> f = f;
    LOG=log_;
    f->setObserver(this);
}

void View::update(std::string logString){
    LOG->print(logString);
}
