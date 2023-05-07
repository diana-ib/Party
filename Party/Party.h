//
// Created by ise on 1/5/23.
//

#ifndef ASSIGNMENT5_PARTY_H
#define ASSIGNMENT5_PARTY_H
#include <vector>
#include <string>

using namespace std;
class Politician;
class Party {
    string partyName;

protected:
    Politician *chairmanOfParty;
    vector<Politician*> politicians;
    int powerful;
public:
//Constructor
    Party(string name);
    //copy Constructor
    Party(const Party &other);
    //Add a politician to a party
    virtual bool addPolitican(Politician *p)=0;
    virtual bool isDemocratic()const=0;
    virtual bool isRepublican()const=0;
    //removes a politician from a part
    virtual bool deletePolitican(Politician *p);
    //checks which leader politician has the highest power
    void primaries();
    //what the pweor of strength pary 
    int theStrength();
    //Function that goes over all politicians and updates their chairman after primaries
    void notifychairman();
    //print party
    virtual void printParty()const=0;
    //get party name
    string getPartyName()const;
    int getSize()const;
    //get politcian by the id 
    Politician* getPolByID(int id)const;
    int getPower();
    virtual int getSizeDemocratic()const=0;
    virtual int getSizeRepublican()const=0;
    //Function that returns the chairman of the party
    Politician *getchairmanOfParty()const{return this->chairmanOfParty;}
    //get a politician from the politicians vector
    vector<Politician*> getPoliticians();
    //destructour 
    virtual ~Party();
};


#endif //ASSIGNMENT5_PARTY_H
