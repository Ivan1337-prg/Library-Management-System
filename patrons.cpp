#include<string>
#include<vector>
#include<iostream>
#include<fstream>

#include "patrons.h"
#include "patron.h"

#define CHUNKSIZE 2

//default constructor
patrons::patrons()
{
   
}

//add patrons
void patrons::addpatrons()
{
//declarations
int patronid;
string name;
int finebal;
int booksout;
int any;
//prompt users for id/name/bal/#of books borrowed
cout<<"Enter Patron id number: "<<endl;
cin>>patronid;
cin.ignore();
cout<<"Enter Patrons name: "<<endl;
getline(cin,name);
cout<<"Enter Fine balance: "<<endl;
cin>>finebal;
cout<<"Enter number of books borrowed: "<<endl;
cin>>booksout;

//create and populate patron object
patron* temp=new patron(patronid,name,finebal,booksout);
patronlist.push_back(temp);

//added successfully
patcnt++;
cout<<"Patron succesfully added."<<endl;
cout<<"Press any number to return to menu."<<endl;
cin>>any;
}

//edit patrons
void patrons::editpatrons()
{
int patronid;
string name;
int finebal;
int booksout;

//prompt patron for old id/new information
cout<<"Enter the old patron id number: "<<endl;
cin>>patronid;
cin.ignore();
cout<<"You cannot change the patron id number."<<endl;
cout<<"Type new information:"<<endl;
cout<<"Enter new name."<<endl;
getline(cin, name);
cout<<"Enter new fine balance."<<endl;
cin>>finebal;
cout<<"Enter new number of books borrowed."<<endl;
cin>>booksout;

//populate it to the vector
for(int i=0; i<patronlist.size();i++)
{
if(patronlist.at(i)->getid()==patronid)
 {
     patronlist.at(i)->setname(name);
     patronlist.at(i)->setfinebalances(finebal);
     patronlist.at(i)->setnumofbooksout(booksout);
 }
}
}

//delete patrons
void patrons::deletepatrons(int patronid)
{
//make sure id matches the one that they sent
for (int i=0; i<patronlist.size();i++)
{
 if(patronlist[i]->getid()==patronid)
 {
     //delete the line
     patronlist.erase(patronlist.begin()+i);
     patcnt--;
    cout<<"Patron Deleted."<<endl;
 }
}
}

//searchforpatrons
patron* patrons::searchforpatrons(int patronid)
{
for(int i=0;i<patronlist.size();i++)
{
    //make sure the id is the one that they said
    if(patronlist[i]->getid()==patronid)
    {
        //return pointer
        cout<<"Patron found."<<endl;
        return patronlist[i];
    }
    else
    {
        cout<<"Patron not found."<<endl;
    }
}
return 0;
}

//print patrons
void patrons::printpatrons()
{
//to print whats in the vector!
for(int i=0; i<patronlist.size();i++)
{
    cout<<"Here is the Patron information: "<<endl;
    cout<<patronlist.at(i)->getid()<<" "<<patronlist.at(i)->getname()<<" "<<patronlist.at(i)->getfinebalances()<<" "<<patronlist.at(i)->getnumofbooksout()<<endl;
}
}

//printing single patron 
void patrons::printsinglepatrons()
{
    int newpatronid;
    cout<<"Enter the patron id: "<<endl;
    cin>>newpatronid;
    for(int i=0; i<patronlist.size();i++)
    {
    if(patronlist.at(i)->getid()==newpatronid)
    {
     cout<<patronlist.at(i)->getid()<<" "<<patronlist.at(i)->getname()<<" "<<patronlist.at(i)->getfinebalances()<<" "<<patronlist.at(i)->getnumofbooksout()<<endl;
    }
    }
}

//to load into the database
void patrons::loadpatrons()
{
    int patronid;
    string name;
    int finebal;
    int booksout;

        ifstream fin;
        fin.open("patrons.dat");
        fin>>patcnt; 
        fin.ignore();
        patron* temp;

        for(int i=0;i<patronlist.size();i++)
        {
        fin>>patronid>>name>>finebal>>booksout;
        cout<<patronid<<name<<finebal<<booksout;

        patron* temp=new patron(patronid,name,finebal,booksout);
        patronlist.push_back(temp);
        }
        fin.close();
}

//store patrons
void patrons::storepatrons()
{
    ofstream fout;
    fout.open("patrons.dat");
    fout<<patcnt<<endl;

    patron *temp;
    for(int i=0;i<patronlist.size();i++)
    {
        fout<<patronlist.at(i)->getid()<<" "<<patronlist.at(i)->getname()<<" "<<patronlist.at(i)->getfinebalances()<<" "<<patronlist.at(i)->getnumofbooksout()<<endl;
    }
    fout.close();
}

