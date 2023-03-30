//============================================================================
// Name        : lab 5-1 extra credit.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This is a program that outputs 1-99 in rows of 15 except for any multiple of 4
//============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const int W1 = 2; // the number of digits

int main() {

	cout.fill('0'); // leading zeros

	for (int i = 1; i <= pow(10,W1); i++)
	{

		if ((i % 20) == 0)
			cout << endl;

		if ((i % 4) == 0)
			continue;

		cout << setw(W1) << i << " ";
	}

	return 0;
}
