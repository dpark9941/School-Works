//============================================================================
// Name        : lab 5-4 part5.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program displays a square with a certain length
//============================================================================

#include <iostream>
using namespace std;

int main() {

	int length; // length of square
	int i; // row #
	int j; // the number of X
	int repeat; // repeats to display the square

	cout << "======SQUARE GENERATOR======" << endl << endl;
	cout << "Input the length of your square (1 - 25): ";
	cin >> length;
	//input validation
	while (length < 1 || length > 25)
	{
		cout << "ERROR! Only enter 1 - 25: ";
		cin >> length;
	}

	cout << endl;

	for (repeat = 1; repeat <= length; repeat++)
	{
		for (i = 1; i <= length; i++)
		{
			for (j = 1; j <= length; j++)
				cout << "X";
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}
