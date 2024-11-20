#include "AudioCD.h"

AudioCD::AudioCD(int id, double cost, std::string status, int loanPeriod, 
                 std::string artist, std::string title, int tracks, std::string releaseDate, std::string genre)
    : LibraryItem(id, cost, status, loanPeriod), artist(artist), title(title), tracks(tracks), releaseDate(releaseDate), genre(genre) {}

void AudioCD::display(std::ostream& os) const {
    os << "Audio CD\n"
       << "ID: " << id << "\n"
       << "Title: " << title << "\n"
       << "Artist: " << artist << "\n"
       << "Tracks: " << tracks << "\n"
       << "Release Date: " << releaseDate << "\n"
       << "Genre: " << genre << "\n"
       << "Cost: $" << cost << "\n"
       << "Status: " << status << "\n"
       << "Loan Period: " << loanPeriod << " days\n";
}
