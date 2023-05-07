//
// Created by ise on 1/8/23.
//


#include <iostream>
#include "republicanSocial.h"
using namespace std;
republicanSocial::republicanSocial(string fName,string lName,int pow,int id): social(fName,lName,pow,id)
{

}
void republicanSocial::printPoliticians() const {
    cout<<"Republican";
    social::printPoliticians();
}
bool republicanSocial::addPol(Party* p){
    if(p->isDemocratic())return false;
    return p->addPolitican(this);
}
republicanSocial::~republicanSocial(){

}