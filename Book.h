#ifndef BOOK_H
#define BOOK_H

#include "LibraryItem.h"

class Book : public LibraryItem {
private:
    std::string title;
    std::string author;
    std::string isbn;
    std::string category; 

public:
    Book(int id, double cost, std::string status, int loanPeriod, 
         std::string title, std::string author, std::string isbn, std::string category);
    
    void display(std::ostream& os) const override; 
};

#endif
