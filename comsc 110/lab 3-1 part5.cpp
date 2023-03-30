//============================================================================
// Name        : lab 3-1 part5.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program shows numbers in a 2x2 table
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

int main() {


	float num1 = 99.888, num2 = 5.6, num3 = 62.15, num4 = 465.344;

	cout << setprecision(2) << fixed;
	cout << setw(10) << num1 << setw(10) << num2 << endl;
	cout << setw(10) << num3 << setw(10) << num4 << endl;

	return 0;
}
