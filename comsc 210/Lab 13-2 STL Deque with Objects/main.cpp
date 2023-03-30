//*****************
//Program Name: Lab 13-2: STL::Deque with Objects
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: Write a program that will simulate a line of cars lined up to pay their toll at a tollbooth
//*****************

#include <iostream>
#include <string>
#include <deque>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Car.h"
using namespace std;

const int SIZE = 3; //the initial size of the deque

void addCar(deque<Car> &, vector<string>);
void displayAddStatus(deque<Car>, int);
void payCar(deque<Car> &);
void displayPayStatus(deque<Car>, int);
void displayDeque(deque<Car>);
void displayDeque(deque<Car>, int);
void plagiarismRequirement();

int main(){
	srand(time(0));

	//initializes a deque with size 3
	deque<Car> lane1;
	Car initialCar1("GMC", 1999, 1405);
	Car initialCar2("Mercury", 2004, 5592);
	Car initialCar3("Peugeot", 2019, 4938);
	lane1.push_back(initialCar1);
	lane1.push_back(initialCar2);
	lane1.push_back(initialCar3);

	//reads car's make from the file into the array
	ifstream fin("makes.txt");
	vector<string> carMakes;
	string tempMake;
	while(fin >> tempMake)
		carMakes.push_back(tempMake);
	fin.close();

	//allows the user choose how to display the cars
	int choice;
	cout << "Enter:" << endl;
	cout << "[1] Depict lanes by make/year" << endl;
	cout << "[2] Depict lanes by transponder" << endl;
	cout << "Choice: ";
	cin >> choice;

	cout << "Initial lane setup:" << endl;
	displayDeque(lane1, choice);

	//performs add/pay operations
	int operation = 0;
	int roundCount = 0;
	while(!lane1.empty()){
		roundCount++;
		cout << "Operations this round #" << roundCount << ':' << endl;
		operation = rand() % 2;
		switch(operation){
		case 0:
			addCar(lane1, carMakes);
			displayAddStatus(lane1, choice);
			displayDeque(lane1, choice);
			break;
		case 1:
			displayPayStatus(lane1, choice);
			payCar(lane1);
			cout << endl << "Lane 1: ";
			displayDeque(lane1, choice);
			break;
		}
	}

	plagiarismRequirement();

	return 0;
}

//generates a random car object and adds the object to the deque
void addCar(deque<Car> &tempDeque, vector<string> carMakes){
	Car tempCar;
	//randomly chooses car's make
	int index = rand() % (carMakes.size());
	string tempMake = carMakes.at(index);
	//randomly creates car's year
	int tempYear = rand() % (2021 - 1990 + 1) + 1990;
	//randomly creates car's transponder
	int tempTransponder = rand() % (9999 - 1000 + 1) + 1000;

	//assigns the data into the car object
	tempCar.setMake(tempMake);
	tempCar.setYear(tempYear);
	tempCar.setTransponder(tempTransponder);

	//inserts the object into the deque
	tempDeque.push_back(tempCar);
}

//displays which car is added to the queue
void displayAddStatus(deque<Car> tempLane,int choice){
	if(choice == 1)
		cout << "\t> Lane 1: " << tempLane.back().getMake() << "/" << tempLane.back().getYear() << " added to the queue" << endl;
	else if(choice == 2)
		cout << "\t> Lane 1: " << tempLane.back().getTransponder() << " added to the queue" << endl;
}

//performs paying operations on the deque; deletes the first element of the deque
void payCar(deque<Car> &tempDeque){
	tempDeque.pop_front();
}

//displays which car is going through toll gate
void displayPayStatus(deque<Car> tempLane, int choice){
	if(choice == 1)
		cout << "\t> Lane 1: " << tempLane.front().getMake() << "/" << tempLane.front().getYear() << " going through toll gate" << endl;
	else if(choice == 2)
		cout << "\t> Lane 1: " << tempLane.front().getTransponder() << " going through toll gate" << endl;
}

//displays the contents of the deque
void displayDeque(deque<Car> tempDeque){
	for(Car val : tempDeque)
		cout << val.getMake() << '/' << val.getYear() << ' ';
	if(tempDeque.empty()) cout << "<*empty*>";
	cout << endl << endl;
}

//overloaded displayDeque; displays the contents of the deque
void displayDeque(deque<Car> tempDeque, int choice){
	if(choice == 1)
		displayDeque(tempDeque);
	else if(choice == 2){
		for(Car val : tempDeque)
			cout << val.getTransponder() << ' ';
		if(tempDeque.empty()) cout << "<*empty*>";
	cout << endl << endl;
	}
}

//*****************
//Function name: plagiarismRequirement
//Purpose: outputs plagiarism Requirement
//List of parameters:
//Returns:
//Return type: void
//*****************
void plagiarismRequirement(){
  cout << endl;
  cout << "I attest that this code is my original programming work, and that I received" << endl;
  cout << "no help creating it. I attest that I did not copy this code or any portion of this" << endl;
  cout << "code from any source." << endl;
}
