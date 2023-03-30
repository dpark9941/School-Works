//============================================================================
// Name        : lab 5-3 part2.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program adds all the even numbers up to the number that user entered
//============================================================================

#include <iostream>
using namespace std;
int main() {

	int num1, sum;

	cout << "SUMMATION PROGRAM " << endl << endl;
	cout << "Enter a positive integer to display the sum of all even non-negative integers up to and including that integer: ";
	cin >> num1;
	while (num1 < 0) //input validation
	{
		cout << "ERROR! only enter positive number: ";
		cin >> num1;
	}

	for (int i = 0; i <= num1; i++)
	{
		if ((i % 2) != 0)
			continue;
		sum += i;
	}

	cout << "The sum of all even non-negative integers form 0 to " << num1 << " is " << sum << endl;
	cout << "Program ending... Have a nice day!";

	return 0;
}
