//============================================================================
// Name        : lab 3-3 part1.cpp
// Author      : Donggy Park
// IDE used    : Eclipse
// Description : This program conducts a simple calculation
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

const int W1 = 10,
		  W2 = (W1-2);

int main() {

	int num1 = 10, num2 = 20;
	int sum; // sum of num1 and num2

	sum = num1 + num2;

	cout << "Here's a math problem below; press enter to see the answer!" << endl;
	cout << setw(W1) << num1 << endl;
	cout << setw(W2) << "+ " << num2 << endl;
	cout << setw(W1) << "----";
	cin.get();

	cout << setw(W1) << sum << endl;

	return 0;
}
