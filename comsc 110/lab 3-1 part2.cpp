//============================================================================
// Name        : lab 3-1 part2.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program shows the results of multiplications using a field with of 10.
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

int main() {

	float num1 = 6.5, num2 = 5.4, num3 = 7.6;
	float output1, output2;

	output1 = num1*num2;
	output2 = num1*num3;

	cout << setw(10) << output1 << endl;
	cout << setw(10) << output2 << endl;

	return 0;
}
