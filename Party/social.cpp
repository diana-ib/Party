//
// Created by ise on 1/8/23.
//

#include <string>
#include <iostream>
#include "social.h"
social::social(string fName,string lName,int pow,int id):Politician(fName,lName,pow,id){

}
int social::getPrimariespower(){
    return this->power*2;
}
void social::printPoliticians()const{
    Politician::printPoliticians();
    if(this->chairmanOfParty==NULL){
        cout<<", Type:S, Chairman: None"<<endl;
        return;
    }
    cout<<", Type:S, Chairman: "<< this->chairmanOfParty->getFirstName()<<endl;
}
social::~social(){

}