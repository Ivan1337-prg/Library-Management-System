//child class
#include "libraryitem.h"

#ifndef DVD_H
#define DVD_H

class dvd: public libraryitem
{
    private:
    //vector
    //vector<dvd*> dvdlist;
    string title;
    string category;
    int runtime;
    string studio;
    string releasedate;

    public:
    dvd();
    dvd(int, float, string, int, string, string, int, string, string);

    //virtual print function
    void print();

    void setdvdtitle(string titles);
    string getdvdtitle();
    void setcategory(string categories);
    string getcategory();
    void setruntime(int runtimes);
    int getruntime();
    void setstudio(string studios);
    string getstudio();
    void setreleasedate(string releasedates);
    string getreleasedate();
};
#endif
