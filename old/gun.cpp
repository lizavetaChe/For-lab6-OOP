
#include "gun.h"

void gun::what(){
    std::cout << "WOW, gun!" << '\n';
}
void gun::useItem(User *pl){
    pl->setAtt(valiue+pl->getAtt());
    notify("User find item - gun, ATT = " + std::to_string(pl->getAtt()));
}