//============================================================================
// Name        : lab 5-5 part5.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program adds lines for display purpose
//============================================================================

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main(){

	string address;
	int counter = 0;

	ifstream inputFile;
	inputFile.open("addresses.txt");
	if (!inputFile)
	{
		cout << "ERROR! There's a problem opening the file: File doesn't exist" << endl;
		cout << "Program ending..." << endl;
		return 0;
	}

	cout << "Reading from the file..." << endl;

	ofstream outputFile;
	outputFile.open("addressesWithBlankLine.txt");

	while (getline(inputFile, address))
	{
		counter++;
		outputFile << address << endl;
		if (counter % 3 == 0)
			outputFile << endl;
	}

	outputFile.close();
	inputFile.close();

	return 0;
}


