//============================================================================
// Name        : lab 7-3 part2.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : fills a vector with 100 numbers and prints them out
//============================================================================

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

const int ROWS = 10; //size of the rows of the table
const int COLS = 10; //size of the columns of the table
const int MAX = 100; //max range of rand()
const int MIN = 1; //min range of rand()
const int W1 = 3; //field width for numbers
const int SIZE = 100; //size of the vector

int main(){
	srand(time(0));
	vector <int> vec1(SIZE);
	int counter = 0; //counts the number of random numbers in one row
	cout << "===============Vector Processing Program=============== " << endl;
	cout << "This program fills a vector with random numbers and then prints them out" << endl;

	//fills the vector with random numbers
	cout << "Generating random numbers..." << endl;
	for (int i = 0; i < SIZE; i++)
		vec1[i] = rand() % (MAX - MIN + 1) + MIN;
	cout << "Done." << endl;

	cout << "Here's the table!" << endl << endl;
	for (int val : vec1){
		cout << setw(W1) << val << " ";
		counter++;
		if (counter == 10){
			cout << endl;
			counter = 0;
		}
	}
	return 0;
}
