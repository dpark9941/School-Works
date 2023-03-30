//*****************
//Program Name: Lab 6-1: Accelerate and Brake That Car
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: write a Car class and accelerate or brake the car
//*****************

#include "Car.h"
#include <iostream>
#include <string>
#include <cmath> //abs()

using namespace std;

//constructor
Car::Car(string m, int y){
  make = m;
  year = y;
  speed = 0;
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
    cout << "Invalid year!" << endl;
    cout << "Enter again: ";
    cin >> y;
    setYear(y);
  }
}

//assigns a value to speed
void Car::setSpeed(int s){
  if (s >= 0){
    speed = s;
  }

  //input validation
  else {
    cout << "Invalid speed!" << endl;
    cout << "Enter again: ";
    cin >> s;
    setSpeed(s);
  }
}

//returns the value of make
string Car::getMake(){
  return make;
}

//returns the value of year
int Car::getYear(){
  return year;
}

//returns the value of speed
int Car::getSpeed(){
  return speed;
}

//increases car speed
void Car::accelerate(){
  cout << "Accelerating..." << endl;
  speed = speed + ACC_RATE;
}

//decreases car speed
void Car::brake(){
  cout << "Braking..." << endl;
  if (getSpeed() < abs(BRK_RATE)){
    speed = 0;
  } else {
    speed = speed + BRK_RATE;
  }
}

//displays the status of the car
void Car::displayStat(){
  cout << getMake() << " | " << getYear() << " | " << getSpeed() << endl;
}
