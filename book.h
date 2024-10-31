//child class
#include "libraryitem.h"

#ifndef BOOK_H
#define BOOK_H

class book : public libraryitem
{
    private:
    //vector
    //vector<book*> booklist;
    string title;
    string author;
    int isbn;
    string category;

    public:
    book();
    book(int, float, string, int, string, string, int, string);
   
    void setbooktitle(string titles);
    string getbooktitle();
    void setauthor(string authors);
    string getauthor();
    void setisbn(int isbns);
    int getisbn();
    void setcategory(string categories);
    string getcategory();
    //virtual print function
    void print();

};
#endif
