//============================================================================
// Name        : lab 5-4 part1.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program asks the user to guess a random number
//============================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAXR = 10;
const int MINR = 1;

int main() {

	int userGuess; //user input number
	int randNr; //the random number generated

	//random number generator
	srand(time(0)); //seed value for rand()
	randNr = rand() % (MAXR - MINR + 1) + MINR;

	cout << "I'm thinking of a number 1 - 10. Can you guess what it is?: ";
	cin >> userGuess;
	while (userGuess < MINR || userGuess > MAXR) //input validation
	{
		cout << "\t> ERROR! Guess 1- 10 only please: ";
		cin >> userGuess;
	}
	while (userGuess != randNr)
	{
		if (userGuess <= randNr)
			cout << "\t> No, that's too low" << endl;
		if (userGuess >= randNr)
			cout << "\t> No, that's too high" << endl;
		cout << "\t> Guess again: ";
		cin >> userGuess;
	}

	cout << "\n=============================" << endl;
	cout << "Congratulations! You got it!!" << endl;
	cout << "=============================" << endl;

	return 0;
}
