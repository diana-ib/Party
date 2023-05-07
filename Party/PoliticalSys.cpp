//
// Created by ise on 1/5/23.
//
#include "Errors.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "PoliticalSys.h"
#include "Politician.h"
#include "republicanLeader.h"
#include "democraticLeader.h"
#include "republicanSocial.h"
#include "democraticSocial.h"
#include "democraticParty.h"
#include "republicanParty.h"

using namespace std;
//vector<Party*>sortedParties;
PoliticalSys::PoliticalSys(){

}
PoliticalSys::PoliticalSys(char*&file){
    vector<string >polician;
    vector<string >parties;
    Politician *newPolitician;
    Party * newParty;
    string line_,word,fname,lname,id,rORd,lORs, partyName;
    ifstream file_;
    file_.open(file);
    const char del = ' ';
    if(file_.is_open())
    {
        getline(file_,line_);
        while(getline(file_,line_)){
            stringstream str(line_);
            if(line_.compare("Parties:\r")!=0) {
                while (getline(str,word,del)){
                    polician.push_back(word);
                }
                stringstream id1(polician[2]);
                stringstream power1(polician[3]);
                int iD,power;
                id1>>iD;
                power1>>power;

                if (polician[5][0] == 'L' && polician[4][0] == 'R') {
                    newPolitician = new republicanLeader(polician[0], polician[1], power, iD);
                    try {
                        if(newPolitician==NULL)
                            throw memory();
                    }
                    catch (Errors &e){
                        e.what();
                    }
                    politicians.push_back(newPolitician);

                }
                if (polician[5][0] == 'L' && polician[4][0]  == 'D') {
                    newPolitician = new democraticLeader(polician[0], polician[1], power,iD);
                    try {
                        if(newPolitician==NULL)
                            throw memory();
                    }
                    catch (Errors &e){
                        e.what();
                    }
                    politicians.push_back(newPolitician);
                }
                if (polician[5][0] == 'S' && polician[4][0]  == 'D') {
                    newPolitician = new democraticSocial(polician[0], polician[1], power,iD);
                    try{
                        if(newPolitician==NULL)
                            throw memory();
                    }
                    catch (Errors &e){
                        e.what();
                    }
                    politicians.push_back(newPolitician);
                }
                if (polician[5][0] == 'S' && polician[4][0]  == 'R') {
                    newPolitician = new republicanSocial(polician[0], polician[1], power,iD);
                    try {
                        if(newPolitician==NULL)
                            throw memory();
                    }
                    catch (Errors &e){
                        e.what();
                    }
                    politicians.push_back(newPolitician);
                }
                polician.clear();
            } else{
                break;
            }
        }
        //parties
        while(getline(file_,line_)){
            stringstream str(line_);
            while (getline(str,word,del)){
                parties.push_back(word);
            }
            if(parties[1][0]  == 'D'){
                newParty=new democraticParty(parties[0]);
                try {
                    if(newParty== NULL)
                        throw memory();
                }
                catch (Errors &e){
                    e.what();
                }
                party.push_back(newParty);
                parties.clear();

            }
            if(parties[1][0]  == 'R'){
                newParty=new republicanParty(parties[0]);
                try{

                    if(newParty== NULL)
                        throw memory();

                }
                catch (Errors &e){
                    e.what();
                }
                party.push_back(newParty);
                parties.clear();

            }
            for(int i=0;i<politicians.size();i++){
                politicians[i]->addPol(newParty);
            }
        }
        copy(party.begin(),party.end(), back_inserter(sortedParties));
        sort(sortedParties.begin(),sortedParties.end(),sortedFunctor());
        file_.close();
    }
    else{
        cout<<"file is not open"<<endl;

    }
}


bool  PoliticalSys::addPolitician(){
    int flag=0;
    int p,id;
    string fname,lname;
    string rORd,sORl;
    Politician *newP;
    cout<<"---Create Politician---"<<endl;
    while (flag==0) {
        cout << "First name:" << endl;
        cin>>fname;
        cout << "Last name:" << endl;
        cin>>lname;
        cout<<"ID:"<<endl;
        cin>>id;
        try {
            for (int i = 0; i < politicians.size(); i++) {

                if (id == politicians[i]->getID() || id < 0) {
                    throw invalidID();
                }
            }
            cout << "Power:" << endl;
            cin >> p;
            if (p < 0) {
                throw invalidData();
            }
            cout << "Republican or Democratic person" << endl;
            cin>> rORd;
            if (rORd[0] != 'R' && rORd[0] != 'D')
                throw invalidData();
            cout << "Leader or Social" << endl;
            cin >> sORl;
            if (sORl[0] != 'L' && sORl[0] != 'S')
                throw invalidData();
        }
        catch (Errors &e){
            e.what();
            continue;
        }
        break;

    }
    if (sORl[0] == 'L' && rORd[0] == 'R') {
        newP = new republicanLeader(fname, lname, p,id);
        try{
            if(newP==NULL)
                throw memory();

        }
        catch (Errors& e) {
            e.what();

        }

    }
    if (sORl[0] == 'L' && rORd[0] == 'D') {
        newP = new democraticLeader(fname, lname, p,id);
        try{
            if(newP==NULL)
                throw memory();

        }
        catch (Errors& e) {
            e.what();

        }
    }
    if (sORl[0] == 'S' && rORd[0] == 'D') {
        newP = new democraticSocial(fname, lname, p,id);
        try{
            if(newP==NULL)
                throw memory();

        }
        catch (Errors& e) {
            e.what();

        }

    }
    if (sORl[0] == 'S' && rORd[0] == 'R') {
        newP = new republicanSocial(fname, lname, p,id);
        try{
            if(newP==NULL)
                throw memory();

        }
        catch (Errors& e) {
            e.what();

        }


    }
    for(int i=0;i<party.size();i++){
        newP->addPol(party[i]);
    }
    politicians.push_back(newP);
    if(newP->getParty()!= nullptr)return true;
    return false;
}

