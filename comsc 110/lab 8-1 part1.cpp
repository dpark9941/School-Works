//============================================================================
// Name        : lab 8-1 part1.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : generates 1000 random numbers and writes them to a file
//============================================================================

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int MAX = 30000;
const int MIN = 1;
const int SIZE = 1000; //the number of random numbers generated
/*Eclipse had an error generating 10000 random numbers so I replaced it with 1000*/

int main(){
	srand(time(0));
	ofstream outputFile;
	outputFile.open("random numbers.txt");
	int number;

	cout << "This program generates random numbers and writes them to a file" << endl;
	cout << "Generating and writing the numbers..." << endl;
	for (int i = 0; i < SIZE; i++){
		number = rand() % (MAX - MIN + 1) + MIN;
		outputFile << number << " ";
	}
	cout << "Done." << endl;
	outputFile.close();

	return 0;
}
