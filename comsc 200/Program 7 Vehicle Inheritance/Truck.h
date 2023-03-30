//*****************
//Program Name: Program 7: Vehicle Inheritance
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: write Sedan and Truck class that inherits Vehicle class and print out information about them
//*****************

#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"
using namespace std;

/*
----------------------------
Truck :: Vehicle
----------------------------
- towingCapacity : int
- axles : int
- seats : int
----------------------------
+ Truck()
+ Truck(string, int, int, int, int, int)
+ printVehicle() : void
----------------------------
*/

class Truck : public Vehicle{
private:

  int towingCapacity;
  int axles;
  int seats; //additional member variable

public:

  //constructors
  Truck() : Vehicle(){
    towingCapacity = 0;
    axles = 0;
    seats = 0;
  }

  Truck(string n, int y, int m, int t, int a, int s) : Vehicle(n, y, m){
    towingCapacity = t;
    axles = a;
    seats = s;
  }

  void printVehicle(){
    Vehicle::print();
    cout << "Towing capacity: " << towingCapacity  << " tons" << endl;
    cout << "Number of Axles: " << axles << endl;
    cout << "Number of Seats: " << seats << endl;
  }
};

#endif
