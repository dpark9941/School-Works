//*****************
//Program Name: Lab 5-4: Constructors
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: write a Car class with constructors and initialize objects using those constructors
//*****************

#include "Car.h"
#include <iostream>

using namespace std;

int main(){
  //creates Car objects and initializes some member variables using constructors
  Car myCar1;
  Car myCar2("Ford");
  Car myCar3(2016);
  Car myCar4("Ford", 2005);

  //member variables are partly initialized
  cout << myCar1.getMake() << ' ' << myCar1.getYear() << endl;
  cout << myCar2.getMake() << ' ' << myCar2.getYear() << endl;
  cout << myCar3.getMake() << ' ' << myCar3.getYear() << endl;
  cout << myCar4.getMake() << ' ' << myCar4.getYear() << endl;

  //sets uninitialized member variables
  myCar1.setMake("Chevrolet");
  myCar1.setYear(2011);
  myCar2.setYear(2019);
  myCar3.setMake("Hyundai");

  //member variables are fully initialized
  cout << endl;
  cout << myCar1.getMake() << ' ' << myCar1.getYear() << endl;
  cout << myCar2.getMake() << ' ' << myCar2.getYear() << endl;
  cout << myCar3.getMake() << ' ' << myCar3.getYear() << endl;
  cout << myCar4.getMake() << ' ' << myCar4.getYear() << endl;

  cout << endl;
  cout << "I attest that this code is my original programming work, and that I received" << endl;
  cout << "no help creating it. I attest that I did not copy this code or any portion of this" << endl;
  cout << "code from any source." << endl;

  return 0;
}
