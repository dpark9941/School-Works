//============================================================================
// Name        : lab 3-3 part2.cpp
// Author      : Donggy Park
// IDE used    : Eclipse
// Description : This program outputs the sum of random numbers
//============================================================================

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

const int W1 = 10,
		  W2 = (W1-2);
const int MAXR = 99, // maximum random number
		  MINR = 10; // minimum random number

int main() {

	srand (time(0));

	int num1 = (rand() % (MAXR - MINR + 1)) + MINR,
		num2 = (rand() % (MAXR - MINR + 1)) + MINR;
	int sum; // sum of num1 and num2

	sum = num1 + num2;

	cout << "Here's a math problem below; press enter to see the answer!" << endl;
	cout << setw(W1) << num1 << endl;
	cout << setw(W2) << "+ " << num2 << endl;
	cout << setw(W1) << "----";
	cin.get();

	cout << setw(W1) << sum << endl;


	return 0;
}
