
#include "StepUserAction.h"

void StepUserAction::Work(){
    field->place=field->getCard()->StepUser(field->getPlace(), dx, dy);
    field->TURN();
}