//============================================================================
// Name        : lab 8-1 part2.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : reads random number into an array and sorts them
//============================================================================

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int W1 = 5; //number field width
const int W2 = 17; //string field width
const int SIZE = 1000; //the size of array

//function prototypes
void sortArray(int[SIZE]);

int main(){
	ifstream inputFile;
	inputFile.open("random numbers.txt");
	if(!inputFile){
		cout << "ERROR! The file doesn't exist" << endl;
		cout << "Program ending..." << endl;
		return 0;
	}

	cout << "This program sorts random numbers from a file" << endl;
	int randNr[SIZE];
	int number; //hold a random number in the file
	int index = 0; //index number for the array

	//inputs the numbers into the array
	cout << "Reading the numbers from the file..." << endl;
	while (inputFile >> number){
		randNr[index] = number;
		index++;
	}
	cout << "Done." << endl;
	inputFile.close();

	cout << "Sorting the numbers..." << endl;
	sortArray(randNr);
	cout << "Done." << endl;

	//displays results
	cout << "==============RESULTS==============" << endl;
	cout << setw(W2) << "Highest number: " << setw(W1) << randNr[SIZE - 1] << endl;
	cout << setw(W2) << "Lowest number: " << setw(W1) << randNr[0] << endl;
	cout << setw(W2) << "Middle number: " << setw(W1) << randNr[SIZE/2] << endl;
	return 0;
}

//=======================================================
//Function name: sortArray
//Purpose: swaps the elements of array til it is sorted
//List of parameters: randNr{SIZE]
//Return type: void
//Returns:
//=======================================================
void sortArray(int randNr[SIZE]){
	bool swap;
	int temp;

	do{
		swap = false;
		for (int count = 0; count < SIZE - 1; count++){
			if (randNr[count] > randNr[count + 1]){
				temp = randNr[count];
				randNr[count] = randNr[count + 1];
				randNr[count + 1] = temp;
				swap = true;
			}
		}
	} while(swap);
}
