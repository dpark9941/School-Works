//============================================================================
// Name        : lab 5-3 part4.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program calculates daily earning and the average
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

const int W1 = 15;
const int W2 = 10;

int main() {

	int transactions = 0; // the number of transactions
	double earning, subTotal, average;

	cout << "SUMMATION PROGRAM" << endl << endl;
	cout << "Enter today's earning by transaction" << endl;
	cout << "Transaction #" << transactions + 1 << ": ";
	cin >> earning;

	while (earning != -1)
	{
		subTotal += earning;
		transactions++;

		cout << "\nTransaction #" << transactions + 1 << endl;
		cout << "If you're done entering, please enter -1: ";
		cin >> earning;
		while (earning < 0 && earning != -1) //input validation
		{
			cout << "ERROR! only enter positive number: ";
			cin >> earning;
		}
	}

	average = subTotal / transactions;

	cout << setprecision(2) << fixed << showpoint << endl;
	cout << "---------RESULTS---------" << endl << endl;
	cout << left << setw(W1) << "Total: " << "$" << right << setw(W2-1) << subTotal << endl;
	cout << left << setw(W1) << "Transactions: " << right << setw(W2) << transactions << endl;
	cout << left << setw(W1) << "Average: " << "$" << right << setw(W2-1) << average << endl;
	cout << "\nProgram ending... Have a nice day!" << endl;

	return 0;
}
