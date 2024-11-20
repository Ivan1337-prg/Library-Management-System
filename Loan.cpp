#include "Loan.h"
#include <iostream>

Loan::Loan(int loanID, Patron* patron, LibraryItem* item, std::string dueDate)
    : loanID(loanID), patron(patron), item(item), dueDate(dueDate) {}
void Loan::display() const {
    std::cout << "Loan ID: " << loanID 
              << "\nPatron: " << patron->getName() 
              << "\nItem ID: " << item->getID() 
              << "\nDue Date: " << dueDate << "\n";
}

int Loan::getLoanID() const { return loanID; }
Patron* Loan::getPatron() const { return patron; }
LibraryItem* Loan::getItem() const { return item; }
std::string Loan::getDueDate() const { return dueDate; }
