//
// Created by ise on 1/8/23.
//
#include "Politician.h"
#ifndef ASSIGNMENT5_LEADER_H
#define ASSIGNMENT5_LEADER_H


class leader: public Politician{
public:
//counstructor
    leader(string fName,string lName,int pow,int id);
    //the power of primaries
    virtual int getPrimariespower();
    //destructor 
    virtual ~leader();
    //print the politcian 
    virtual void printPoliticians()const;
};


#endif //ASSIGNMENT5_LEADER_H
