//============================================================================
// Name        : lab 5-2 part1.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program conducts a simple input validation
//============================================================================

#include <iostream>
using namespace std;

int main() {

	int input; // user input

	cout << "Enter the number 10: ";
	cin >> input;

	while (input != 10)
	{
		cout << "ERROR: only enter 10: ";
		cin >> input;
	}

	if (input == 10)
		cout << "Thank you!" << endl;

	return 0;
}
