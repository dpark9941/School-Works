#ifndef THEATER_H
#define THEATER_H

#include "Venue.h"
#include <iostream>
#include <iomanip>
#include <string>

//const int W1 = 2;

/*
-----------------------
  Theater : Venue
-----------------------
- name : string
- address : string
- cityStateZip : string
- concessionSales : float
- potentialRevenue : float
-----------------------
+ Theater()
+ Theater(string, string, string, float, string, int, int, float)
+ getPotentialRevenue() : float
+ print() : void
----------------------
*/

class Theater : public Venue {
private:
  string name;
  string address;
  string cityStateZip;
  float concessionSales;
  float potentialRevenue;
public:
  //constructors
  Theater() : Venue() {
    name = "";
    address = "";
    cityStateZip = "";
    concessionSales = 0.0;
    potentialRevenue = 0.0;
  }

  Theater(string name, string address, string cityStateZip, float concessionSales, string type, int yearOpened, int capacity, float price) :
  Venue(type, yearOpened, capacity, price) {
    this->name = name;
    this->address = address;
    this->cityStateZip = cityStateZip;
    this->concessionSales = concessionSales;
    potentialRevenue = 0.0;
  }

  //getPotentialRevenue calculates the potential revenue of the venue and returns the value
  //redefines getPotentialRevenue() of the base class
  float getPotentialRevenue() {
    potentialRevenue = Venue::getPotentialRevenue() + concessionSales;
    return potentialRevenue;
  }

  //print out information about Theater
  void printTheater() {
    cout << fixed << setprecision(W1);
    cout << "Type: " << getType() << endl;
    cout << "Year opened: " << getYearOpened() << endl;
    cout << "Capacity: " << getCapacity() << endl;
    cout << "Average price: $" << getPrice() << endl;
    cout << "Name: " << name << endl;
    cout << "Address: " << address <<", " << cityStateZip << endl;
    cout << "Concession sales: $" << concessionSales << endl;
    cout << "Potential revenue: $" << getPotentialRevenue() << endl;
  }
};
#endif
