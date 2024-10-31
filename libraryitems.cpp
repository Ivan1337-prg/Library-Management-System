//collection class

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include <typeinfo>
#include "libraryitems.h"
#include "libraryitem.h"
#include "book.h"
#include "audioCd.h"
#include "dvd.h"

#define CHUNKSIZE 2


libraryitems::libraryitems()
{
}

//add libraryitems
void libraryitems::addlibraryitems()
{
int any;
int minianswer;
libraryitem* temp;
//declarations for libraryitem
int id;
float cost;
string status;
int loanperiod;
//declarations for audioCd
string artist;
string audiotitle;
int track;
string audioreleasedate;
string genre;
//declarations for book
string booktitle;
string author;
int isbn;
string category;
//declarations for dvd
string dvdtitle;
string dvdcategory;
int runtime;
string studio;
string dvdreleasedate;

//libraryitem
cout<<"Enter library id number: "<<endl;
cin>>id;
cout<<"Enter cost: "<<endl;
cin>>cost;
cin.ignore();
cout<<"Enter status: "<<endl;
getline(cin,status);
cout<<"Enter LoanPeriod: "<<endl;
cin>>loanperiod;

//have a mini menu for each child class
cout<<endl<<"Mini Menu:"<<endl;
cout<<"1 - AudioCd: "<<endl;
cout<<"2 - Book: "<<endl;
cout<<"3 - Dvd: "<<endl;
cin>>minianswer;
cin.ignore();

switch (minianswer)
{
case 1:
    cout<<"Enter Artist: "<<endl;
    getline(cin, artist);
    cout<<"Enter Title: "<<endl;
    getline(cin, audiotitle);
    cout<<"Enter Track: "<<endl;
    cin>>track;
    cin.ignore();
    cout<<"Enter Release Date: "<<endl;
    getline(cin, audioreleasedate);
    cout<<"Enter Genre: "<<endl;
    getline(cin, genre);

    //creating and populating object
    temp= new audioCd(id, cost, status, loanperiod, artist, audiotitle, track, audioreleasedate, genre);
    libraryitemlist.push_back(temp);
    break;

case 2:
    cout<<"Enter Title: "<<endl;
    getline(cin,booktitle);
    cout<<"Enter Author: "<<endl;
    getline(cin, author);
    cout<<"Enter ISBN: "<<endl;
    cin>>isbn;
    cin.ignore();
    cout<<"Enter Category: "<<endl;
    getline(cin, category);

    //creating and populating object
    temp= new book(id, cost, status, loanperiod, booktitle, author, isbn, category);
    libraryitemlist.push_back(temp);
    break;

case 3:
    cout<<"Enter Title: "<<endl;
    getline(cin, dvdtitle);
    cout<<"Enter Category: "<<endl;
    getline(cin, dvdcategory);
    cout<<"Enter Runtime: "<<endl;
    cin>>runtime;
    cin.ignore();
    cout<<"Enter Studio: "<<endl;
    getline(cin,studio);
    cout<<"Enter Release Date: "<<endl;
    getline(cin,dvdreleasedate);

    //creating and populating object
    temp= new dvd(id, cost, status, loanperiod, dvdtitle, dvdcategory, runtime, studio, dvdreleasedate);
    libraryitemlist.push_back(temp);
    break;

default:
    cout<<"You entered a choice that was not 1-3."<<endl;
    exit(-1);
    break;
}

libraryitemcnt++;
cout<<"libraryitem succesfully added."<<endl;
cout<<"Press any number to return to menu."<<endl;
cin>>any;
}

//delete libraryitems
void libraryitems::deletelibraryitems(int id)
{
//loop to get through all of the line
for (int i=0; i<libraryitemlist.size();i++)
{
 if(libraryitemlist.at(i)->getid()==id)
 {
     libraryitemlist.erase(libraryitemlist.begin()+i);
     cout<<"libraryitem Deleted."<<endl;
 }
}
}

