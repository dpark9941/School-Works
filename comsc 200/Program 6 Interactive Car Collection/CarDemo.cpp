//*****************
//Program Name: Program 6: Interactive Car Collection
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: menu-driven program that provides interactive features of Car class
//*****************

#include "Car.h"
#include <iostream>
#include <string>
using namespace std;

//function prototypes
short displayMainMenu();
void displayCollection(vector<Car>);
void addCar(vector<Car>&);
void removeCar(vector<Car>&);
void accelerateCar(vector<Car>&);
void brakeCar(vector<Car>&);

int main(){

  //variable definitions
  vector<Car> carCollection;
  bool quit = false;
  bool emptyCollection = carCollection.empty();

  //body of the program
  while(!quit){
    emptyCollection = carCollection.empty();
    switch (displayMainMenu()){
    case 1:
      if(!emptyCollection){
        cout << "Car Inventory:" << endl;
        displayCollection(carCollection);
      }
      else{
        cout << "\t> ERROR: The collection is empty" << endl;
      }
      break;

    case 2:
      addCar(carCollection);
      break;

    case 3:
      if(!emptyCollection){
        removeCar(carCollection);
      }
      else{
        cout << "\t> ERROR: The collection is empty" << endl;
      }
      break;

    case 4:
      if(!emptyCollection){
        accelerateCar(carCollection);
      }
      else{
        cout << "\t> ERROR: The collection is empty" << endl;
      }
      break;

    case 5:
      if(!emptyCollection){
        brakeCar(carCollection);
      }
      else{
        cout << "\t> ERROR: The collection is empty" << endl;
      }
      break;

    case 6:
      quit = true;
      break;

    default:
      cout << "ERROR! Invalid Choice!" << endl;
      break;
    }
  }

  cout << endl << "Program ending..." << endl;

  cout << endl;
  cout << "I attest that this code is my original programming work, and that I received" << endl;
  cout << "no help creating it. I attest that I did not copy this code or any portion of this" << endl;
  cout << "code from any source." << endl;

  return 0;
}

//*****************
//Function name: displayMainMenu
//Purpose: displays main menu and returns the user's choice
//List of parameters:
//Returns: choice
//Return type: short
//*****************
short displayMainMenu(){
  short choice;
  cout << "1. Print complete car collection" << endl;
  cout << "2. Add a car to the collection" << endl;
  cout << "3. Remove a car from the collection" << endl;
  cout << "4. Accelerate Car" << endl;
  cout << "5. Brake Car" << endl;
  cout << "6. Quit" << endl;
  cout << "Enter: ";
  cin >> choice;
  return choice;
}

//*****************
//Function name: displayCollection
//Purpose: displays the car collection
//List of parameters: tempCollection
//Returns:
//Return type: void
//*****************
void displayCollection(vector<Car> tempCollection){
  if (!tempCollection.empty()){
    for (int i = 0; i < tempCollection.size(); i++){
    cout << "\t> " << i + 1 << " | ";
    tempCollection.at(i).displayStat();
    }
  }
  else {
    cout << "ERROR: The collection is empty" << endl;
    return;
  }
}

//*****************
//Function name: addCar
//Purpose: add cars to the collection
//List of parameters: &tempCollection
//Returns:
//Return type: void
//*****************
void addCar(vector<Car> &tempCollection){
  string tempMake;
  int tempYear;
  cout << "Adding a car to the collection..." << endl;
  cout << "\t> Enter make: ";
  cin >> tempMake;
  cout << "\t> Enter year: ";
  cin >> tempYear;
  tempCollection.push_back(Car(tempMake, tempYear));
  cout << "\t> Done. Car added." << endl;
}

//*****************
//Function name: removeCar
//Purpose: remove cars from the collection
//List of parameters: &tempCollection
//Returns:
//Return type: void
//*****************
void removeCar(vector<Car> &tempCollection){
  short choice;
  cout << "Removing a car from the collection..." << endl;
  cout << "\t> Enter the number of the car to remove:" << endl;
  displayCollection(tempCollection);
  cout << "\t> Choice: ";
  cin >> choice;
  while (choice > tempCollection.size()){
    cout << "Invalid choice!" << endl;
    cout << "Only enter 1 to " << tempCollection.size() << endl;
    cout << "Enter: ";
    cin >> choice;
  }
  tempCollection.erase(tempCollection.begin() + choice - 1);
  cout << "\t> Done. Car removed." << endl;
}

//*****************
//Function name: accelerateCar
//Purpose: accelerate cars in the collection
//List of parameters: &tempCollection
//Returns:
//Return type: void
//*****************
void accelerateCar(vector<Car> &tempCollection){
  short choice;
  cout << "Accelerating a car..." << endl;
  cout << "\t> Enter the number of the car to accelerate:" << endl;
  displayCollection(tempCollection);
  cout << "\t> Choice: ";
  cin >> choice;
  while (choice > tempCollection.size()){
    cout << "Invalid choice!" << endl;
    cout << "Only enter 1 to " << tempCollection.size() << endl;
    cout << "Enter: ";
    cin >> choice;
  }
  tempCollection.at(choice - 1).accelerate();
  cout << "\t> Done. Car accelerated. New speed " << tempCollection.at(choice - 1).getSpeed() << " mph" << endl;
}

//*****************
//Function name: brakeCar
//Purpose: brake cars in the collection
//List of parameters: &tempCollection
//Returns:
//Return type: void
//*****************
void brakeCar(vector<Car> &tempCollection){
  short choice;
  cout << "Braking a car..." << endl;
  cout << "\t> Enter the number of the car to brake:" << endl;
  displayCollection(tempCollection);
  cout << "\t> Choice: ";
  cin >> choice;
  while (choice > tempCollection.size()){
    cout << "Invalid choice!" << endl;
    cout << "Only enter 1 to " << tempCollection.size() << endl;
    cout << "Enter: ";
    cin >> choice;
  }
  tempCollection.at(choice - 1).brake();
  cout << "\t> Done. Car braked. New speed " << tempCollection.at(choice - 1).getSpeed() << " mph" << endl;
}
