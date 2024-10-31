//Child class
#include "libraryitem.h"

#ifndef AUDIOCD_H
#define AUDIOCD_H

class audioCd : public libraryitem
{
    private:
    //vector
    vector<audioCd*> audioCdlist;
    string artist;
    string title;
    int track;
    string releasedate;
    string genre;

    public:
    audioCd();
    audioCd(int, float, string, int, string, string, int, string, string);

    //virtual print function
    void print();

    void setartist(string artists);
    string getartist();
    void setaudiotitle(string titles);
    string getaudiotitle();
    void settrack(int tracks);
    int gettrack();
    void setreleasedate(string releasedates);
    string getreleasedate();
    void setgenre(string genres);
    string getgenre();
};
#endif