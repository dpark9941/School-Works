//============================================================================
// Name        : Program 13.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : manages a car collection
//============================================================================

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

const int ACCELERATE = 5; // acceleration rate
const int DECELERATE = -5; //deceleration rate

struct Car{
	string make; //the manufacturer of the car
	string model;
	int year;
	double mileage;
	int speed;
};

int isEmpty();
int displayMenu();
void outputCar(vector<Car>);
void addCar(vector<Car>&);
void removeCar(vector<Car>&);
void accelerateCar(vector<Car>&);
void decelerateCar(vector<Car>&);

int main(){
	vector<Car> collection;
	//pre-population
	Car c1 = {"VW", "GTI", 2015, 105000, 0};
	collection.push_back(c1);
	Car c2 = {"Dodge", "Durango", 2011, 1050, 0};
	collection.push_back(c2);
	Car c3 = {"Toyota", "Rav4", 1999, 12000, 0};
	collection.push_back(c3);
	int select;
	do{
		if (collection.size() == 0)
			select = isEmpty();
		else
			select = displayMenu();

		if (select == 1)
			outputCar(collection);
		if (select == 2)
			addCar(collection);
		if (select == 3)
			removeCar(collection);
		if (select == 4)
			accelerateCar(collection);
		if (select == 5)
			decelerateCar(collection);
	} while (select != 6);

	cout << "Program ending... Have a nice day" << endl;

	return 0;
}

//=======================================================
//Function name: isEmpty
//Purpose: shows directions when collection is empty
//List of parameters:
//Return type: int
//Returns: select
//=======================================================
int isEmpty(){
	int select;
		cout << "WARNING! The collection is empty. You can quit or add a car to continue." << endl;
		cout << "Select: " << endl;
		cout << "\t[1] Add a car to the collection" << endl;
		cout << "\t[2] Quit" << endl;
		cout << "\t> ";
		cin >> select;
		while (select < 1 || select > 2){
			cout << "ERROR! Only 1 - 2: ";
			cin >> select;
		}
		if (select == 1)
			select = 2; //if (select == 2) addCar(collection);
		else if (select == 2)
			select = 6; //while (select != 6);

	return select;
}
//=======================================================
//Function name: displayMenu
//Purpose: displays instructions
//List of parameters:
//Return type: int
//Returns: select
//=======================================================
int displayMenu(){
	int select;
	cout << "Select:" << endl;
	cout << "\t[1] Output car collection status" << endl;
	cout << "\t[2] Add a car to the collection" << endl;
	cout << "\t[3] Remove a car from the collection" << endl;
	cout << "\t[4] Accelerate a car" << endl;
	cout << "\t[5] Decelerate a car" << endl;
	cout << "\t[6] Quit" << endl;
	cout << "\t> ";
	cin >> select;
	while (select < 1 || select > 6){
		cout << "ERROR! Only 1 - 6: ";
		cin >> select;
	}
	return select;
}

//=======================================================
//Function name: outputCar
//Purpose: displays informations about cars in the collection
//List of parameters: vector<Car> collection
//Return type: void
//Returns:
//=======================================================
void outputCar(vector<Car> collection){
	cout << "\t> Car collection status:" << endl;
	for (int i = 0; i < collection.size(); i++){
		cout << "=====================================" << endl;
		cout << "\t> " << collection[i].year << ' ' << collection[i].make << ' ' << collection[i].model << endl;
		cout << "\t> Mileage: " << collection[i].mileage << endl;
		cout << "\t> Speed: " << collection[i].speed << endl;
	}
}

//=======================================================
//Function name: addCar
//Purpose: allows user to add a car to the collection
//List of parameters: vector<Car> &collection
//Return type: void
//Returns:
//=======================================================
void addCar(vector<Car> &collection){
	Car temp;
	cout << "\t> Adding a car to collection. Enter:" << endl;
	cout << "\t> Manufacturer: ";
	cin.ignore();
	getline(cin, temp.make);
	cout << "\t> Model: ";
	getline(cin, temp.model);
	//cin.ignore();
	cout << "\t> Year of Manufacture: ";
	cin >> temp.year;
	cout << "\t> Mileage: ";
	cin >> temp.mileage;
	temp.speed = 0;
	collection.push_back(temp);
}

//=======================================================
//Function name: removeCar
//Purpose: allows user to remove a car from the collection
//List of parameters: vector<Car> &collection
//Return type: void
//Returns:
//=======================================================
void removeCar(vector<Car> &collection){
	int remove;
	cout << "\t> Removing a car from collection. Select:" << endl;
	for (int i = 0; i < collection.size(); i++){
		cout << "\t> [" << i+1 << "] " << collection[i].year << ' ' << collection[i].make << ' ' << collection[i].model << endl;
	}
	cout << "\t> ";
	cin >> remove;
	while (remove < 1 || remove > collection.size()){
		cout << "\t> ERROR! Only 1 - " << collection.size() << ": ";
		cin >> remove;
	}
	collection.erase(collection.begin()+remove-1);
	cout << "\t> Car removed." << endl;
}

//=======================================================
//Function name: accelerateCar
//Purpose: allows user to accelerate a car
//List of parameters: vector<Car> &collection
//Return type: void
//Returns:
//=======================================================
void accelerateCar(vector<Car> &collection){
	int accelerate;
	cout << "\t> Accelerating a car. Select:" << endl;
	for (int i = 0; i < collection.size(); i++){
		cout << "\t>[" << i+1 << "] " << collection[i].year << ' ' << collection[i].make << ' ' << collection[i].model << endl;
	}
	cout << "\t> ";
	cin >> accelerate;
	while (accelerate < 1 || accelerate > collection.size()){
		cout << "\t> ERROR! Only 1 - " << collection.size() << ": ";
		cin >> accelerate;
	}
	collection[accelerate-1].speed += ACCELERATE;
	cout << "\t> New speed: " << collection[accelerate-1].speed << endl;
}

//=======================================================
//Function name: decelerateCar
//Purpose: allows user to decelerate a car
//List of parameters: vector<Car> &collection
//Return type: void
//Returns:
//=======================================================
void decelerateCar(vector<Car> &collection){
	int decelerate;
	cout << "\t> Decelerating a car. Select:" << endl;
	for (int i = 0; i < collection.size(); i++){
		cout << "\t>[" << i+1 << "] " << collection[i].year << ' ' << collection[i].make << ' ' << collection[i].model << endl;
	}
	cout << "\t> ";
	cin >> decelerate;
	while (decelerate < 1 || decelerate > collection.size()){
		cout << "ERROR! Only 1 - " << collection.size() << ": ";
		cin >> decelerate;
	}
	if (collection[decelerate-1].speed == 0)
		cout << "\t> The speed is already 0. It can't be decelerated." << endl;
	else{
		collection[decelerate-1].speed += DECELERATE;
		cout << "\t> New speed: " << collection[decelerate-1].speed << endl;
	}

}

