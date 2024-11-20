#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <string>
#include <iostream>

class LibraryItem {
protected:
    int id;                     
    double cost;                
    std::string status;         
    int loanPeriod;             

public:

    LibraryItem(int id, double cost, std::string status, int loanPeriod);
    virtual ~LibraryItem() {}

    int getID() const;                  
    double getCost() const;             
    std::string getStatus() const;      
    int getLoanPeriod() const;          

    void setStatus(std::string newStatus); 

    virtual void display(std::ostream& os) const = 0;

    friend std::ostream& operator<<(std::ostream& os, const LibraryItem& item);
};

#endif
