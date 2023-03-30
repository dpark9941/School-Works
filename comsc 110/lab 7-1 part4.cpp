//============================================================================
// Name        : lab 7-1 part4.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : reads 10 movie titles from a file and outputs them
//============================================================================

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int SIZE = 10; //the size of the array

int main(){

	ifstream inputFile;
	inputFile.open("input.txt");
	if (!inputFile){
		cout << "ERROR! The file doesn't exist!" << endl;
		cout << "Program ending..." << endl;
		return 0;
	}

	string movies[SIZE];

	for (int i = 0; i < SIZE; i++){
		getline(inputFile, movies[i]);
		cout << movies[i] << endl;
	}

	inputFile.close();
	return 0;
}
