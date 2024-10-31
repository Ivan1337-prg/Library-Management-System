#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<time.h>

#include "loans.h"
#include "loan.h"
#include "patrons.h"
#include "patron.h"
#include "libraryitems.h"
#include "libraryitem.h"

#define CHUNKSIZE 2

extern patrons custs;
extern libraryitems inventory;

//default constructor
loans::loans()
{
  
}
void loans::addloans()
{
//declarations
    int loanid;
    int bookid;
    int patronid;
    string status;
    int any;
    string datetime;

    //get user to enter data
    cout<<"Enter loan id number: "<<endl;
    cin>>loanid;
    cout<<"Enter book id number: "<<endl;
    cin>>bookid;
    cout<<"Enter patron id number: "<<endl;
    cin>>patronid;
    cin.ignore();
    cout<<"Enter status: "<<endl;
    getline(cin,status);
    cout<<"Enter current date: "<<endl;
    getline(cin,datetime);

    //create and populate loan object
    loan* temp=new loan(loanid,bookid,patronid,datetime,status);
    loanlist.push_back(temp);

    //added succesfully 
    loancnt++;
    cout<<"Loan succesfully added."<<endl;
    cout<<"Press any number to return to menu."<<endl;
    cin>>any;
}

void loans::deleteloans()
{
    //asking for book id to delete
    int bookid;
    cout<<"Enter Book id: "<<endl;
    cin>>bookid;

    //loop to get through all of the line
    for (int i=0; i<loanlist.size();i++)
    {
        if(loanlist.at(i)->getbookids()==bookid)
        {
         loanlist.erase(loanlist.begin()+i);
        }
    }
}

void loans::checkoutbook()
{
    //declarations
    int loanid;
    int bookid;
    int patronid;
    string status="IN";
    int any;
    string datetime;
    time_t time;
    struct tm * timeinfo;
    int year;
    int month;
    int day;
    
    //get user to enter data
    cout<<"Enter loan id number: "<<endl;
    cin>>loanid;
    cout<<"Enter book id number: "<<endl;
    cin>>bookid;
    cout<<"Enter patron id number: "<<endl;
    cin>>patronid;
    cin.ignore();
    cout<<"Enter current year: "<<endl;
    cin>>year;
    cout<<"Enter current month: "<<endl;
    cin>>month;
    cout<<"Enter current day: "<<endl;
    cin>>day;

    datetime=year + month + day;

    //delete it from list
    for (int i=0; i<loanlist.size();i++)
    {
        if(loanlist.at(i)->getbookids()==bookid)
        {
         loanlist.erase(loanlist.begin()+i);
        }
    }

    //time
    timeinfo = gmtime (&time);
    timeinfo->tm_year=year;
    timeinfo->tm_mon=month-1;
    timeinfo->tm_mday=day + 10;

    mktime(timeinfo);

    //added succesfully 
    loancnt++;
    cout<<"Loan succesfully deleted."<<endl;
    cout<<"DUE DATE IS: "<<endl;
    cout<<asctime(timeinfo)<<endl;
    cout<<"Press any number to return to menu."<<endl;
    cin>>any;

}

void loans::checkinbook()
{
    //declarations
    int loanid;
    int bookid;
    int patronid;
    string status="IN";
    int any;
    string datetime;
    time_t time;
    struct tm * timeinfo;
    int year;
    int month;
    int day;
    
    //get user to enter data
    cout<<"Enter loan id number: "<<endl;
    cin>>loanid;
    cout<<"Enter book id number: "<<endl;
    cin>>bookid;
    cout<<"Enter patron id number: "<<endl;
    cin>>patronid;
    cin.ignore();
    cout<<"Enter current year: "<<endl;
    cin>>year;
    cout<<"Enter current month: "<<endl;
    cin>>month;
    cout<<"Enter current day: "<<endl;
    cin>>day;

    datetime=year + month + day;

    //create and populate loan object
    loan* temp=new loan(loanid,bookid,patronid,datetime,status);
    loanlist.push_back(temp);

    //time
    timeinfo = gmtime (&time);
    timeinfo->tm_year=year;
    timeinfo->tm_mon=month-1;
    timeinfo->tm_mday=day;

    mktime(timeinfo);

    //added succesfully 
    loancnt++;
    cout<<"Loan succesfully added."<<endl;
    cout<<"DATE THAT YOU CHECKED IN: "<<endl;
    cout<<asctime(timeinfo)<<endl;
    cout<<"Press any number to return to menu."<<endl;
    cin>>any;
}

