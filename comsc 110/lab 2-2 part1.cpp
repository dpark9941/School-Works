//============================================================================
// Name        : lab 2-2 part1.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program outputs the sume of 5 integers.
//============================================================================

#include <iostream>
using namespace std;

int main() {

	int num1 = 5, num2 = 10, num3 = 15, num4 = 20, num5 = 25;
	int sum;
	const int CONST = 100;

	num1 += CONST, num2 += CONST, num3 += CONST, num4 += CONST, num5 += CONST;
	sum = num1+num2+num3+num4+num5;

	cout << sum;

	return 0;
}
