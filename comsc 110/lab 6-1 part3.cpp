//============================================================================
// Name        : lab 6-1 part3.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : asks for 3 positive integer and then conducts some calculations
//============================================================================

#include <iostream>
using namespace std;

void someCalculations(int, int, int);

int main(){

	int num1, num2, num3;

	cout << "Enter three positive numbers: ";
	cin >> num1 >> num2 >> num3;
	while (num1 <= 0 || num2 <= 0 || num3 <= 0)
	{
		cout << "ERROR! Enter a positive number: ";
		cin >> num1 >> num2 >> num3;
	}

	someCalculations(num1, num2, num3);
	return 0;
}

void someCalculations(int num1, int num2, int num3){

	int sum;

	cout << "Doubling the numbers..." << endl;
	num1 *= 2;
	num2 *= 2;
	num3 *= 2;

	cout << "Adding the numbers..." << endl;
	sum = num1 + num2 + num3;

	cout << "The sum is " << sum << endl;
}
