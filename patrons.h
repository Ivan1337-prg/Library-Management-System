#ifndef PATRONS_H
#define PATRONS_H

#include "patron.h"

using namespace std;

class patrons
{
    private:
    //vector
    vector<patron*> patronlist;

    int patcnt;
    int patcap;

    public:
    patrons();

    //basic ones
    void addpatrons();
    void editpatrons();
    void deletepatrons(int patronid);
    void printpatrons();
    void loadpatrons();
    void storepatrons();
    void printsinglepatrons();

    //other ones
    patron *searchforpatrons(int patronid);
   
  

};
#endif