//entity class
//base class

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

#include "libraryitem.h"

//default constructor
libraryitem::libraryitem()
{
    id=0;
    cost=0.0;
    status=" ";
    loanperiod=0;
}

//basic constructor
libraryitem::libraryitem(int ids, float costs, string statuss, int loanperiods)
{
    id=ids;
    cost=costs;
    status=statuss;
    loanperiod=loanperiods;
}

//normal print
void libraryitem::print()
{
    cout<<"ID: "<<id<<endl;
    cout<<"Cost: "<<cost<<endl;
    cout<<"Status: "<<status<<endl;
    cout<<"Loan Period: "<<loanperiod<<endl;
}

//raw print
void libraryitem::rawprint()
{
  cout<<id<<" "<<cost<<" "<<status<<" "<<loanperiod<<" "<<endl;  
}

//outputstream
/*
ostream& operator<<(ostream& st, item& it)
{
   it.rawprint();
   return st;
}
*/

//sets and gets
void libraryitem::setid(int ids) {id=ids;}
int libraryitem::getid() {return id;}
void libraryitem::setcost(float costs) {cost=costs;}
float libraryitem::getcost() {return cost;}
void libraryitem::setstatus(string statuss) {status=statuss;}
string libraryitem::getstatus() {return status;}
void libraryitem::setloanperiod(int loanperiods) {loanperiod=loanperiods;}
int libraryitem::getloanperiod() {return loanperiod;}