//============================================================================
// Name        : program7.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program will simulate flipping a coin and keeping track of how many heads/tails have shown
//============================================================================

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MINTOSS = 1; //minimum range of tosses
const int MAXTOSS = 100000; //maximum range of tosses
const int MAXR = 1; // maximum random number
const int MINR = 0; //minimum random number
const int W1 = 12; //width for string literal
const int W2 = 8; //width for numbers

int main(){

	srand(time(0));
	bool head; // either heads or tails
	double hPercentage; //percentage of heads
	double tPercentage; // percentage of tails
	char repeat; //repeats the whole program

	do
	{
		int tosses = 0; //the number of tosses
		int heads = 0; // the number of heads
		int tails = 0; //the number of tails

		cout << "-------------------------COIN FLIP SIMULATOR-------------------------" << endl;
		cout << "This program will let you enter the number of coin tosses you'd" << endl;
		cout << "like to make, and then tell you what the heads/tails distribution is." << endl << endl;
		cout << "How many tosses would you like? (" << MINTOSS << " - " << MAXTOSS << "): ";
		cin >> tosses;
		while (tosses < MINTOSS || tosses > MAXTOSS) // input validation
		{
			cout << "ERROR! Please choose between " << MINTOSS << " - " << MAXTOSS << ": ";
			cin >> tosses;
		}

		for (int i = 1; i <= tosses; i++)
		{
			head = rand() % (MAXR - MINR + 1) + MINR;
			if (head)
				heads++;
		}

		tails = tosses - heads;
		hPercentage = (heads / (double)tosses) * 100;
		tPercentage = (tails / (double)tosses) * 100;

		cout << setprecision(2) << fixed << showpoint << endl;
		cout << "=======COIN FLIP RESULTS=======" << endl << endl;
		cout << setw(W1) << "Flips: " << setw(W2) << tosses << endl;
		cout << setw(W1) << "# Heads: " << setw(W2) << heads << " / " << hPercentage << "%" << endl;
		cout << setw(W1) << "# Tails: " << setw(W2) << tails << " / " << tPercentage << "%" << endl << endl;

		cout << "Repeat program? Y/N: ";
		cin >> repeat;
		while (tolower(repeat) != 'y' && tolower(repeat) != 'n') //input validation
		{
			cout << "ERROR! Y/N only: ";
			cin >> repeat;
		}
	} while (tolower(repeat) == 'y');

	cout << "Program ending... Have a nice day";

	return 0;
}
