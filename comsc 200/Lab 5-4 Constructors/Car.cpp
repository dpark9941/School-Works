//*****************
//Program Name: Lab 5-4: Constructors
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: write a Car class with constructors and initialize objects using those constructors
//*****************

#include "Car.h"
#include <iostream>

using namespace std;

//constructors
Car::Car(){
  make = "";
  year = 0;
}

Car::Car(string m){
  make = m;
  year = 0;
}

Car::Car(int y){
  make = "";
  year = y;
}

Car::Car(string m, int y){
  make = m;
  year = y;
}

//returns the value of make
string Car::getMake(){
  return make;
}

//returns the value of year
int Car::getYear(){
  return year;
}

//assigns a value to make
void Car::setMake(string m){
  make = m;
}

//assigns a value to year
void Car::setYear(int y){
  if (y >= 0){
    year = y;
  }

  //input validation
  else {
    cout << "Invalid value!" << endl;
    cout << "Enter again: ";
    cin >> y;
    setYear(y);
  }
}
