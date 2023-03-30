//*****************
//Program Name: Program 9: Multiple Inheritance
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: write a program using multiple inheritance
//*****************

#ifndef PUBLISHEDWORK_H
#define PUBLISHEDWORK_H

#include <iostream>
#include <string>
using namespace std;

class PublishedWork {
private:
  string author;
  int yearPublished;
public:
  //constructors
  PublishedWork() {
    author = "";
    yearPublished = 0;
  }

  PublishedWork(string author, int yearPublished) {
    setAuthor(author);
    setYearPublished(yearPublished);
  }

  //mutators
  void setAuthor(string author) {this->author = author;}
  void setYearPublished(int yearPublished) {this->yearPublished = yearPublished;}

  //accessors
  string getAuthor() {return author;}
  int getYearPublished() {return yearPublished;}

  //other methods
  void printPublishedWork() {
    cout << "Author: " << getAuthor() << endl;
    cout << "Year published: " << getYearPublished() << endl;
  }
};

#endif
