//Glushko Taras, CSCE 1040.001, Homework 4
#include "Patron.h"
#include <iostream>

Patron::Patron(int id, std::string name) : id(id), name(name), fineBalance(0) {}

void Patron::display() const {
    std::cout << "Patron ID: " << id << "\nName: " << name << "\nFine Balance: $" << fineBalance << "\n";
}

int Patron::getID() const { return id; }
std::string Patron::getName() const { return name; }
double Patron::getFineBalance() const { return fineBalance; }
void Patron::updateFine(double amount) { fineBalance += amount; }
