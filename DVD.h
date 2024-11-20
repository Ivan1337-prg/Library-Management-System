#ifndef DVD_H
#define DVD_H

#include "LibraryItem.h"

class DVD : public LibraryItem {
private:
    std::string title;
    std::string category; 
    int runtime;          
    std::string studio;  
    std::string releaseDate;

public:
    DVD(int id, double cost, std::string status, int loanPeriod, 
        std::string title, std::string category, int runtime, std::string studio, std::string releaseDate);

    void display(std::ostream& os) const override; 
};

#endif
