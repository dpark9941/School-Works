//============================================================================
// Name        : lab 4-2 part3.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program calculates leap year
//============================================================================

#include <iostream>
using namespace std;

int main() {

	int year; // user input

	cout << "***LEAP YEAR CALCULATOR***" << endl;
	cout << "Enter a year to determine if it's a leap year: ";
	cin >> year;

	if ((year % 4) == 0)
	{
		if ((year % 100) == 0)
		{
			if ((year % 400) == 0)
			{
				cout << year << " is a leap year" << endl;
			} // if ((year % 400) == 0)
			else
				cout << year << " is not a leap year" << endl;
		} // if ((year % 100) == 0)
		else
			cout << year << " is a leap year" << endl;
	} // if ((year % 4) == 0)
	else
		cout << year << " is not a leap year" << endl;

	cout << "Program ending..." << endl;

	return 0;
}
