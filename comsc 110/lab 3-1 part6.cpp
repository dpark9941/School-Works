//============================================================================
// Name        : lab 3-1 part6.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program
//============================================================================


#include <iostream>
#include <iomanip>
using namespace std;

int main() {

	float num1 = 25.42, num2 = 65.44, num3 = 54.23, sum, average;
	string txtAmounts = "Amounts: ", txtSum = "Sum: ", txtAverage = "Average: ";

	sum = num1+num2+num3;
	average = sum/3;

	cout << setprecision(2) << fixed;
	cout << setw(10) << txtAmounts << endl << setw(16) << num1 << endl << setw(16) << num2 << endl << setw(16) << num3 << endl;
	cout << setw(10) << txtSum << setw(6) << sum << endl;
	cout << setw(10) << txtAverage << setw(6) << average;

	return 0;
}
