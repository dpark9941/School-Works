//============================================================================
// Name        : lab 2-1 part4.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This is a program that calculates fuel economy.
//============================================================================

#include <iostream>
using namespace std;

int main() {

	float mile, gallon, mpg;

	cout << "enter the distance you drove: ";
	cin >> mile;

	cout << "enter the amount of fuel you used: ";
	cin >> gallon;

	mpg=mile/gallon;

	cout << "the fuel economy is : " << mpg << " miles per gallon";

	return 0;
}
