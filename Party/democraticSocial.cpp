//
// Created by ise on 1/8/23.
//
#include <iostream>
#include "democraticSocial.h"
using namespace std;
democraticSocial::democraticSocial(string fName,string lName,int pow,int id): social(fName,lName,pow,id){

}
void democraticSocial::printPoliticians()const{
    cout<<"Democratic";
    social::printPoliticians();
}
bool democraticSocial::addPol(Party* p){
    if(p->isRepublican())return false;
    return p->addPolitican(this);
}
democraticSocial::~democraticSocial(){

}