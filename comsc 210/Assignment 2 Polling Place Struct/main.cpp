//*****************
//Program Name: Assignment 2: Polling Place Struct
//Author: Your Donggyu Park
//IDE Used: Eclipse
//Program description: Write a program that develops and manipulates data about polling places in struct variables
//*****************

#include "Pollingplace.h"
#include <iostream>
#include <vector>
using namespace std;

const int POLLING_PLACES = 3; //the number of PollingPlace objects that main() will populate

PollingPlace PopulatePollingPlace();
void OutputPollingPlace(PollingPlace);
void plagiarismRequirement();

int main(){
	vector<PollingPlace> pollingPlaceList;

	//creates PollingPlace objects
	for(int i = 0; i < POLLING_PLACES; i++){
		cout << "Polling place #" << i + 1 << endl;
		pollingPlaceList.push_back(PopulatePollingPlace());
		cin.ignore();//to empty the keyboard buffer
		cout << endl;
	}

	//outputs polling places
	for(int i = 0; i < pollingPlaceList.size(); i++){
		cout << "Polling place #" << i + 1 << endl;
		OutputPollingPlace(pollingPlaceList.at(i));
		cout << endl;
	}

	plagiarismRequirement();

	return 0;
}

//*****************
//Function name: PopulatePollingPlace
//Purpose: populates a PollingPlace variable and returns it
//List of parameters:
//Returns: temp
//Return type: PollingPlace
//*****************
PollingPlace PopulatePollingPlace(){
	PollingPlace temp;

	//gets the address of the polling place from the user
	cout << "Enter the address of the polling place: ";
	getline(cin, temp.address);

	//gets the location of the polling place from the user
	cout << "Enter the location of the polling place: ";
	getline(cin, temp.location);

	//gets the number of voting machines from the user
	cout << "Enter the number of the voting machines: ";
	cin >> temp.machines;

	//gets the number of expected voters at that location
	cout << "Enter the number of expected voters at that location: ";
	cin >> temp.voters;

	//returns the struct
	return temp;
}

//*****************
//Function name: OutputPollingPlace
//Purpose: outputs info about a polling place
//List of parameters: PollingPlace temp
//Returns:
//Return type: void
//*****************
void OutputPollingPlace(PollingPlace temp){
	cout << "Address: " << temp.address << endl;
	cout << "Location: " << temp.location << endl;
	cout << "Machines: " << temp.machines << endl;
	cout << "Expected voters: " << temp.voters << endl;

}

//*****************
//Function name: plagiarismRequirement
//Purpose: outputs Plagiarism Requirement
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
