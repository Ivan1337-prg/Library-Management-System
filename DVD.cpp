#include "DVD.h"

DVD::DVD(int id, double cost, std::string status, int loanPeriod, 
         std::string title, std::string category, int runtime, std::string studio, std::string releaseDate)
    : LibraryItem(id, cost, status, loanPeriod), title(title), category(category), runtime(runtime), studio(studio), releaseDate(releaseDate) {}

void DVD::display(std::ostream& os) const {
    os << "DVD\n"
       << "ID: " << id << "\n"
       << "Title: " << title << "\n"
       << "Category: " << category << "\n"
       << "Runtime: " << runtime << " minutes\n"
       << "Studio: " << studio << "\n"
       << "Release Date: " << releaseDate << "\n"
       << "Cost: $" << cost << "\n"
       << "Status: " << status << "\n"
       << "Loan Period: " << loanPeriod << " days\n";
}
