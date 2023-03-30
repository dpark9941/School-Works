//============================================================================
// Lab Name    : Lab: Functions.cpp
// Author      : Donggyu Park
// Date        : 03/05/2020
// Programming Environment : Win 10, Eclipse
//============================================================================

#include <iostream>
#include "Lab 3 Functions.hpp"
using namespace std;

int main() {
	int input1, input2, input3;

	cout << "Enter 3 numbers and I will find the minimum and maximum number." << endl;
	cout << "Enter 3 numbers separated by space: ";
	cin >> input1 >> input2 >> input3;

	cout << "The minimum is " << Minimum(input1, input2, input3) << endl;
	cout << "The maximum is " << Maximum(input1, input2, input3) << endl;

	return 0;
}
