//============================================================================
// Name        : lab 4-1 part5.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program outputs names in alphabetical order
//============================================================================

#include <iostream>
using namespace std;

int main() {

	string name1, name2;

	cout << "Enter two first name and I'll sort them." << endl;
	cout << "Name #1: ";
	cin >> name1;
	cout << "Name #2: ";
	cin >> name2;

	if (name1 < name2)
		cout << "Alphabetized: " << name1 << " " << name2 << endl;

	else if (name1 > name2)
		cout << "Alphabetized: " << name2 << " " << name1 << endl;
	else
		cout << "The names are the same: " << name1 << endl;

	cout << "Program ending..." << endl;

	return 0;
}
