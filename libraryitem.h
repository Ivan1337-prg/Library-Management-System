//entity class
//base class

#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

using namespace std;

class libraryitem
{
    //use protected and not private
    protected:
    //vector
    vector<libraryitem*> libraryitemlist;
    int id;
    float cost;
    string status;
    int loanperiod;

    public:
    libraryitem();
    libraryitem(int ids, float costs, string statuss, int loanperiods);

    void setid(int ids);
    int getid();
    void setcost(float costs);
    float getcost();
    void setstatus(string statuss);
    string getstatus();
    void setloanperiod(int loanperiods);
    int getloanperiod();

    //need a print function
    virtual void print();
    virtual void rawprint();

};
#endif