//edit libraryitems
void libraryitems::editlibraryitems()
{
int any;
int minianswer;
//declarations for libraryitem
int id;
float cost;
string status;
int loanperiod;
//declarations for audioCd
string artist;
string audiotitle;
int track;
string audioreleasedate;
string genre;
//declarations for book
string booktitle;
string author;
int isbn;
string category;
//declarations for dvd
string dvdtitle;
string dvdcategory;
int runtime;
string studio;
string dvdreleasedate;

//libraryitem
cout<<"Enter old library id number: "<<endl;
cin>>id;
cout<<"You cannot change the id number."<<endl;
cout<<"Type new information:"<<endl;

//asking user for input
cout<<"Enter new cost: "<<endl;
cin>>cost;
cin.ignore();
cout<<"Enter new status: "<<endl;
getline(cin,status);
cout<<"Enter new LoanPeriod: "<<endl;
cin>>loanperiod;

//loop to populate the sets
for(int i=0; i<libraryitemlist.size();i++)
{
if(libraryitemlist.at(i)->getid()==id)
 {
     libraryitemlist.at(i)->setid(id);
     libraryitemlist.at(i)->setcost(cost);
     libraryitemlist.at(i)->setstatus(status);
     libraryitemlist.at(i)->setloanperiod(loanperiod);
 }
}

//have a mini menu for each child class
cout<<endl<<"Mini Menu:"<<endl;
cout<<"1 - AudioCd: "<<endl;
cout<<"2 - Book: "<<endl;
cout<<"3 - Dvd: "<<endl;
cin>>minianswer;
cin.ignore();

switch (minianswer)
{
case 1:
    cout<<"Enter Old Artist: "<<endl;
    getline(cin, artist);
    cout<<"You cannot change the Artist Name."<<endl;
    cout<<"Type new information:"<<endl;

    cout<<"Enter New Title: "<<endl;
    getline(cin, audiotitle);
    cout<<"Enter New Track: "<<endl;
    cin>>track;
    cin.ignore();
    cout<<"Enter New Release Date: "<<endl;
    getline(cin, audioreleasedate);
    cout<<"Enter New Genre: "<<endl;
    getline(cin, genre);

    /*
    //loop to populate the sets
    for(int i=0; i<libraryitemlist.size();i++)
    {  
    if(libraryitemlist.at(i)->getartist()==artist)
    {
     libraryitemlist.at(i)->setaudiotitle(audiotitle);
     libraryitemlist.at(i)->settrack(track);
     libraryitemlist.at(i)->setreleasedate(audioreleasedate);
     libraryitemlist.at(i)->setgenre(genre);
    }
    }
    */
    break;

case 2:
    cout<<"Enter Old Author: "<<endl;
    getline(cin, author);
    cout<<"You cannot change the Artist Name."<<endl;
    cout<<"Type new information:"<<endl;

    cout<<"Enter Title: "<<endl;
    getline(cin,booktitle);
    cout<<"Enter ISBN: "<<endl;
    cin>>isbn;
    cin.ignore();
    cout<<"Enter Category: "<<endl;
    getline(cin, category);

    /*
    //loop to populate the sets
    for(int i=0; i<libraryitemlist.size();i++)
    {  
    if(libraryitemlist.at(i)->getauthor()==author)
    {
     libraryitemlist.at(i)->setbooktitle(booktitle);
     libraryitemlist.at(i)->setisbn(isbn);
     libraryitemlist.at(i)->setcategory(category);
    }
    }
    */

    break;

case 3:
    cout<<"Enter Old Title: "<<endl;
    getline(cin, dvdtitle);
    cout<<"You cannot change the Title Name."<<endl;
    cout<<"Type new information:"<<endl;

    cout<<"Enter Category: "<<endl;
    getline(cin, dvdcategory);
    cout<<"Enter Runtime: "<<endl;
    cin>>runtime;
    cin.ignore();
    cout<<"Enter Studio: "<<endl;
    getline(cin,studio);
    cout<<"Enter Release Date: "<<endl;
    getline(cin,dvdreleasedate);

    /*
    //loop to populate the sets
    for(int i=0; i<libraryitemlist.size();i++)
    {  
    if(libraryitemlist.at(i)->getdvdtitle()==dvdtitle)
    {
     libraryitemlist.at(i)->setcategory(dvdcategory);
     libraryitemlist.at(i)->setruntime(runtime);
     libraryitemlist.at(i)->setstudio(studio);
     libraryitemlist.at(i)->setreleasedate(dvdreleasedate);
    }
    }
    */
    break;

default:
    cout<<"You entered a choice that was not 1-3."<<endl;
    exit(-1);
    break;
}
}

