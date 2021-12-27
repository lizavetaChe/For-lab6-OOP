
#include "armor.h"

void armor::what(){
    std::cout << "WOW, this armor!" << '\n';
}
void armor::useItem(User *pl){
    pl->setSH(valiue+pl->getShield());
    notify("User find item - armor, SH = " + std::to_string(pl->getShield()));
}