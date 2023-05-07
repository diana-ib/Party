//
// Created by ise on 1/8/23.
//
#include "leader.h"
#ifndef ASSIGNMENT5_DEMOCRATICLEADER_H
#define ASSIGNMENT5_DEMOCRATICLEADER_H


class democraticLeader: public leader{
public:
//counstructor
    democraticLeader(string fName,string lName,int pow,int id);
    //prinnt politcian 
    void printPoliticians()const;
    // add politcian to party 
    virtual bool addPol(Party* p);
    //destructor
    virtual ~democraticLeader();
};


#endif //ASSIGNMENT5_DEMOCRATICLEADER_H
