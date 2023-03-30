//============================================================================
// Name        : lab 5-5 part3.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program reads the number of data items in the file
//============================================================================

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

int main(){

	int number;
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
		counter++;

	inputFile.close();

	cout << "There are " << counter << " data items." << endl;

	return 0;
}


