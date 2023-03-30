//*****************
//Program Name: Assignment 5: Array of Movie Objects
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: Write a program that demonstrates Movie class
//*****************

#include "Movie.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int ARR_SIZE = 4;

void readFile(Movie *);
void outputArray(Movie *);
void plagiarismRequirement();

int main(){
	Movie *movieList = new Movie[ARR_SIZE];

	cout << "Reading file..." << endl;
	readFile(movieList);
	cout << "Done." << endl;

	cout << endl;

	cout << "Outputting the array:" << endl;
	outputArray(movieList);

	delete [] movieList;

	plagiarismRequirement();

	return 0;
}

//*****************
//Function name: readFile
//Purpose: reads input file into an array
//List of parameters: Movie *tempMovie
//Returns:
//Return type: void
//*****************
void readFile(Movie *movies){
	ifstream fin;
	fin.open("input.txt");

	//if there is an error with opening the input file
	if(!fin.good()){
		cout << "The file is not open! Program ending..." << endl;
		exit(0);
	}

	string sw;
	int yr;
	string t;
	int index = 0;
	while(!fin.eof()){
		getline(fin, sw);
		fin >> yr;
		fin.ignore();
		getline(fin, t);

		(movies + index)->setScreenWriter(sw);
		(movies + index)->setYearReleased(yr);
		(movies + index)->setTitle(t);

		index++;
	}
}

//*****************
//Function name: outputArray
//Purpose: outputs the contents of the array
//List of parameters: Movie *tempMovie
//Returns:
//Return type: void
//*****************
void outputArray(Movie *movies){
	for(int i = 0; i < ARR_SIZE; i++){
		cout << endl;
		cout << "Movie: " << (movies + i)->getTitle() << endl;
		cout << "\tYear released: " << (movies + i)->getYearReleased() << endl;
		cout << "\tScreen writer: " << (movies + i)->getScreenWriter() << endl;
	}
}

//*****************
//Function name: plagiarismRequirement
//Purpose: outputs Plagiarism Requirement
//List of parameters:
//Returns:
//Return type: void
//*****************
void plagiarismRequirement(){
  cout << endl;
  cout << "I attest that this code is my original programming work, and that I received" << endl;
  cout << "no help creating it. I attest that I did not copy this code or any portion of this" << endl;
  cout << "code from any source." << endl;
}
