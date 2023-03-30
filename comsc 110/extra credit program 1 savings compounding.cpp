//============================================================================
// Name        : extra credit program 1.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program calculates future balance amount
//============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const int W1 = 20; // space for string literals
const int W2 = 15; // space for numbers

int main() {

	double principal, interestRate, interest, totalAmount;
	int timesCompounded; // the number of times interest is compounded during the year

	cout << "This program will calculate the amount you'd have in savings, given the starting principal," << endl;
	cout << "interest rate, and number of compounding periods per year, which you enter." << endl << endl;

	cout << "Please enter starting principal in dollars and cents: ";
	cin >> principal;
	while (principal < 0) // input validation
	{
		cout << "ERROR! The value must be a positive number";
		cin >> principal;
	}

	cout << "Please enter the interest rate in decimal format (e.g. 4% enter 0.04): ";
	cin >> interestRate;
	while (interestRate < 0) // input validation
	{
		cout << "ERROR! The value must be a positive number";
		cin >> interestRate;
	}

	cout << "Please enter the number of compounding periods per year in whole numbers: ";
	cin >> timesCompounded;
	while (timesCompounded < 0) // input validation
	{
		cout << "ERROR! The value must be a positive number";
		cin >> timesCompounded;
	}

	totalAmount = principal * pow ((1 + (interestRate / timesCompounded)), timesCompounded);
	interest = totalAmount - principal;

	cout << setprecision(2) << fixed << showpoint; // output manipulators
	cout << "\n\n*******Your future savings amount*******" << endl << endl;
	cout << left << setw(W1) << "Interest rate:" << right << setw(W2) << (interestRate *= 100) << "%" << endl;
	cout << left << setw(W1) << "Times compounded:" << right << setw(W2) << timesCompounded << endl;
	cout << left << setw(W1) << "Principal:" << "$" << right << setw(W2-1) << principal << endl;
	cout << left << setw(W1) << "Interest:" << "$" <<right << setw(W2-1) << interest << endl;
	cout << left << setw(W1) << "Amount in savings:" << "$" <<right << setw(W2-1) << totalAmount << endl;
	cout << "\nProgram ending... Have a superior day" << endl;

	return 0;
}
