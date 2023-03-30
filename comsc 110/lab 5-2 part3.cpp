//============================================================================
// Name        : lab 5-2 part3.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program calculates the sum of integers from 0 up to and including user's input integer
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

int main() {

	int entry; // user input
	int sum; // the sum of the integers

	cout << "===Summation Program===" << endl << endl;
	cout << "Enter a positive integer to display the sum of" << endl;
	cout << "all positive integers up to and including that integer: ";
	cin >> entry;

	for (int s = 0; s <= entry; s++)
		sum += s;

	cout << "The sum of all positive integers from 0 to " << entry << " is " << sum << endl << endl;
	cout << "Program ending..." << endl;

	return 0;
}
