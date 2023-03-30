//============================================================================
// Name        : lab 7-4 part2.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : creates random numbers and writes them to a file
//============================================================================

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int YMAX = 1500; //max range of y
const int YMIN = 500; //min range of y
const int MAX = 9999; //max range of rand()
const int MIN = 1000; //min range of rand()

int main(){

	cout << "This program will generates random numbers and writes them to a file" << endl;
	ofstream outputFile;
	outputFile.open("numbers.txt");
	srand(time(0));
	int randNr;

	cout << "Generating random numbers..." << endl;
	int y = rand() % (YMAX - YMIN + 1) + YMIN;
	//generates randoms and writes them to the file
	for (int i = 1; i < y; i++){
		randNr = rand() % (MAX - MIN + 1) + MIN;
		outputFile << randNr << " ";
	}
	cout << "Done." << endl;
	outputFile.close();
	return 0;
}
