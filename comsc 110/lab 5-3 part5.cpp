//============================================================================
// Name        : lab 5-3 part5.cpp
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

	int transactions; // the number of transactions
	int transactionsOverall = 0;
	double earning, subtotal, average;
	double subtotalOverall = 0;
	char again;

	cout << "SUMMATION PROGRAM" << endl;
	do
	{
		transactions = 0;
		subtotal = 0;
		cout << "\nEnter today's earning by transaction" << endl;
		cout << "Transaction #" << transactions + 1 << ": ";
		cin >> earning;

		while (earning != -1)
		{
			subtotal += earning;
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

		average = subtotal / transactions;

		cout << setprecision(2) << fixed << showpoint << endl;
		cout << "---------RESULTS---------" << endl << endl;
		cout << left << setw(W1) << "Total: " << "$" << right << setw(W2-1) << subtotal << endl;
		cout << left << setw(W1) << "Transactions: " << right << setw(W2) << transactions << endl;
		cout << left << setw(W1) << "Average: " << "$" << right << setw(W2-1) << average << endl;

		subtotalOverall += subtotal;
		transactionsOverall += transactions;

		cout << "\nDo you want to calculate another day? Y/N: ";
		cin >> again;
	} while (toupper(again) == 'Y');

	average = subtotalOverall / transactionsOverall;

	cout << "\n-----OVERALL RESULTS-----" << endl;
	cout << left << setw(W1) << "Total: " << "$" << right << setw(W2-1) << subtotalOverall << endl;
	cout << left << setw(W1) << "Transactions: " << right << setw(W2) << transactionsOverall << endl;
	cout << left << setw(W1) << "Average: " << "$" << right << setw(W2-1) << average << endl;


	cout << "\nProgram ending... Have a nice day!" << endl;

	return 0;
}
