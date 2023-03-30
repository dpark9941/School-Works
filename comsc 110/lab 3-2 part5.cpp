///============================================================================
// Name        : lab 3-2 part5.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program calculates the sum and the average of four integers
//============================================================================
#include <iostream>
using namespace std;

int main() {

	int num1, num2, num3, num4;
	double sum, avg;

	cout << "Enter four integers, separated by spaces: ";
	cin >> num1 >> num2 >> num3 >> num4;

	sum = num1+num2+num3+num4;
	avg = sum/4;

	cout << "Sum: " << sum << endl;
	cout << "Average: " << avg << endl;

	return 0;
}
