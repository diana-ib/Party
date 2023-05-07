//
// Created by ise on 1/5/23.
//
#include "Politician.h"
#include "Party.h"
#include "republicanParty.h"
#include "democraticParty.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cstring>
#ifndef ASSIGNMENT5_POLITICALSYS_H
#define ASSIGNMENT5_POLITICALSYS_H
using namespace std;
//this class represents the political sys
class PoliticalSys {
//politicians, parties and copy of the parties (sorted) vectors
    vector<Party*>sortedParties;
    vector<Politician*> politicians;
    vector<Party*> party;

public:
//counstructor
    PoliticalSys();
    //counstructor read the file txt
    PoliticalSys(char *&file);
    //add politician to the sys
    bool  addPolitician();
    // return true if this is the biggest party of the sys else false
    bool BiggestParty();
    //add new party to the sys
    bool addParty();
    //remove Politician from the sys
    bool removePolitician();
    //remove Party from the sys
    bool removeParty();
    //elections, within this function the chairman of the party is chosen (Primaries) and then the winning party is chosen
    bool elections();
    //print all politicians in the sys
    void printPoliticians()const;
    //print all the parties in the sys
    void printParties()const;
    //destructour
    virtual ~PoliticalSys();

};
//class function to sort the politiciens
class sortedFunctor{
public:
    bool operator()(const Party*p1, const Party*p2 ){
        if(p1->getSize()==p2->getSize()){
            return p1->getPartyName().length()<p2->getPartyName().length();
        }
        return (p1->getSize()<p2->getSize());
    }
};

#endif //ASSIGNMENT5_POLITICALSYS_H
