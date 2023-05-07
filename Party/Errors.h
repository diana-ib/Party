//
// Created by ise on 1/8/23.
//

#ifndef ASSIGNMENT5_ERRORS_H
#define ASSIGNMENT5_ERRORS_H
#include <iostream>
using namespace std;
class Errors {
public:
    Errors(){};
    virtual void what()const=0;
    virtual ~Errors(){};
};
class invalidData:public Errors{
public:
    virtual void what()const{cout<<"Please enter valid details"<<endl;}
    virtual ~invalidData(){};
};
class invalidID:public Errors{
public:
    virtual void what()const{cout<<"Please enter valid id"<<endl;}
    virtual ~invalidID(){};
};
class invalidName:public Errors{
public:
    virtual void what()const{cout<<"Please enter valid name"<<endl;}
    virtual ~invalidName(){};
};
class memory:public Errors{
public:
    virtual void what()const{cout<<"Memory overflow\n"<<endl;}
    virtual ~memory(){};
};
#endif //ASSIGNMENT5_ERRORS_H
