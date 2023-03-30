//============================================================================
// Name        : lab 8-1 part3.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : finds a certain user input value in the array
//============================================================================

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int SIZE = 1000; //the size of array

//function prototypes
void sortArray(int[SIZE]);
int binarySearch(int[SIZE], int);

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
	int find; //holds the number that the user wants to find
	int result; //indicates if the number has been found

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

	cout << "Enter a number you want to search: ";
	cin >> find;
	cout << "Finding the numbers..." << endl;
	result = binarySearch(randNr, find);
	cout << "Done." << endl;

	//displays results
	cout << "==============RESULTS==============" << endl;
	if (result != -1)
		cout << "The number you were looking for was on " << result + 1 << "th position in the array" << endl;
	else
		cout << "The number you were looking for was not on the array" << endl;

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

//=======================================================
//Function name: binarySearch
//Purpose: search through array to find user input number
//List of parameters: randNr[SIZE], find
//Return type: int
//Returns: position
//=======================================================
int binarySearch(int randNr[SIZE], int find){
	int position = -1, first = 0, last = SIZE - 1, middle;
	bool found = false;

	while (first <= last && !found){
		middle = (first + last)/2;
		if (randNr[middle] == find){
			found = true;
			position = middle;
		}
		else if (randNr[middle] > find)
			last = middle - 1;
		else
			first = middle + 1;
	}
	return position;
}
