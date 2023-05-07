//
// Created by ise on 1/5/23.
//
#include "Party.h"
#include "republicanParty.h"
#include <iostream>
using namespace std;
republicanParty::republicanParty(string name): Party(name){
}
bool republicanParty::addPolitican(Politician *p){
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
void republicanParty::printParty()const{
    cout<<"Republican ";
    Party::printParty();
}
republicanParty::~republicanParty(){

}