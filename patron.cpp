#include<string>
#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

#include "patron.h"

//default constructor
patron::patron()
{
    id=0;
    name=" ";
    finebalance=0;
    numofbooksout=0;
}

//basic constructor
patron::patron(int ids, string names, int finebalances, int numofbooksouts)
{
id=ids;
name=names;
finebalance=finebalances;
numofbooksout=numofbooksouts;
}

//sets and gets
void patron::setname(string names){name=names;}
string patron::getname(){return name;}
void patron::setid(int ids){id=ids;}
int patron::getid(){return id;}
void patron::setfinebalances(int finebalances){finebalance=finebalances;}
int patron::getfinebalances(){return finebalance;}
void patron::setnumofbooksout(int numofbooksouts){numofbooksout=numofbooksouts;}
int patron::getnumofbooksout(){return numofbooksout;}