void loans::fineinformation()
{
    //print the fines
}

void loans::listofoverduebooks()
{
    /*
    add books and loans to borrowed books and datetime
    select borrowed books where datetime>10
    add books and loans to patron id and book id
    select patron id where book id = "+id"
    */
}

void loans::reportlostbook()
{
    //declarations
    int patronid;
    int bookid;
    //asking for user input
    cout<<"Enter Patron id: "<<endl;
    cin>>patronid;
    cout<<"Enter the Book id that you have lost."<<endl;
    cin>>bookid;

    /*
    //prompt patron id
    //book patronid that they lost

    //load the patron and book
    //set fine to the status of the book
    */
}

//edit loans
void loans::editloans()
{
//declarations
int loanid;
int bookid;
int patronid;
string datetime;
string status;

//asking user for input
cout<<"Enter the old loan id number: "<<endl;
cin>>loanid;
cout<<"You cannot change the loan id number."<<endl;
cout<<"Type new information:"<<endl;
cout<<"Enter new book id."<<endl;
cin>>bookid;
cout<<"Enter new due date."<<endl;
cin>>datetime;
cout<<"Enter new status."<<endl;
cin>>status;

//populating the sets
for(int i=0; i<loanlist.size();i++)
{
if(loanlist.at(i)->getloanid()==loanid)
 {
     loanlist.at(i)->setbookid(bookid);
     loanlist.at(i)->setpatronid(patronid);
     loanlist.at(i)->setdatetime(datetime);
     loanlist.at(i)->setstatus(status);
 }
}
}

//load into the data
void loans::loadloans()
{
    //declarations
    int loanid;
    int bookid;
    int patronid;
    string datetime;
    string status;
    ifstream fin;
    //opening loans.dat
        fin.open("loans.dat");
        fin>>loancnt; 
        fin.ignore();
        loan* temp;

    //reading in input into the .dat
        for(int i=0;i<loanlist.size();i++)
        {
        fin>>loanid>>bookid>>patronid>>datetime>>status;
        cout<<loanid<<bookid<<patronid<<datetime<<status;

        loan* temp=new loan(loanid,bookid,patronid,datetime,status);
        loanlist.push_back(temp);
        }
        fin.close();
}

//store loans into data
void loans::storeloans()
{
    ofstream fout;
    fout.open("loans.dat");
    fout<<loancnt<<endl;

    libraryitem *temp;
//outputing the input into the .dat
    for(int i=0;i<loanlist.size();i++)
    {
        fout<<loanlist.at(i)->getloanid()<<" "<<loanlist.at(i)->getbookids()<<" "<<loanlist.at(i)->getpatronid()<<" "<<loanlist.at(i)->getdatetime()<<" "<<loanlist.at(i)->getstatus()<<endl;
    }
    fout.close();
}

void loans::printloans()
{
     for(int i=0; i<loanlist.size();i++)
    {
    //printing the gets
    cout<<"Here is the loan information: "<<endl;
    cout<<loanlist.at(i)->getloanid()<<" "<<loanlist.at(i)->getbookids()<<" "<<loanlist.at(i)->getpatronid()<<" "<<loanlist.at(i)->getdatetime()<<" "<<loanlist.at(i)->getstatus()<<endl;
    }
}

void loans::printsingleloans()
{
    int newloanid;
    cout<<"Enter the loan id: "<<endl;
    cin>>newloanid;
    for(int i=0; i<loanlist.size();i++)
    {
    if(loanlist.at(i)->getloanid()==newloanid)
    {
     cout<<loanlist.at(i)->getloanid()<<" "<<loanlist.at(i)->getbookids()<<" "<<loanlist.at(i)->getpatronid()<<" "<<loanlist.at(i)->getdatetime()<<" "<<loanlist.at(i)->getstatus()<<endl;
    }
    }

}