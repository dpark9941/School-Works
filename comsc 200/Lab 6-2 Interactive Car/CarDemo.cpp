//*****************
//Program Name: Lab 6-2: Interactive Car
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: write a Car class with interactive features
//*****************

#include "Car.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
  string tempMake;
  int tempYear;

  cout << "===Interactive Car Demo===" << endl << endl;
  cout << "Enter your car's make: ";
  cin >> tempMake;
  cout << "Enter your car's year: ";
  cin >> tempYear;

  Car car1(tempMake, tempYear);

  while (car1.getChoice() != 3){
    car1.displayMenu();
    if (car1.getChoice() == 1){
      car1.accelerate();
    }
    else if (car1.getChoice() == 2) {
      car1.brake();
    }
    car1.displayStat();
    cout << endl;
  }

  cout << endl << "Program ending..." << endl;

  cout << endl;
  cout << "I attest that this code is my original programming work, and that I received" << endl;
  cout << "no help creating it. I attest that I did not copy this code or any portion of this" << endl;
  cout << "code from any source." << endl;

  return 0;
}
