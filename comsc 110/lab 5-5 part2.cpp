//============================================================================
// Name        : lab 5-5 part2.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program writes 100 random numbers to a file
//============================================================================

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

const int MAXR = 1000;
const int MINR = 1;

int main(){

	srand(time(0));
	int maxR = MINR - 1;
	int minR = MAXR + 1;

	ofstream outputFile;
	outputFile.open("100RandomNumebrs.txt");

	cout << "Writing 100 random numbers to the file..." << endl;

	for (int i = 1; i <= 100; i++)
	{
		int randNr = rand() % (MAXR - MINR + 1) + MINR;

		outputFile << randNr << endl;
		if (randNr > maxR)
			maxR = randNr;
		if (randNr < minR)
			minR = randNr;
	}

	cout << "Largest: " << maxR << endl;
	cout << "Smallest: " << minR << endl;

	outputFile.close();

	return 0;
}


