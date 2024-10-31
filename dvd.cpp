//child class

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

#include "dvd.h"
#include "libraryitem.h"

//default constructor
dvd::dvd()
{
    title=" ";
    category=" ";
    runtime=0;
    studio=" ";
    releasedate=" ";
}

//basic constructor
dvd::dvd(int ids, float costs, string statuss, int loanperiods, string titles, string categories, int runtimes, string studios, string releasedates) : libraryitem(ids, costs, statuss, loanperiods)
{
    title=titles;
    category=categories;
    runtime=runtimes;
    studio=studios;
    releasedate=releasedates;
}

void dvd::print()
{
    libraryitem::print();
    cout<<"Title: "<<title<<endl;
    cout<<"Category: "<<category<<endl;
    cout<<"Runtime: "<<runtime<<endl;
    cout<<"Studio: "<<studio<<endl;
    cout<<"Release Date: "<<releasedate<<endl;
}

//sets and gets
void dvd::setdvdtitle(string titles) {title=titles;}
string dvd::getdvdtitle() {return title;}
void dvd::setcategory(string categories) {category=categories;}
string dvd::getcategory() {return category;}
void dvd::setruntime(int runtimes) {runtime=runtimes;}
int dvd::getruntime() {return runtime;}
void dvd::setstudio(string studios) {studio=studios;}
string dvd::getstudio() {return studio;}
void dvd::setreleasedate(string releasedates) {releasedate=releasedates;}
string dvd::getreleasedate() {return releasedate;}