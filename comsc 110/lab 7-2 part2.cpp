//============================================================================
// Name        : lab 7-2 part2.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : generates 100 random numbers and copies the number to another array
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
	int randoms1[SIZE]; //populated array
	int randoms2[SIZE]; //unpopulated array

	cout << "This program generates 100 random numbers and copies them to an unpopulated array" << endl;
	cout << "Generating and copying random numbers..." << endl;
	for (int i = 0; i < SIZE; i++){
		randoms1[i] = rand() % (MAX - MIN + 1) + MIN;
		randoms2[i] = randoms1[i];
	}

	cout << "Done." << endl << endl;
	for (int i = 0; i < SIZE; i++){
		cout << randoms2[i] << " ";
	}

	return 0;
}

