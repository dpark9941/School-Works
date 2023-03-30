//============================================================================
// Name        : lab 5-5 part4.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program reads the number of data items in the file
//============================================================================

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main(){

	double number;
	double sum = 0;
	double average = 0;
	double largest = -1000000000 + 1; // the largest number in the file
	double smallest = 1000000000 - 1; // the smallest number in the file
	int counter = 0; // counts the number of elements in the file

	ifstream inputFile;
	inputFile.open("randoms.txt");
	if (!inputFile)
	{
		cout << "ERROR! There's a problem opening the file: File doesn't exist" << endl;
		cout << "Program ending..." << endl;
		return 0;
	}

	cout << "Reading from the file..." << endl;

	while (inputFile >> number)
	{
		counter++;

		if (number > largest)
			largest = number;
		if (number < smallest)
			smallest = number;

		sum += number;
	}

	inputFile.close();

	average = sum / counter;

	cout << setprecision(2) << fixed << showpoint << endl;
	cout << "Number of items: " << counter << endl;
	cout << "Total: " << sum << endl;
	cout << "Average: " << average << endl;
	cout << "Largest: " << largest << endl;
	cout << "Smallest: " << smallest << endl;

	return 0;
}


