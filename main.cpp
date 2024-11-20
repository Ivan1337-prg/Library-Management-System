#include "LibraryItem.h"
#include "Book.h"
#include "AudioCD.h"
#include "DVD.h"
#include "Patron.h"
#include "Loan.h"
#include <iostream>
#include <vector>
#include <memory>

void displayMenu() {
    std::cout << "\nMENU:\n";
    std::cout << "1 - Add Book\n";
    std::cout << "2 - Add Audio CD\n";
    std::cout << "3 - Add DVD\n";
    std::cout << "4 - Add Patron\n";
    std::cout << "5 - Create Loan\n";
    std::cout << "6 - Print All Library Items\n";
    std::cout << "7 - Print All Patrons\n";
    std::cout << "8 - Print All Loans\n";
    std::cout << "0 - Quit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    std::vector<std::unique_ptr<LibraryItem>> items; // Polymorphic collection
    std::vector<Patron> patrons;
    std::vector<Loan> loans;

    int choice;
    int loanCounter = 0;

    while (true) {
        displayMenu();
        std::cin >> choice;

        if (choice == 0) {
            std::cout << "Exiting the system.\n";
            break;
        }

        switch (choice) {
            case 1: { // Add Book
                int id, loanPeriod;
                double cost;
                std::string title, author, isbn, category;

                std::cout << "Enter Book ID: ";
                std::cin >> id;
                std::cin.ignore();
                std::cout << "Enter Title: ";
                std::getline(std::cin, title);
                std::cout << "Enter Author: ";
                std::getline(std::cin, author);
                std::cout << "Enter ISBN: ";
                std::getline(std::cin, isbn);
                std::cout << "Enter Category: ";
                std::getline(std::cin, category);
                std::cout << "Enter Cost: ";
                std::cin >> cost;
                std::cout << "Enter Loan Period (in days): ";
                std::cin >> loanPeriod;

                items.push_back(std::unique_ptr<Book>(new Book(id, cost, "In", loanPeriod, title, author, isbn, category)));
                std::cout << "Book added successfully.\n";
                break;
            }

            case 2: { // Add Audio CD
                int id, loanPeriod, tracks;
                double cost;
                std::string title, artist, releaseDate, genre;

                std::cout << "Enter Audio CD ID: ";
                std::cin >> id;
                std::cin.ignore();
                std::cout << "Enter Title: ";
                std::getline(std::cin, title);
                std::cout << "Enter Artist: ";
                std::getline(std::cin, artist);
                std::cout << "Enter Tracks: ";
                std::cin >> tracks;
                std::cin.ignore();
                std::cout << "Enter Release Date: ";
                std::getline(std::cin, releaseDate);
                std::cout << "Enter Genre: ";
                std::getline(std::cin, genre);
                std::cout << "Enter Cost: ";
                std::cin >> cost;
                std::cout << "Enter Loan Period (in days): ";
                std::cin >> loanPeriod;

                items.push_back(std::unique_ptr<AudioCD>(new AudioCD(id, cost, "In", loanPeriod, artist, title, tracks, releaseDate, genre)));
                std::cout << "Audio CD added successfully.\n";
                break;
            }

            case 3: { // Add DVD
                int id, loanPeriod, runtime;
                double cost;
                std::string title, category, studio, releaseDate;

                std::cout << "Enter DVD ID: ";
                std::cin >> id;
                std::cin.ignore();
                std::cout << "Enter Title: ";
                std::getline(std::cin, title);
                std::cout << "Enter Category: ";
                std::getline(std::cin, category);
                std::cout << "Enter Runtime (in minutes): ";
                std::cin >> runtime;
                std::cin.ignore();
                std::cout << "Enter Studio: ";
                std::getline(std::cin, studio);
                std::cout << "Enter Release Date: ";
                std::getline(std::cin, releaseDate);
                std::cout << "Enter Cost: ";
                std::cin >> cost;
                std::cout << "Enter Loan Period (in days): ";
                std::cin >> loanPeriod;

                items.push_back(std::unique_ptr<DVD>(new DVD(id, cost, "In", loanPeriod, title, category, runtime, studio, releaseDate)));
                std::cout << "DVD added successfully.\n";
                break;
            }

            case 4: { // Add Patron
                int id;
                std::string name;

                std::cout << "Enter Patron ID: ";
                std::cin >> id;
                std::cin.ignore();
                std::cout << "Enter Patron Name: ";
                std::getline(std::cin, name);

                patrons.emplace_back(id, name);
                std::cout << "Patron added successfully.\n";
                break;
            }

            case 5: { // Create Loan
                int patronID, itemID;
                std::string dueDate;

                std::cout << "Enter Patron ID: ";
                std::cin >> patronID;
                std::cout << "Enter Library Item ID: ";
                std::cin >> itemID;
                std::cout << "Enter Due Date: ";
                std::cin >> dueDate;

                Patron* patron = nullptr;
                LibraryItem* item = nullptr;

                for (auto& p : patrons)
                    if (p.getID() == patronID) patron = &p;

                for (const auto& i : items)
                    if (i->getID() == itemID) item = i.get();

                if (patron && item) {
                    loans.emplace_back(loanCounter++, patron, item, dueDate);
                    item->setStatus("Out");
                    std::cout << "Loan created successfully.\n";
                } else {
                    std::cout << "Invalid Patron ID or Library Item ID.\n";
                }
                break;
            }

            case 6: { // Print All Library Items
                for (const auto& item : items)
                    std::cout << *item << "\n";
                break;
            }

            case 7: { // Print All Patrons
                for (const auto& patron : patrons)
                    patron.display();
                break;
            }

            case 8: { // Print All Loans
                for (const auto& loan : loans)
                    loan.display();
                break;
            }

            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
