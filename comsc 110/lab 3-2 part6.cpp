//============================================================================
// Name        : lab 3-2 part6.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program calculates various algebraic expressions
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

int main() {

	float a = 6.0, b = 4.0, c = 7.0, d = 5.0;

	cout << (a+d)/(a*b) << endl;
	cout << (a+b)*(d/c) << endl;
	cout << (c-d)*pow(b,d) << endl;
	cout << (c-d)*pow(b,c-b);

	return 0;
}
