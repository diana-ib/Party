//
// Created by ise on 1/5/23.
//

#include "democraticParty.h"
#include <iostream>
using namespace std;
democraticParty::democraticParty(string name):Party(name){
}
bool democraticParty::addPolitican(Politician *p) {
    if(p->getParty()== nullptr||this->getSize()<p->getParty()->getSize()){
        if(p->getParty()!= nullptr)p->getParty()->deletePolitican(p);
        if(p->getPower()==p->getPrimariespower()||p->getPower()>powerful){
            powerful=p->getPower();
        }
        p->setParty(this);
        this->politicians.push_back(p);
        return true;
    }
    return false;
}
void democraticParty::printParty()const{
    cout<<"Democrat ";
    Party::printParty();
}
democraticParty::~democraticParty() {

}