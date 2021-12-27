
#include "Person.h"

void Person::setHP_NOW(int hp){
    hp_NOW = hp;
}
void Person::setAtt(int at){
    att = at;
}
void Person::setSH(int sh){
    shield = sh;
}
int Person::getHp_NOW(){
    return hp_NOW;
}
int Person::getAtt(){
    return att;
}
int Person::getShield(){
    return shield;
}