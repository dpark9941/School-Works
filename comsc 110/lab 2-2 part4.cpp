//============================================================================
// Name        : lab 2-2 part4.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program shows the user what they entered
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {

	int number;
	float realNumber;
	char character;
	string words;

	cout << "enter a whole number: ";
	cin >> number;
	cout << "enter a real number: ";
	cin >> realNumber;
	cout << "enter a character: ";
	cin >> character;
	cout << "enter words or sentences: ";
	cin.ignore();
	getline (cin, words);

	cout << endl << "You entered : " << endl;
	cout << number << endl;
	cout << realNumber << endl;
	cout << character << endl;
	cout << words;

	return 0;

}
