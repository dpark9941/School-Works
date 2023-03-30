//============================================================================
// Name        : lab 7-1 part3.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : outputs, subtotals and counts odd random numbers
//============================================================================

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 25; //the size of the array
const int MAX = 100; //max range of the random number
const int MIN = 1; //min range of the random number

int main(){

	srand(time(0));
	int randNr[SIZE];
	int sum = 0; //sum of the odd numbers generated
	int counter = 0; //counts the number of odd numbers
	int i = 0;

	for (i = 0; i < SIZE; i++)
		randNr[i] = rand() % (MAX - MIN + 1) + MIN;

	for (i = 0; i < SIZE; i++){
		if (randNr[i] % 2 == 1){
			sum += randNr[i];
			cout << randNr[i] << endl;
			counter++;
		}
	}

	cout << setprecision(2) << fixed << showpoint << endl;
	cout << counter << " odd number(s) have been created" << endl;
	cout << "The total of the odd numbers is " << sum << endl;

	return 0;
}
