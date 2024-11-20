//Glushko Taras, CSCE 1040.001, Homework 4
#ifndef PATRON_H
#define PATRON_H

#include <string>

class Patron {
private:
    int id;
    std::string name;
    double fineBalance;

public:
    Patron(int id, std::string name);
    void display() const;
    int getID() const;
    std::string getName() const;
    double getFineBalance() const;
    void updateFine(double amount);
};

#endif
