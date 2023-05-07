//
// Created by ise on 1/8/23.
//
#include "Politician.h"
#include <string>
#ifndef ASSIGNMENT5_SOCIAL_H
#define ASSIGNMENT5_SOCIAL_H


class social: public Politician {
public:
//constructor
    social(string fName,string lName,int pow,int id);
    //get the primaries power
    virtual int getPrimariespower();
    // print the politician
    virtual void printPoliticians()const;
    //destructor
    virtual ~social();
};


#endif //ASSIGNMENT5_SOCIAL_H
