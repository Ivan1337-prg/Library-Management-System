//collection class

#ifndef LIBRARYITEMS_H
#define LIBRARYITEMS_H

#include "libraryitems.h"
#include "libraryitem.h"
using namespace std;

class libraryitems
{
    private:
    vector<libraryitem*> libraryitemlist;

    int libraryitemcnt;
    int libraryitemcap;
    
    public:
    libraryitems();
    //basic ones
    void addlibraryitems();
    void deletelibraryitems(int id);
    void editlibraryitems();
    void printlibraryitems();
    void loadlibraryitems();
    void storelibraryitems();
    //extra oness
    libraryitem *searchforlibraryitems(int id);

};
#endif