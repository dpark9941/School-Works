//============================================================================
// Name        : lab 3-2 part2.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This is a program that converts Celsius temperature to Fahrenheit temperature
//============================================================================

#include <iostream>
using namespace std;

int main() {

	float celsius, fahrenheit;

	cout << "This program converts Celsius temperature to Fahrenheit temperature." << endl;
	cout << "Enter a Celsius temperature: ";
	cin >> celsius;

	fahrenheit = (9.0/5.0)*celsius+32;

	cout << celsius << " Celsius is " << fahrenheit << " Fahrenheit.";

	return 0;
}
