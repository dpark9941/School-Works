//============================================================================
// Name        : lab 6-2 part1.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : generates random numbers and determines if the number is even
//============================================================================

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAXR = 10000; //max range of random numbers
const int MINR = 1; //min range of random numbers

void welcome();
bool isEven(int);

int main(){

	srand(time(0));
	int counter = 0; //counts the number of even numbers
	int randNr;

	welcome();
	cout << "Generating numbers..." << endl;

	for (int i = 1; i <= 100; i++)
	{
		randNr = rand() % (MAXR - MINR + 1) + MINR;
		isEven(randNr);
		if (isEven(randNr))
			counter++;
	}

	cout << "Done." << endl << endl;

	int oddCounter = 100 - counter; // the number of odd numbers

	cout << "\t> Results" << endl;
	cout << "\t> Evens: " << counter << setw(2) << "(" << counter << "%)" << endl;
	cout << "\t> Odds: " << oddCounter << setw(3) << "(" << oddCounter << "%)" << endl;

	return 0;
}

//couts welcome message
void welcome(){
	cout << "This program will generate 100 random numbers between " << MINR << " - " << MAXR
		<<" and determine how many and what percentage are odd/even." << endl;
}

//determines if the random number is odd or even
bool isEven(int oddEven){

	if (oddEven % 2 == 0)
		return true;
	else
		return false;
}
