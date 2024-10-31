#ifndef LOANS_H
#define LOANS_H

#include "loan.h"

using namespace std;

class loans
{
    private:
    //vector
    vector<loan*> loanlist;

    int loancnt;
    int loancap;
    
    public:
    loans();

    //basic ones
    void editloans();
    void printloans();
    void storeloans();
    void loadloans();
    void addloans();
    void deleteloans();

    //extra ones
    void checkoutbook();
    void checkinbook();
    void listofoverduebooks();
    void reportlostbook();
    void listbookforpatrons();
    void updateloan();
    void recheckbook();
    void fineinformation();
    void printsingleloans();
};
#endif

