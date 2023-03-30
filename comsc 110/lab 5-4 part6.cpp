//============================================================================
// Name        : lab 5-4 part6.cpp
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
	char again; // repeats the whole program

	do
	{
		cout << "============SQUARE GENERATOR============" << endl << endl;
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

		cout << "Repeat the program? Y/N: ";
		cin >> again;
		//input validation
		while (tolower(again) != 'y' && tolower(again) != 'n')
		{
			cout << "ERROR! only Y/N: ";
			cin >> again;
		}

		cout << endl;

	} while (tolower(again) == 'y');

	cout << "Program ending..." << endl;

	return 0;
}
