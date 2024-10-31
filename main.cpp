/*
THANE TATE
CSCE 1040.001/002
HOMEWORK 4
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

#include "patron.h"
#include "patrons.h"
#include "loan.h"
#include "loans.h"
#include "libraryitem.h"
#include "libraryitems.h"
#include "audioCd.h"
#include "book.h"
#include "dvd.h"

//call each class
patrons custs;
loans sales;
libraryitems inventory;

int main()
{
    int choice = -1;
    int newid;
    int newlibraryitemid;
    int patid;
    int libraryitemid;

   custs.loadpatrons();
   sales.loadloans();
   inventory.loadlibraryitems();

   while(choice !=0)
   {
       cout<<endl<<"MENU:"<<endl;
       cout<<endl<<"LIBRARYITEM"<<endl;
       cout<<"0 - quit"<<endl; 
       cout<<"1 - add libraryitem"<<endl;
       cout<<"2 - delete libraryitem"<<endl;
       cout<<"3 - edit libraryitem"<<endl;
       cout<<"4 - print libraryitem"<<endl;
       cout<<endl<<"LOAN"<<endl;
       cout<<"5 - add loan"<<endl;
       cout<<"6 - delete loan"<<endl;
       cout<<"7 - edit loan"<<endl; 
       cout<<"8 - print loan"<<endl; 
       cout<<"9 - print single loan"<<endl; //
       cout<<"10 - checkout a book"<<endl;
       cout<<"11 - checkin a book"<<endl;
       cout<<"12 - list of overdue books"<<endl;
       cout<<"13 - fine information"<<endl;
       cout<<"14 - report lost book"<<endl;
       cout<<endl<<"PATRON"<<endl;
       cout<<"15 - add patron"<<endl;
       cout<<"16 - delete patron"<<endl;
       cout<<"17 - edit patron"<<endl;
       cout<<"18 - print patron"<<endl; 
       cout<<"19 - print single patron"<<endl; //
       cout<<endl<<"Enter your choice: ";
       cin>>choice;
       cin.ignore();
   
    switch(choice)
    {
        case 1: inventory.addlibraryitems(); break;

        case 2:
        { 
        cout<<"Enter a ID: "<<endl;
        cin>>newid;
        inventory.deletelibraryitems(newid); 
        break;
        }

        case 3: inventory.editlibraryitems(); break;
        case 4: inventory.printlibraryitems(); break;
        case 5: sales.addloans(); break;
        case 6: sales.deleteloans(); break;
        case 7: sales.editloans(); break;
        case 8: sales.printloans(); break;
        case 9: sales.printsingleloans(); break;
        case 10: sales.checkoutbook(); break;
        case 11: sales.checkinbook(); break;
        case 12: sales.listofoverduebooks(); break;
        case 13: sales.fineinformation(); break;
        case 14: sales.reportlostbook(); break;
        case 15: custs.addpatrons(); break;
        case 16:
        {
        cout<<"Enter a Patrons ID: "<<endl;
        cin>>patid;
        custs.deletepatrons(patid); 
        break;
        }
        case 17: custs.editpatrons(); break;
        case 18: custs.printpatrons(); break;
        case 19: custs.printsinglepatrons(); break;
    }
   }
   
    custs.storepatrons();
    inventory.storelibraryitems();
    sales.storeloans();

    return 0;
}