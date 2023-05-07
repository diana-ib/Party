//
// Created by ise on 1/8/23.
//
#include <string>
#include <iostream>
#include "leader.h"
using namespace std;
leader::leader(string fName,string lName,int pow,int id):Politician(fName,lName,pow,id)
{

}
int leader::getPrimariespower(){
    return this->power;
}
leader::~leader()  { }
void leader::printPoliticians()const{
    Politician::printPoliticians();
    if(this->chairmanOfParty==NULL){
        cout<<", Type:L, Chairman: None"<<endl;
        return;
    }
    else {
        cout << ", Type:L, Chairman: " << this->chairmanOfParty->getFirstName()<< endl;
    }
}
