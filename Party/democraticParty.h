//
// Created by ise on 1/5/23.
//

#ifndef ASSIGNMENT5_DEMOCRATICPARTY_H
#define ASSIGNMENT5_DEMOCRATICPARTY_H
#include "Party.h"
#include "Politician.h"
class democraticParty: public Party{
public:
//counstructor
    democraticParty(string name);
    //destructor
    virtual ~democraticParty();
    //print party
    virtual void printParty()const;
    //add politcian to party 
    virtual bool addPolitican(Politician *p);
    virtual bool isDemocratic()const{return true;}
    virtual bool isRepublican()const{return false;}
    //get the size of the democratic party
    virtual int getSizeDemocratic()const{return this->getSize();}
    //get the size of the republican party - in this class this function always returns -1
    virtual int getSizeRepublican()const { return -1;}
};


#endif //ASSIGNMENT5_DEMOCRATICPARTY_H
