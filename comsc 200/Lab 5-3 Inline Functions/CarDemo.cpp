//*****************
//Program Name: Lab 5-3: Inline Functions
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: separate codes into TWO files, using inline functions
//*****************

#include "Car.h"
#include <iostream>

using namespace std;

int main(){

  //declares an instance of the class and assigns values to the member variables
  Car myCar;
  myCar.setMake("Hyundai");
  myCar.setYear(2020);

  //displays the object's data
  cout << myCar.getMake() << endl;
  cout << myCar.getYear() << endl;

  cout << endl;
  cout << "I attest that this code is my original programming work, and that I received" << endl;
  cout << "no help creating it. I attest that I did not copy this code or any portion of this" << endl;
  cout << "code from any source." << endl;

  return 0;
}
