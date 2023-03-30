//============================================================================
// Name        : program4.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program is a color mixer
//============================================================================

#include <iostream>
using namespace std;

int main() {

	int num1, num2; // the colors that's being mixed

	cout << "========= Color Mixer ==========" << endl << endl;
	cout << "Pick two of the three colors below and this program will output what color is produced when mixed:" << endl;
	cout << "Enter 1 for red, 2 for blue, 3 for yellow." << endl;
	cout << "Enter your two choices separated by a space: ";
	cin >> num1 >> num2;

	if (num1 == num2)
		cout <<"You entered the same choice. Please re-run the program" << endl;
	else
	{
		if (num1 * num2 == 2)
			cout << "\nRed and Blue make Purple." << endl;
		if (num1 * num2 == 3)
			cout << "\nRed and Yellow make Orange." << endl;
		if (num1 * num2 == 6)
			cout << "\nBlue and Yellow make Green." << endl;
		else
			cout << "Please choose between 1-3" << endl;
	}

	return 0;
}


