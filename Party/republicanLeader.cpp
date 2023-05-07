//
// Created by ise on 1/8/23.
//
#include <iostream>
#include "republicanLeader.h"
using namespace std;
republicanLeader::republicanLeader(string fName,string lName,int pow,int id): leader(fName,lName,pow,id)
{

}
void republicanLeader::printPoliticians()const{
    cout<<"Republican";
    leader::printPoliticians();
}
bool republicanLeader::addPol(Party* p){
    if(p->isDemocratic())return false;
    return p->addPolitican(this);
}
republicanLeader::~republicanLeader(){

}