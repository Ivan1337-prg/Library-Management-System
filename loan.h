/*
needs to declare these things!
Loan ID (Set/Get)
Book ID (Set/Get)
Patron ID (Set/Get)
Due Date/Time
(string)
Current Status 
(Overdue, normal)
*/
#ifndef LOAN_H
#define LOAN_H
using namespace std;
class loan
{

    private:
    int loanid;
    int bookid;
    int patronid;
    string datetime;
    string status;

    public:
    loan();
    loan(int loanids, int bookids, int patronids, string datetimes, string statuss);
    void setloanid(int loanids);
    int getloanid();
    void setbookid(int bookids);
    int getbookids();
    void setpatronid(int patronids);
    int getpatronid();
    void setdatetime(string datetimes);
    string getdatetime();
    void setstatus(string statuss);
    string getstatus();

};
#endif