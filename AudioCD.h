#ifndef AUDIOCD_H
#define AUDIOCD_H

#include "LibraryItem.h"

class AudioCD : public LibraryItem {
private:
    std::string artist;
    std::string title;
    int tracks;
    std::string releaseDate;
    std::string genre; 

public:
    AudioCD(int id, double cost, std::string status, int loanPeriod, 
            std::string artist, std::string title, int tracks, std::string releaseDate, std::string genre);

    void display(std::ostream& os) const override; 
};

#endif
