/*
needs to declare these things!
set/get:
Name (string)
ID (int)
Fine balance (int)
# of books out (int)
*/
#ifndef PATRON_H
#define PATRON_H

using namespace std;

class patron
{
    private:
    int id;
    string name;
    int finebalance;
    int numofbooksout;

    public:
    patron();
    patron(int ids, string names, int finebalances, int numofbooksouts);
    void setname(string names);
    string getname();
    void setid(int ids);
    int getid();
    void setfinebalances(int finebalances);
    int getfinebalances();
    void setnumofbooksout(int numofbooksouts);
    int getnumofbooksout();
};
#endif