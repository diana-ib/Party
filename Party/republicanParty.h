//
// Created by ise on 1/5/23.
//

#ifndef ASSIGNMENT5_REPUBLICANPARTY_H
#define ASSIGNMENT5_REPUBLICANPARTY_H
#include "Politician.h"
#include "Party.h"
//inherits from party class
class republicanParty:public Party{
public:
//counstructor
    republicanParty(string name);
    //add a politician to republican party 
    virtual bool addPolitican(Politician *p);
    //return true if is republican party-false if isDemocratic party
    virtual bool isDemocratic()const{return false;}
    virtual bool isRepublican()const{return true;}
    //Print the Republican Party
    virtual void printParty()const;
    //returns the democratic parties size - in this class always set to -1
    virtual int getSizeDemocratic()const{return -1;}
    //Function that returns the republican parties size
    virtual int getSizeRepublican()const {return this->getSize(); }
    virtual ~republicanParty();
};


#endif //ASSIGNMENT5_REPUBLICANPARTY_H
