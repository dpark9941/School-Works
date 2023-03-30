//============================================================================
// Name        : lab 5-3 part1.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program adds 2 numbers until the user ends the program
//============================================================================

#include <iostream>
using namespace std;
int main() {

	double num1, num2, sum;
	char repeat;

	do
	{
		cout << "\nEnter 2 numbers and I'll add them " << endl << endl;
		cout << "Enter the first number: ";
		cin >> num1;
		cout << "Enter the second number: ";
		cin >> num2;
		sum = num1 + num2;
		cout << '\n' << num1 << " + " << num2 << " = " << sum << endl;
		cout << "\nRepeat program? Y/N: ";
		cin >> repeat;
		while (toupper(repeat) != 'Y' && toupper(repeat) != 'N') //input validation
		{
			cout << "ERROR! only enter Y/N: ";
			cin >> repeat;
		}

	} while (toupper(repeat) == 'Y');

	cout << "Program ending...";

	return 0;
}
