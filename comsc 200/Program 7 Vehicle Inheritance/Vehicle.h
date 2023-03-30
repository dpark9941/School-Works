//*****************
//Program Name: Program 7: Vehicle Inheritance
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: write Sedan and Truck class that inherits Vehicle class and print out information about them
//*****************

#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>
using namespace std;

/*
----------------------------
  Vehicle
----------------------------
- name : string
- year : int
- mileage : int
----------------------------
+ Vehicle()
+ Vehicle(string, int, int)
+ setName(string) : void
+ setYear(int) : void
+ setMileage(int) : void
+ getName() : string
+ getYear() : int
+ getMileage() : int
+ print() : void
+ inputValidation(int) : void
----------------------------
*/

class Vehicle{
private:

  string name; //additional member variable
  int year;
  int mileage;

public:

  //constructors
  Vehicle(){
    name = "";
    year = 0;
    mileage = 0;
  }

  Vehicle(string n, int y, int m){
    name = n;

    inputValidation(y);
    year = y;

    inputValidation(m);
    mileage = m;
  }

  //mutators
  void setName(string n) {name = n;}
  void setYear(int y) {year = y;}
  void setMileage(int m) {mileage = m;}

  //accessors
  string getName() {return name;}
  int getYear() {return year;}
  int getMileage() {return mileage;}

  //other methods
  void print(){
    cout << "Year: " << year << endl;
    cout << "Mileage: " << mileage << endl;
  }

  void inputValidation(int &input){
    while (input < 0){
      cout << "Error! Invalid input" << endl;
      cout << "Enter again: ";
      cin >> input;
    }
  }
};

#endif
