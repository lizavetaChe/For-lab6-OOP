
#include "Print.h"

#include <iostream>


void Print::Menu(){
    int W, H;
    std::cout << "������� ������ �������� ���� � �������: ������ ������\n";
    std::cin >> H >> W;
    std::cout << "��� �������� �� ����� ����������� ������� - {w,s,a,d}; \n";
    std::cout << "��� �������� ��������� � ��������� ����� - {q}; \n";
    std::cout << "��� ���������� ���� - {e}. \n";
    std::cout << "��� ���������� ���� - {x}. \n";
    std::cout << "��� ������� ���������� ���� - {z}. \n";
    f=new FieldShow(H,W);
    mediator->Send(this,"Menu done");
}

FieldShow* Print::getFieldShow() {
    return f;
}

void Print::Condition(){
    std::cout << "HP = "<<f->getCard()->getMap()[f->place->getCoord().x][f->place->getCoord().y].getUser()->getHp_NOW() <<'\n';
    std::cout << "ATT = "<<f->getCard()->getMap()[f->place->getCoord().x][f->place->getCoord().y].getUser()->getAtt() <<'\n';
    std::cout << "SH = "<<f->getCard()->getMap()[f->place->getCoord().x][f->place->getCoord().y].getUser()->getShield() <<'\n';
    mediator->Send(this,"YA VSE SDELAL");
}