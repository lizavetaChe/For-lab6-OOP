
#ifndef PERSON_H_PRINT_H
#define PERSON_H_PRINT_H

#include "Colleague.h"
#include "Rule_CountMonster.h"


class Print : public Colleague{
public:
    void Menu();
    void Condition();
    void Old_or_New();
    FieldShow* getFieldShow();
private:
    FieldShow* f;
};


#endif //PERSON_H_PRINT_H
