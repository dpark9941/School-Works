//============================================================================
// Name        : program 8.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : File Operations With Randoms
//============================================================================

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAXY = 25000; //max range of y
const int MINY = 10000; //min range of y
const int MAXR = 10000; // max range of the random number
const int MINR = 1000; // min range of the random number
const int W1 = 20; // field width for string literals
const int W2 = 15; // field width for numbers

int main(){

	//program description
	cout << "This program will generate a *bunch* of random numbers, write them to" << endl;
	cout << "an external file, read those numbers from that same file, and generate" << endl;
	cout << "and report statistics." << endl << endl;

	//random number generating part
	ofstream outputFile;
	outputFile.open("output.txt");

	cout << "Generating between " << MINY << " and " << MAXY << " random numbers (range: " << MINR << " - " << MAXR << ")..." << endl;
	srand(time(0));
	int y = rand() % (MAXY - MINY + 1) + MINY; //the number of random numbers that's generated
	int randNr;

	for (int r = 1; r <= y; r++)
	{
		randNr = rand() % (MAXR - MINR + 1) + MINR;
		outputFile << randNr << " ";
	}
	outputFile.close();

	cout << "Done." << endl << endl;

	//file reading part
	ifstream inputFile;
	inputFile.open("output.txt");
	if (!inputFile) //file validation
	{
		cout << "ERROR! the file doesn't exist!" << endl;
		cout << "Program ending..." << endl;
		return 0;
	}

	int number; //extracted number from the file
	double counter = 0; //counts the number of random numbers in the file
	int odds = 0, evens = 0; //the number of the odd and even numbers in the file
	double oddsR, evensR; //rates of odd and even numbers
	int largest = MINR - 1; //the largest number found in the file
	int smallest = MAXR + 1; //the smallest number found in the file
	int sum = 0; //the sum of random numbers in the file
	double average; //the average of random numbers

	cout << "Analyzing randoms and compiling statistics..." << endl;
	while (inputFile >> number)
	{
		counter++;
		sum += number;
		if (number % 2 == 0)
			evens++;
		if (number % 2 == 1)
			odds++;
		if (number > largest)
			largest = number;
		if (number < smallest)
			smallest = number;
	}
	inputFile.close();

	average = sum / counter;
	oddsR = odds / counter;
	evensR = evens / counter;

	cout << "Done." << endl << endl;

	//result output
	cout << setprecision(2) << fixed << showpoint;
	cout << setw(W1) << "Number of randoms: " << setw(W2) << (int)counter << endl;
	cout << setw(W1) << "Sum: " << setw(W2) << sum << endl;
	cout << setw(W1) << "Average: " << setw(W2) << average << endl;
	cout << setw(W1) << "Odds: " << setw(W2) << odds << endl;
	cout << setw(W1) << "Evens: " << setw(W2) << evens << endl;
	cout << setw(W1) << "Odds percentage: " << setw(W2) << oddsR * 100 << "%" << endl;
	cout << setw(W1) << "Even percentage: " << setw(W2) << evensR * 100 << "%" << endl;
	cout << setw(W1) << "Highest: " << setw(W2) << largest << endl;
	cout << setw(W1) << "Lowest: " << setw(W2) << smallest << endl;



	return 0;
}
