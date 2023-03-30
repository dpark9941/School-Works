//============================================================================
// Name        : lab 3-2 part4.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program outputs a character the user entered, as well as the ASCII value of the character
//============================================================================

#include <iostream>
using namespace std;

int main() {

	char char1;

	cout << "Enter a character: ";
	cin >> char1;

	cout << "You entered: " << char1 << endl;
	cout << "ASCII value: " << (int) char1;

	return 0;
}
