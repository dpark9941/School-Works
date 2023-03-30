//============================================================================
// Name        : lab 3-3 part3.cpp
// Author      : Donggy Park
// IDE used    : Eclipse
// Description : This program shows 10 random numbers within a range
//============================================================================

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {

	int maxR, minR; // user input of max and min random number

	cout << "Enter your min and max, and I'll output ten random numbers" << endl;
	cout << "that fall within those ranges." << endl << endl;
	cout << "Enter minimum random number: ";
	cin >> minR;
	cout << "Enter maximum random number: ";
	cin >> maxR;

	const int MAXR = maxR,
			  MINR = minR;

	srand(time(0)); // seed value for rand()

	cout << "Ten random numbers between " << minR << " and " << maxR << " inclusive:" << endl;

	cout << (rand() % (MAXR - MINR + 1)) + MINR << endl;
	cout << (rand() % (MAXR - MINR + 1)) + MINR << endl;
	cout << (rand() % (MAXR - MINR + 1)) + MINR << endl;
	cout << (rand() % (MAXR - MINR + 1)) + MINR << endl;
	cout << (rand() % (MAXR - MINR + 1)) + MINR << endl;
	cout << (rand() % (MAXR - MINR + 1)) + MINR << endl;
	cout << (rand() % (MAXR - MINR + 1)) + MINR << endl;
	cout << (rand() % (MAXR - MINR + 1)) + MINR << endl;
	cout << (rand() % (MAXR - MINR + 1)) + MINR << endl;
	cout << (rand() % (MAXR - MINR + 1)) + MINR << endl;

	return 0;
}
