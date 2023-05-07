//
// Created by ise on 1/8/23.
//
#include "leader.h"
#include <string>
#ifndef ASSIGNMENT5_REPUBLICANLEADER_H
#define ASSIGNMENT5_REPUBLICANLEADER_H


class republicanLeader: public leader{
public:
//counstructor
    republicanLeader(string fName,string lName,int pow,int id);
    //destructur
    virtual ~republicanLeader();
    //print the politicians
    void printPoliticians()const;
    //add politcian to rupublican 
    virtual bool addPol(Party* p);
};


#endif //ASSIGNMENT5_REPUBLICANLEADER_H
