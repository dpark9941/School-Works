//*****************
//Program Name: Program 7: Vehicle Inheritance
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: write Sedan and Truck class that inherits Vehicle class and print out information about them
//*****************

#ifndef SEDAN_H
#define SEDAN_H

#include "Vehicle.h"
using namespace std;

/*
----------------------------
Sedan :: Vehicle
----------------------------
- doors : int
- hatchback : bool
- awd : bool
----------------------------
+ Sedan()
+ Sedan(string, int, int, int, bool, bool)
+ printVehicle() : void
----------------------------
*/

class Sedan : public Vehicle{
private:

  int doors;
  bool hatchback;
  bool awd; //additional member variable

public:

  //constructors
  Sedan() : Vehicle(){
    doors = 0;
    hatchback = false;
    awd = false;
  }

  Sedan(string n, int y, int m, int d, bool h, bool a) : Vehicle(n, y, m){
    doors = d;
    hatchback = h;
    awd = a;
  }

  void printVehicle(){
    Vehicle::print();
    cout << "Doors: " << doors << endl;
    cout << "Hatchback: " << (hatchback ? "Yes" : "No") << endl;
    cout << "AWD: " << (awd ? "Yes" : "No") << endl;
  }
};

#endif
