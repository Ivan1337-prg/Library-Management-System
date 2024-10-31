#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

#include "loan.h"

//default constructor
loan::loan()
{
    loanid=0;
    bookid=0;
    patronid=0;
    datetime=" ";
    status=" ";
}

//basic constructor
loan::loan(int loanids, int bookids, int patronids, string datetimes, string statuss)
{
    loanid=loanids;
    bookid=bookids;
    patronid=patronids;
    datetime=datetimes;
    status=statuss;
}

//sets and gets
void loan::setloanid(int loanids){loanid=loanids;}
int loan::getloanid(){return loanid;}
void loan::setbookid(int bookids){bookid=bookids;}
int loan::getbookids(){return bookid;}
void loan::setpatronid(int patronids){patronid=patronids;}
int loan::getpatronid(){return patronid;}
void loan::setdatetime(string datetimes){datetime=datetimes;}
string loan::getdatetime(){return datetime;}
void loan::setstatus(string statuss){status=statuss;}
string loan::getstatus(){return status;}