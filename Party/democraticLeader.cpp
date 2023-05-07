//
// Created by ise on 1/8/23.
//
#include <iostream>
#include "democraticLeader.h"
using namespace std;
democraticLeader::democraticLeader(string fName,string lName,int pow,int id):leader(fName,lName,pow,id){

}
void democraticLeader::printPoliticians()const{
    cout<<"Democratic";
    leader::printPoliticians();
}
bool democraticLeader::addPol(Party* p){
    if(p->isRepublican())return false;
    return p->addPolitican(this);
}
democraticLeader::~democraticLeader(){

}