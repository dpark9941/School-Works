//============================================================================
// Name        : lab 4-1 part1.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program tells which number is larger or if they're same
//============================================================================

#include <iostream>
using namespace std;

int main() {

	float num1, num2;

	cout << "Enter two different number and I'll tell you which is larger or if they're the same." << endl;

	cout << "Enter first number: ";
	cin >> num1;
	cout << "Enter second number: ";
	cin >> num2;

	if (num1 > num2)
		cout << "The first number (" << num1 << ") is larger than the second number (" << num2 << ")." << endl;

	else if (num1 < num2)
		cout << "The second number (" << num2 << ") is larger than the first number (" << num1 << ")." << endl;
	else
		cout << "These numbers are the same (" << num1 << ")." << endl;

	return 0;
}
