//*****************
//Program Name: Program 7: Vehicle Inheritance
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: write Sedan and Truck class that inherits Vehicle class and print informations about them
//*****************

#include "Vehicle.h"
#include "Sedan.h"
#include "Truck.h"

using namespace std;

int main() {

  //object declarations
  Vehicle Bike("Bike", 2020, 1);
  Sedan Mercedes("Mercedes", 2017, 40000, 4, false, true);
  Truck Pickup("Pickup", 2001, 232354, 1234, 2, 2);

  //outputs information about Bike
  cout << "Information about Vehicle " << Bike.getName() << endl;
  Bike.print();
  cout << endl;

  //outputs information about Mercedes
  cout << "Information about Sedan " << Mercedes.getName() << endl;
  Mercedes.printVehicle();
  cout << endl;

  //outputs information about Pickup
  cout << "Information about Truck " << Pickup.getName() << endl;
  Pickup.printVehicle();
  cout << endl;

  //tests if the inputValidation() works
  cout << "Testing input validation function..." << endl;
  Vehicle invalid_input("invalid_input", -9, -19990);

  //outputs modified information about invaild_input
  cout << "Information about Vehicle " << invalid_input.getName() << endl;
  invalid_input.print();
  cout << endl;

  cout << endl;
  cout << "I attest that this code is my original programming work, and that I received" << endl;
  cout << "no help creating it. I attest that I did not copy this code or any portion of this" << endl;
  cout << "code from any source." << endl;

  return 0;
}
