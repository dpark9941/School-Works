//============================================================================
// Name        : lab 3-1 part1.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program outputs a number with various decimal points.
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

int main() {

	double number = 765.4321625;

	cout << number << endl;
	cout << fixed;
	cout << setprecision(2) << number << endl;
	cout << setprecision(4) << number << endl;
	cout << setprecision(5) << number << endl;
	cout << setprecision(6) << number << endl;

	return 0;
}
