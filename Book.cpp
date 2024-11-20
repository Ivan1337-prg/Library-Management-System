#include "Book.h"

Book::Book(int id, double cost, std::string status, int loanPeriod, 
           std::string title, std::string author, std::string isbn, std::string category)
    : LibraryItem(id, cost, status, loanPeriod), title(title), author(author), isbn(isbn), category(category) {}

void Book::display(std::ostream& os) const {
    os << "Book\n"
       << "ID: " << id << "\n"
       << "Title: " << title << "\n"
       << "Author: " << author << "\n"
       << "ISBN: " << isbn << "\n"
       << "Category: " << category << "\n"
       << "Cost: $" << cost << "\n"
       << "Status: " << status << "\n"
       << "Loan Period: " << loanPeriod << " days\n";
}
