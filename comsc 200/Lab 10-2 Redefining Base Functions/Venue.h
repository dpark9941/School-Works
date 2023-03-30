#ifndef VENUE_H
#define VENUE_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int W1 = 2;

/*
-----------------------
  Venue
-----------------------
- type : string
- yearOpened : int
- capacity : int
- price : float
- potentialRevenue : float
-----------------------
+ Venue()
+ Venue(string, int, int, float)
+ getType() : string
+ getYearOpened() : int
+ getCapacity() : int
+ getPrice() : float
+ getPotentialRevenue() : float
+ print() : void
----------------------
*/

class Venue {
private:
  string type;
  int yearOpened;
  int capacity;
  float price;
  float potentialRevenue;
public:
  //constructors
  Venue() {
    type = "";
    yearOpened = 0;
    capacity = 0;
    price = 0.0;
    potentialRevenue = 0.0;
  }

  Venue(string type, int yearOpened, int capacity, float price) {
    this->type = type;
    this->yearOpened = yearOpened;
    this->capacity = capacity;
    this->price = price;
    potentialRevenue = 0.0;
  }

  //accessors
  string getType() {return type;}
  int getYearOpened() {return yearOpened;}
  int getCapacity() {return capacity;}
  float getPrice() {return price;}

  //getPotentialRevenue() calculates the potential revenue of the venue and returns the value
  float getPotentialRevenue() {
    potentialRevenue = capacity * price;
    return potentialRevenue;
  }

  //print out information about Venue
  void printVenue() {
    cout << fixed << setprecision(W1);
    cout << "Type: " << type << endl;
    cout << "Year opened: " << yearOpened << endl;
    cout << "Capacity: " << capacity << endl;
    cout << "Average price: $" << price << endl;
    cout << "Potential revenue: $" << getPotentialRevenue() << endl;
  }
};

#endif
