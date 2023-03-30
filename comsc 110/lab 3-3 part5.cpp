//============================================================================
// Name        : lab 3-3 part5.cpp
// Author      : Donggy Park
// IDE used    : Eclipse
// Description : This program outputs a sentence if the input is greater than 10
//============================================================================

#include <iostream>
using namespace std;

int main() {

	int number;

	cout << "Enter an integer: ";
	cin >> number;

	if (number > 10)
		cout << "That's greater than 10!" << endl;

	cout <<"Program ending" << endl;

	return 0;
}
