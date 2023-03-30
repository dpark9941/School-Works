//============================================================================
// Name        : lab 2-1 part2.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This is a program that calculates the sum of three numbers that you enter.
//============================================================================

#include <iostream>
using namespace std;
int main() {

	cout << "This is a program that calculates the sum of three numbers that you enter.\nYou must enter integers." <<endl <<endl;

	int num1, num2, num3, sum;
	cout << "enter the first number: ";
	cin >> num1;
	cout << "enter the second number: ";
	cin >> num2;
	cout << "enter the third number: ";
	cin >> num3;

	sum=num1+num2+num3;

	cout << "the sum of the numbers you entered is : " << sum;

	return 0;
}
