//child class

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

#include "audioCd.h"
#include "libraryitem.h"

//default constructor
audioCd::audioCd()
{
    artist=" ";
    title=" ";
    track=0;
    releasedate=" ";
    genre=" ";
}

//basic constructor
audioCd::audioCd(int ids, float costs, string statuss, int loanperiods, string artists, string titles, int tracks, string releasedates, string genres) : libraryitem(ids, costs, statuss, loanperiods)
{
    artist=artists;
    title=titles;
    track=tracks;
    releasedate=releasedates;
    genre=genres;
}

void audioCd::print()
{
    libraryitem::print(); //why doesnt this work. exact same as example..
    cout<<"Artist: "<<artist<<endl;
    cout<<"Title: "<<title<<endl;
    cout<<"Track: "<<track<<endl;
    cout<<"Release Date: "<<releasedate<<endl;
    cout<<"Genre: "<<genre<<endl;
}

//sets and gets
void audioCd::setartist(string artists) {artist=artists;}
string audioCd::getartist() {return artist;}
void audioCd::setaudiotitle(string titles) {title=titles;}
string audioCd::getaudiotitle() {return title;}
void audioCd::settrack(int tracks) {track=tracks;}
int audioCd::gettrack() {return track;}
void audioCd::setreleasedate(string releasedates) {releasedate=releasedates;}
string audioCd::getreleasedate() {return releasedate;}
void audioCd::setgenre(string genres) {genre=genres;}
string audioCd::getgenre() {return genre;}