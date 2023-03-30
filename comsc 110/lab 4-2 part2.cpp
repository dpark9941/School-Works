//============================================================================
// Name        : lab 4-2 part2.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program outputs the name of fruits that starts with that letter
//============================================================================

#include <iostream>
using namespace std;

int main() {

	char choice; //user input

	cout << "Enter choice A-E to display a fruit name that starts with the letter." << endl;
	cout << "Your choice (A-E only): " << choice;
	cin >> choice;


	switch (choice)
	{
		case 'a':
		case 'A':
			cout << "\nApple!" << endl;
			cout << "Program ending..." << endl;
			break;

		case 'b':
		case 'B':
			cout << "\nBlueberry!" << endl;
			cout << "Program ending..." << endl;
			break;

		case 'c':
		case 'C':
			cout << "\nCoconut!" << endl;
			cout << "Program ending..." << endl;
			break;

		case 'd':
		case 'D':
			cout << "\nDurian!" << endl;
			cout << "Program ending..." << endl;
			break;

		case 'e':
		case 'E':
			cout << "\nElderberry!" << endl;
			cout << "Program ending..." << endl;
			break;

		default :
			cout << "Error: Not a valid choice! Please re-run the program" << endl;
	}

	return 0;
}
