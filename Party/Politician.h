//
// Created by ise on 1/5/23.
//

#include <string>
#ifndef ASSIGNMENT5_POLITICIAN_H
#define ASSIGNMENT5_POLITICIAN_H
#include "Party.h"
using namespace std;
class Politician {
    static  int politicianNum;
protected:
    string firstName;
    string lastName;
    Party *party;
    int power;
    int iD;
    Politician *chairmanOfParty;
public:
    Politician(string fName,string lName,int pow,int id);
    Politician(const Politician& other);
    virtual void printPoliticians()const=0;
    virtual ~Politician();
    int getPower()const;
    string getFirstName()const;
    string getPoliticianName()const;
    int getID()const;
    virtual int getPrimariespower()=0;
    virtual bool addPol(Party* p)=0;
    Party* getParty()const;
    Politician *getChairman()const{return this->chairmanOfParty;}
    void setParty(Party* p);
    void update(Politician *newchairmanOfParty);

};


#endif //ASSIGNMENT5_POLITICIAN_H
