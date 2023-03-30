//============================================================================
// Name        : lab 7-2 part1.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : generates 100 random numbers and outputs sum, highest and lowest
//============================================================================

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX = 1000; //max range of rand()
const int MIN = 1; //min range of rand()
const int SIZE = 100; //size of the array

int main(){

	srand(time(0));
	int randoms[SIZE];
	int sum = 0;
	int highest = MIN - 1;
	int lowest = MAX + 1;

	cout << "This program generates 100 random numbers and outputs the sum, the highest and the lowest" << endl;
	cout << "Generating random numbers..." << endl;
	for (int num : randoms){
		num = rand() % (MAX - MIN + 1) + MIN;
		sum += num;
		if (num > highest)
			highest = num;
		if (num < lowest)
			lowest = num;
	}
	cout << "Done." << endl << endl;

	cout << "The sum: " << sum << endl;
	cout << "The highest: " << highest << endl;
	cout << "The lowest: " << lowest << endl;

	return 0;
}

