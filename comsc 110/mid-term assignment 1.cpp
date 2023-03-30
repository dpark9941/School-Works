//============================================================================
// Name        : mid-term assignment 1.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : mid-term assignment 1
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

int main(){

	int height;
	char charOption;
	char pyramidChar;
	char repeat;

	do
	{
		cout << "*******************PYRAMID PROGRAM*******************" << endl;
		cout << "This program will output a sideways asterisk pyramid of a height of your choosing." << endl;
		cout << "\t> How tall of a pyramid do you want? Enter 5-25 only: ";
		cin >> height;
		while (height < 5 || height > 25)
		{
			cout << "\t> ERROR: 5-25 only. Reenter: ";
			cin >> height;
		}
		cout << "\t> Default character is the asterisk." << endl;
		cout << "\t> Would you like to choose your own character? Y/N: ";
		cin >> charOption;
		while (tolower(charOption) != 'y' && tolower(charOption) != 'n')
		{
			cout << "\t> ERROR! Y/N only: ";
			cin >> charOption;
		}

		if (tolower(charOption) == 'y')
		{
			cout << "\t> Enter the character you want to use: ";
			cin >> pyramidChar;
			while (pyramidChar == '*')
			{
				cout << "ERROR! * is the default character. Enter something else: ";
				cin >> pyramidChar;
			}
		}

		//ascending part
		for (int i = 1; i <= height; i++)
		{
			for (int a = 1; a <= i; a++)
			{
				if (tolower(charOption) == 'y')
					cout << pyramidChar;
				else
					cout << '*';
			}
			cout << endl;
		}

		//descending part
		for (int j = height - 1; j >= 1; j--)
		{
			for (int k = 1; k <= j; k++)
			{
				if (tolower(charOption) == 'y')
					cout << pyramidChar;
				else
					cout << '*';
			}
			cout << endl;
		}
		cout << "\t> Generate another pyramid? Y/N: ";
		cin >> repeat;
		while (tolower(repeat) != 'y' && tolower(repeat) != 'n')
		{
			cout << "\t> ERROR! Y/N only: ";
			cin >> repeat;
		}

	} while (tolower(repeat) == 'y');

	cout << "Program ending... Have a nice day" << endl;

	return 0;
}
