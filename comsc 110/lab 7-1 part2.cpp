//============================================================================
// Name        : lab 7-1 part2.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : outputs the sum of the numbers entered using array
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 10; //the size of the array

int main(){

	float sum = 0;
	float numbers[SIZE];
	for (int i = 0; i < SIZE; i++){
		cout << "Enter number " << i+1 << ": ";
		cin >> numbers[i];
		sum += numbers[i];
	}

	cout << setprecision(2) << fixed << showpoint << endl;
	cout << "The total of the numbers entered is " << sum << endl;

	return 0;
}
