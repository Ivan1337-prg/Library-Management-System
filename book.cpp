
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

#include "book.h"
#include "libraryitem.h"

//default constructor
book::book()
{
    title=" ";
    author=" ";
    isbn=0;
    category=" ";
}

//basic constructor
book::book(int ids, float costs, string statuss, int loanperiods, string titles, string authors, int isbns, string categories) : libraryitem(ids, costs, statuss, loanperiods)
{
    title=titles;
    author=authors;
    isbn=isbns;
    category=categories;
}

void book::print()
{
    libraryitem::print();
    cout<<"Title: "<<title<<endl;
    cout<<"Author: "<<author<<endl;
    cout<<"ISBN: "<<isbn<<endl;
    cout<<"Category: "<<category<<endl;
}

//sets and gets
void book::setbooktitle(string titles) {title=titles;}
string book::getbooktitle() {return title;}
void book::setauthor(string authors) {author=authors;}
string book::getauthor() {return author;}
void book::setisbn(int isbns) {isbn=isbns;}
int book::getisbn() {return isbn;}
void book::setcategory(string categories) {category=categories;}
string book::getcategory() {return category;}