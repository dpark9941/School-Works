//============================================================================
// Name        : lab 8-1 part4.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : reads gas prices from a file and sorts them low to high
//============================================================================

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int SIZE = 52; //the size of the array

//function prototypes
void sortArray(double[], int[]);
void swap(double, int);

int main(){
	ifstream inputFile;
	inputFile.open("gas.txt");
	if(!inputFile){
		cout << "ERROR! The file doesn't exist" << endl;
		cout << "Program ending..." << endl;
		return 0;
	}

	cout << "This program sorts gas prices from low to high" << endl;
	double gas [SIZE]; //holds the gas prices
	int week [SIZE]; //holds the number of weeks
	double number; //holds gas price in the file
	int index = 0; //index number for the array

	//inputs the numbers into the array
	cout << "Reading the prices from the file..." << endl;
	while (inputFile >> number){
		gas[index] = number;
		index++;
	}
	cout << "Done." << endl;
	inputFile.close();

	//assigns 1 - 52 to week array
	for (int i = 0; i < SIZE; i++){
		week[i] = i + 1;
	}

	//sorts the gas array
	sortArray(gas, week);

	//displays results
	cout << setprecision(3) << fixed << showpoint << endl;
	cout << "==============1994 GAS PRICES (sorted low to high)==============" << endl;
	cout << "Week\tPrice" << endl;
	for (int i = 0; i < SIZE; i++){
		cout << week[i] << '\t' << gas[i] << endl;
	}

	return 0;
}

//=======================================================
//Function name: sortArray
//Purpose: sorts arrays
//List of parameters: gas{SIZE]
//Return type: void
//Returns:
//=======================================================
void sortArray(double gas[SIZE], int week[SIZE]){
	for (int maxElement = SIZE - 1; maxElement > 0; maxElement--){
		for (int index = 0; index < maxElement; index++){
			if (gas[index] > gas[index + 1]){
				swap(gas[index], gas[index + 1]);
				swap(week[index], week[index + 1]);
			}
		}
	}
}

//=======================================================
//Function name: swap
//Purpose: swaps the order of elements of array
//List of parameters: two elements of an array
//Return type: void
//Returns:
//=======================================================
void swap(int a, int b){
	int temp = a;
	a = b;
	b = temp;
}
