//
// Created by ise on 1/8/23.
//
#include "social.h"
#ifndef ASSIGNMENT5_REPUBLICANSOCIAL_H
#define ASSIGNMENT5_REPUBLICANSOCIAL_H


class republicanSocial :public social{

public:
//constructor
    republicanSocial(string fName,string lName,int pow,int id);
   //destructor
    virtual ~republicanSocial();
    //print the politician
    void printPoliticians()const;
    //add the politician to arupublican party
    virtual bool addPol(Party* p);
};




#endif //ASSIGNMENT5_REPUBLICANSOCIAL_H
