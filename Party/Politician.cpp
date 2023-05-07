//
// Created by ise on 1/5/23.
//
#include <iostream>
#include "Politician.h"
int Politician::politicianNum=0;
Politician::Politician(string fName,string lName,int pow,int id){
    politicianNum++;
    iD=politicianNum;
    iD=id;
    firstName=fName;
    lastName=lName;
    party=NULL;
    chairmanOfParty=NULL;
    power=pow;
}
Politician::Politician(const Politician& other){
    party= nullptr;
    chairmanOfParty= nullptr;
    firstName=other.firstName;
    lastName=other.lastName;
    iD=other.iD;
    power=other.power;
    party=other.party;
    chairmanOfParty=other.chairmanOfParty;
}
 void Politician::printPoliticians()const{
    cout<<" Person:"<< this->firstName<<" "<< this->lastName<<", Id:"<< this->iD<<", Power:"<< this->power;

}
int Politician::getPower()const{
    return this->power;
}
string Politician::getPoliticianName()const{
    return this->firstName;
}
int Politician::getID()const{
    return this->iD;

}
Party* Politician::getParty()const{
    return party;
}
string Politician::getFirstName()const{
    return firstName;
}
void Politician::setParty(Party* p){
    party=p;
}
void Politician::update(Politician *newchairmanOfParty){
        chairmanOfParty=newchairmanOfParty;
}
Politician::~Politician(){

}


