#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

/*
-----------------------
  Date
-----------------------
- day : int
- month : int
- year : int
-----------------------
+ Date()
+ Date(int, int, int)
+ print() : void
----------------------
*/

class Date {
private:
  int day;
  int month;
  int year;
public:
  //constructor
  Date() {
    day = 0;
    month = 0;
    year = 0;
  }

  Date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
  }

  //print out date
  void print() {
    cout << month << "/" << day << "/" << year << endl;
  }
};

#endif
