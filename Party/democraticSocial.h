//
// Created by ise on 1/8/23.
//
#include "social.h"
#ifndef ASSIGNMENT5_DEMOCRATICSOCIAL_H
#define ASSIGNMENT5_DEMOCRATICSOCIAL_H


class democraticSocial:public social {
public:
//constructor 
    democraticSocial(string fName,string lName,int pow,int id);
    //print 
    void printPoliticians()const;
    //destructor
    virtual ~democraticSocial();
    // add politcian 
    virtual bool addPol(Party* p);
};

#endif //ASSIGNMENT5_DEMOCRATICSOCIAL_H
