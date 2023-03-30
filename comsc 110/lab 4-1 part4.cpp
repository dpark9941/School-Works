//============================================================================
// Name        : lab 4-1 part4.cpp
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

	if (choice == 'A')
		cout << "\nApple!" << endl;

	else if (choice == 'B')
		cout << "\nBlueberry!" << endl;

	else if (choice == 'C')
		cout << "\nCoconut!" << endl;

	else if (choice == 'D')
			cout << "\nDurian!" << endl;

	else if (choice == 'E')
			cout << "\nElderberry!" << endl;

	else
	{
		cout << "Error: Not a valid choice! Please re-run the program" << endl;
		return 0;
	}

	cout << "Program ending..." << endl;

	return 0;
}
