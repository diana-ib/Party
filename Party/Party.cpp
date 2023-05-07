//
// Created by ise on 1/5/23.
//
#include <iostream>
#include "Party.h"
#include "Politician.h"
using namespace std;
Party::Party(string name){
    this->partyName=name;
    this->chairmanOfParty=NULL;
    this->powerful=0;

}
Party::Party(const Party &other){
    this->chairmanOfParty=other.chairmanOfParty;
    this->partyName=other.partyName;
    this->powerful=other.powerful;

}
bool Party::deletePolitican(Politician *p){
    if(p==NULL){
        return false;
    }
    int x = 0;
    if(p==chairmanOfParty){
        x=p->getPower();
        chairmanOfParty=NULL;
        notifychairman();
    }

    for(int i=0;i<politicians.size();i++){
        if(p->getID()==politicians[i]->getID()){
            politicians[i]->setParty(NULL);
            politicians.erase(politicians.begin()+i);
            break;
        }
    }
    if(x== this->powerful){
        powerful=0;
        for(int i=0;i<politicians.size();i++){
            if(politicians[i]->getPower()> this->powerful)
                powerful=politicians[i]->getPower();
        }
    }
    return true;


}
int Party::getPower(){
    int total=0;
    for(int i=0;i<politicians.size();i++){
        total+=politicians[i]->getPrimariespower();
    }
    return total;
}
void Party::primaries(){
    int max = 0;
    if(chairmanOfParty){
        max = chairmanOfParty->getPower();
    }
    for(int i=0;i<politicians.size();i++){
        if(politicians[i]->getPower()==politicians[i]->getPrimariespower()&& politicians[i]->getPower()>max){
            this->chairmanOfParty=politicians[i];
            max= politicians[i]->getPower();

        }
    }
    if(chairmanOfParty){
        notifychairman();
        cout<< this->chairmanOfParty->getPoliticianName()<<" is the chairman of "<< this->partyName<<endl;
        return;
    }
    cout<<"None is the chairman of "<< this->partyName<<endl;
    return;
}
int Party::theStrength(){
    int partyPower=0;
    for(int i=0;i<politicians.size();i++){
        if(politicians[i]->getPower()==politicians[i]->getPrimariespower()){
            partyPower+=politicians[i]->getPower();
        } else{
            partyPower= partyPower+(politicians[i]->getPower()*2);
        }

    }
    return partyPower;
}
void Party::printParty()const{
    if(this->chairmanOfParty==NULL)
        cout<<"Party: "<< this->partyName<<", chairman:None, Size:"<< this->politicians.size()<<endl;
    else
        cout<<"Party: "<< this->partyName<<", chairman:"<< this->chairmanOfParty->getPoliticianName()<<", Size:"<< this->politicians.size()<<endl;
    for(int i=0;i< this->politicians.size(); i++){
        cout<<"\t";
        politicians[i]->printPoliticians();
    }
}
string Party::getPartyName()const{
    return this->partyName;

}
int Party::getSize()const{
    return politicians.size();
}

void Party::notifychairman(){
    for(int i=0;i<politicians.size();i++){
        politicians[i]->update(chairmanOfParty);
    }

}
Politician* Party::getPolByID(int id)const{
    for(int i=0;i<politicians.size();i++){
        if(politicians[i]->getID()==id)
        {
            return politicians[i];
        }
    }
    return nullptr;
}
Party::~Party(){
    politicians.clear();
}

vector<Politician *> Party::getPoliticians() {
    return politicians;
}