bool PoliticalSys::BiggestParty(){
    cout<<"----Biggest Party----"<<endl;
    cout<<"["<<sortedParties[sortedParties.size()-1]->getPartyName()<<","<<sortedParties[sortedParties.size()-1]->getSize()<<"]"<<endl;

    return true;
}
bool PoliticalSys::addParty(){
    int flag=0;
    string partyN;
    string rORd;
    Party* newParty;
    while (flag==0) {
        cout << "---Create Party---" << endl;
        cout << "Name:" << endl;
        cin>>partyN;
        cout << "Republican or Democratic party" << endl;
        for (int i = 0; i <party.size(); i++) {
            try {
                if (partyN.compare(party[i]->getPartyName())==0) {
                    throw invalidData();
                }
                flag = 1;
            }
            catch (Errors &e) {
                e.what();
                continue;
            }
        }
        cin>>rORd;
        try {
            if (rORd[0] != 'R' && rORd[0] != 'D')
                throw invalidData();
            else
                flag = 1;
        }
        catch (Errors &e) {
            e.what();
            continue;
        }
    }
    if(rORd[0] == 'D'){
        newParty = new democraticParty(partyN);

    } else{
        newParty = new republicanParty(partyN);
    }
    for(int i=0 ;i<politicians.size();i++) {
        politicians[i]->addPol(newParty);
    }
    party.push_back(newParty);
    sortedParties.push_back(newParty);
    sort(sortedParties.begin(),sortedParties.end(),sortedFunctor());
    return true;
}
bool PoliticalSys::removePolitician(){
    int id;
    int c=0;
    int flag=0;
    Politician *thisPolitician;
    Party* thisParty;
    if(politicians.empty()){
        return false;
    }
    cout<<"---Remove Politician---"<<endl;
    cout<<"Enter the ID:"<<endl;
    cin>>id;
    for (int i = 0; i < politicians.size(); i++) {
        if(id != politicians[i]->getID()) {
            c++;
            thisPolitician = politicians[i];
        }
    }
    try {
        if (c==politicians.size() || id < 0) {
            throw invalidID();
        }
    }
    catch (Errors& e) {
        e.what();
    }

    if(thisPolitician!=NULL){
        thisParty=thisPolitician->getParty();
        thisParty->deletePolitican(thisPolitician);
        for(int j=0;j<politicians.size();j++){
            if(thisPolitician==politicians[j]){
                politicians.erase(politicians.begin()+j);
            }
        }
        sort(sortedParties.begin(),sortedParties.end(),sortedFunctor());
        delete thisPolitician;
        return true;
    }
    return false;

}
bool PoliticalSys::removeParty(){
    string partyName;
    if(party.empty()){
        return false;
    }
    cout<<"---Remove Party---"<<endl;
    int c=0;
    Party* thisParty;
    while (true){
        cout<<"Enter party name:"<<endl;
        cin>>partyName;


        for(int i=0;i<party.size();i++){
            if(partyName==party[i]->getPartyName()){
                thisParty=party[i];
                party.erase(party.begin()+i);
                break;
            }
            c++;
        }
        for(int i=0;i<sortedParties.size();i++){
            if(partyName==sortedParties[i]->getPartyName()){
                sortedParties.erase(sortedParties.begin()+i);
                break;
            }
        }
        try{
            if(c==party.size())
                throw invalidName();
        }
        catch (Errors& e) {
            e.what();
        }
        break;
    }
    for(int i = 0 ; i < thisParty->getPoliticians().size(); i++){
        thisParty->getPoliticians()[i]->setParty(NULL);
    }
    for(int i = 0 ; i < thisParty->getPoliticians().size(); i++){
        for(int j=0;j<party.size();j++){
            thisParty->getPoliticians()[i]->addPol(party[j]);
        }
    }
    delete thisParty;
    return true;



}
bool PoliticalSys::elections(){
    if (party.empty() || politicians.empty())
        return false;
    cout << "----Primaries----"<<endl;
    for (auto & i : party)
        i->primaries();
    cout << "----Elections----"<<endl;
    int max =0 ;
    Party* winner;
    for(int i=0;i<party.size();i++){
        cout << "Party: " << party[i]->getPartyName();
        cout << ",Power: ";
        int power = party[i]->getPower();
        cout <<power<<endl;
        if(power>max){
            max=power;
            winner = party[i];
        }

    }
    cout << "----Elections Results----"<<endl;
    cout << winner->getPartyName();
    cout << " party won the elections and ";
    if (winner->getchairmanOfParty())
        cout << winner->getchairmanOfParty()->getFirstName();
    else
        cout << "None";
    cout << " is the prime minister" << endl;
    return true;
}

void PoliticalSys::printPoliticians()const{
    cout<<"----Politicians----"<<endl;
    for(int i=0;i<politicians.size();i++){
        this->politicians[i]->printPoliticians();
    }
}
void PoliticalSys::printParties()const{
    cout<<"----Parties----"<<endl;
    for(int i=0;i<party.size();i++){
        this->party[i]->printParty();
    }
}
PoliticalSys::~PoliticalSys(){
    for(int i=0;i<politicians.size();i++){
        delete(this->politicians[i]);
    }
    politicians.clear();
    for(int j=0;j<party.size();j++){
        delete(this->party[j]);
    }
    party.clear();

}