//search for libraryitems
libraryitem* libraryitems::searchforlibraryitems(int id)
{
    for(int i=0;i<libraryitemlist.size();i++)
        {
            if(libraryitemlist[i]->getid()==id)
            {
                cout<<"libraryitem found."<<endl;
                return libraryitemlist[i];
            }
            else
            {
                cout<<"libraryitem not found."<<endl;
                return 0;
            }
        }
    return 0;
}


//print libraryitems
void libraryitems::printlibraryitems() 
{
for(int i=0; i<libraryitemlist.size();i++)
{
    cout<<"Here is the LibraryItem information: "<<endl;
    cout<<libraryitemlist.at(i)->getid()<<" "<<libraryitemlist.at(i)->getcost()<<" "<<libraryitemlist.at(i)->getstatus()<<" "<<libraryitemlist.at(i)->getloanperiod()<<endl;
}
}

//to put into data
void libraryitems::loadlibraryitems() 
{ 
    //declarations
    int libid;
    string author;
    string title;
    int isbn;
    float cost;
    string status;
    string line;
    ifstream fin;
    int itype;
    string artist;
    int track;
    string releasedate;
    string genre;
    string atitle;
    string btitle;
    string category;
    string dtitle;
    int runtime;
    string studio;
    int id;
    int loanperiod;
  

        //open libraryitems.dat
        fin.open("libraryitems.dat");
        fin>>libraryitemcnt; 
        fin.ignore();
        libraryitem* temp;

        //loop to put it into dat file
        for(int i=0;i<libraryitemcnt;i++)
        {
        fin>>id>>cost>>status>>loanperiod;

        if (itype == 1)
        {
	    libraryitemlist.push_back(new libraryitem(id,cost,status,loanperiod));        
        }
        
        //audioCd
        else if (itype == 2)
        {
        getline (fin, artist);
        getline (fin, title);
        cin>>track;
        fin.ignore();
        getline(fin, releasedate);
        getline(fin, genre);

        libraryitemlist.push_back( new audioCd (id,cost,status,loanperiod,artist,atitle,track,releasedate,genre));
        }  
       
        //book
        else if (itype == 3)
        {
        getline (fin, btitle);
        getline (fin, author);
        cin>>isbn;
        fin.ignore();
        getline (fin, category);
        
        libraryitemlist.push_back( new book (id,cost,status,loanperiod,btitle,author,isbn,category));
        }

        //dvd
        else if (itype == 4)
        {
        getline (fin, dtitle);
        getline (fin, category);
        cin>>runtime;
        fin.ignore();
        getline (fin, studio);
        getline (fin, releasedate);

        libraryitemlist.push_back( new dvd (id,cost,status,loanperiod,dtitle,category,runtime,studio,releasedate));
        }
        }
        fin.close();
}

//store libraryitems
void libraryitems::storelibraryitems() {}
/*
{
    //loading it into the dat file
    ofstream fout;
    fout.open("libraryitems.dat");
    fout<<libraryitemcnt<<endl;

    libraryitem *temp;
    for(auto it = libraryitemlist.begin(); it !=libraryitemlist.end(); ++it)
    {
        temp=*it;
        fout<<temp->getid()<<" "<<temp->getcost()<<" "<<temp->getstatus()<<" "<<temp->getloanperiod()<<endl;
        
        if (typeid (**it) == typeid (libraryitem))
        {
        fout << "1" << endl; 
        }

        else if ( typeid(**it) == typeid(audioCd) )
        {
          audioCd *temp = dynamic_cast <audioCd*>(*it);
          fout << "2" << endl;
          fout << temp->getartist() << " " << temp-> getaudiotitle()<<" "<<temp->gettrack()<<" "<<temp->getreleasedate()<<" "<<temp->getgenre()<<endl;
        }

       //else if (typeid (**it) == typeid (peritem) )

    }
    fout.close();
}
*/
