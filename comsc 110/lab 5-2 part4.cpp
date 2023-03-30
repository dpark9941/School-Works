//============================================================================
// Name        : lab 5-2 part4.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program generates random numbers and displays the biggest and the smallest
//============================================================================

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAXR = 1000000;
const int MINR = 1;

int main() {


	int entry; // user input of random number's range
	int maxRandom = MINR - 1; // the biggest random number generated
	int minRandom = MAXR + 1; // the smallest random number generated
	int randNum; // a generated random number

	srand(time(0)); // seed value for rand()

	cout << "***RANDOM NUMBER GENERATOR***" << endl << endl;
	cout << "How many random numbers do you want to generate (50-50,000): ";
	cin >> entry;

	// input validation
	while (entry > 50000 || entry < 50)
	{
		cout << "\nERROR! Only enter from 50 to 50000: ";
		cin >> entry;
	}

	// random number generator
	for (int r = 1; r <= entry; r++)
	{
		randNum = (rand() % (MAXR - MINR + 1)) + MINR;
		if (randNum > maxRandom)
			maxRandom = randNum;
		if (randNum < minRandom)
			minRandom = randNum;
	}

	cout << "\n\t> Results complete." << endl;
	cout << "\t> " << entry << " random numbers generated in range in 1-1000000" << endl;
	cout << "\t> Maximum: " << maxRandom << endl;
	cout << "\t> Minimum: " << minRandom << endl;

	return 0;
}
