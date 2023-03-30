//============================================================================
// Name        : lab 7-2 part3.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : creats a 2D array and fills it with random numbers
//============================================================================

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX = 1000; //max range of rand()
const int MIN = 1; //min range of rand()
const int ROWS = 12; //size of the rows of the array
const int COLS = 12; //size of the columns of the array

int main(){

	srand(time(0));
	int randoms[ROWS][COLS];

	cout << "This program generates 12 x 12 2D array and fills them with random numbers" << endl;
	cout << "Generating random numbers..." << endl;
	for (int r = 0; r < ROWS; r++){
		for (int c = 0; c < COLS; c++)
			randoms[r][c] = rand() % (MAX - MIN + 1) + MIN;
	}

	cout << "Done." << endl << endl;

	return 0;
}

