//*****************
//Program Name: Lab 6-1: Accelerate and Brake That Car
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: write a Car class and accelerate or brake the car
//*****************

#include "Car.h"
#include <iostream>

using namespace std;

int main(){
  Car car1("Ford", 2020);

  car1.displayStat();

  car1.accelerate();
  car1.displayStat();

  car1.accelerate();
  car1.displayStat();

  car1.accelerate();
  car1.displayStat();

  car1.brake();
  car1.displayStat();

  car1.brake();
  car1.displayStat();

  car1.brake();
  car1.displayStat();

  car1.brake();
  car1.displayStat();

  cout << endl;
  cout << "I attest that this code is my original programming work, and that I received" << endl;
  cout << "no help creating it. I attest that I did not copy this code or any portion of this" << endl;
  cout << "code from any source." << endl;

  return 0;
}
