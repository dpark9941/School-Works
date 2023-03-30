//============================================================================
// Name        : lab 5-5 part1.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program reads numbers from a file
//============================================================================

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main(){

	int number;
	int counter = 0;
	int sum = 0;
	double average;

	ifstream inputFile;
	inputFile.open("data.txt");

	cout << "Reading from the file...." << endl;
	cout << "Your numbers are: " << endl;

	while (inputFile >> number)
	{
		counter++;
		cout << number << " ";
		sum += number;
	}
	inputFile.close();

	average = sum / (double) counter;

	cout << setprecision(2) << fixed << showpoint << endl;
	cout << "The average of these numbers are: " << average << endl;

	return 0;
}


