#include "LibraryItem.h"

LibraryItem::LibraryItem(int id, double cost, std::string status, int loanPeriod)
    : id(id), cost(cost), status(status), loanPeriod(loanPeriod) {}

int LibraryItem::getID() const { return id; }

double LibraryItem::getCost() const { return cost; }

std::string LibraryItem::getStatus() const { return status; }

int LibraryItem::getLoanPeriod() const { return loanPeriod; }

void LibraryItem::setStatus(std::string newStatus) {
    if (newStatus == "In" || newStatus == "Out" || newStatus == "Lost") {
        status = newStatus;
    } else {
        std::cerr << "Error: Invalid status. Valid options are 'In', 'Out', or 'Lost'.\n";
    }
}

std::ostream& operator<<(std::ostream& os, const LibraryItem& item) {
    item.display(os);
    return os;
}
