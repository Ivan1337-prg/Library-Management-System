//Glushko Taras, CSCE 1040.001, Homework 4
#ifndef LOAN_H
#define LOAN_H

#include "Patron.h"
#include "LibraryItem.h"
#include <string>

class Loan {
private:
    int loanID;
    Patron* patron;
    LibraryItem* item;
    std::string dueDate;

public:
    Loan(int loanID, Patron* patron, LibraryItem* item, std::string dueDate);
    void display() const;
    int getLoanID() const;
    Patron* getPatron() const;
    LibraryItem* getItem() const;
    std::string getDueDate() const;
};

#endif
