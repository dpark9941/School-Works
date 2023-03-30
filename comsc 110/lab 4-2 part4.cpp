//============================================================================
// Name        : lab 4-2 part4.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program
//============================================================================

#include <iostream>
using namespace std;

int main() {

	float num1, num2, num3;
	int y;

	// part 1
	cout << "===Part One===" << endl;
	cout << "Enter a float greater than 10.0: ";
	cin >> num1;
	cout << (num1 > 10 ? "Good job!" : "Follow directions!") << endl;

	//part 2
	cout << "===Part Two===" << endl;
	cout << "Enter a float between 10.0 - 20.0 (inclusive): ";
	cin >> num2;
	cout << (10 <= num2 && num2 <=20 ? "Good job!" : "Follow directions!") << endl;

	// part 3
	cout << "===Part Three===" << endl;
	cout << "Enter any positive or negative number: ";
	cin >> num3;
	cout << "Y is assigned the value of " << (num3 < 0 ? y = -100 : y = 100) << endl;

	cout << "Program ending..." << endl;

	return 0;
}
