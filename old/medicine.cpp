
#include "medicine.h"

void medicine::what(){
    std::cout << "WOW, this medicine!" << '\n';
}
void medicine::useItem(User *pl){
    pl->setHP_NOW(valiue+pl->getHp_NOW());
    notify("User find item - heal, HP = " + std::to_string(pl->getHp_NOW()));
}