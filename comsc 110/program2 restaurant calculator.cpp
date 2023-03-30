//============================================================================
// Name        : program2.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program is a restaurant calculator.
//============================================================================
#include <iostream>
#include <iomanip>
using namespace std;

int main() {

	float subtotal, tipPercentage, tax, totalWtax, tipAmount, totalBill;
	const float TAXRATE = 0.06;

	cout << "Enter the subtotal of food/beverage: ";
	cin >> subtotal;
	cout << "\nEnter the tip percentage: ";
	cin >> tipPercentage;

	totalWtax = subtotal+subtotal*TAXRATE;
	tax = subtotal*TAXRATE;
	tipAmount = totalWtax*tipPercentage/100;
	totalBill = totalWtax+tipAmount;

	string txtSubtotal = "Food & Beverage: $ ";
	string txtTax = "Tax: $ ";
	string txtTotalWtax = "Total with tax is: $ ";
	string txtTipAmount = "Tip amount is: $ ";
	string txtTotalBill = "Total bill is: $ ";

	cout << setprecision(2) << fixed << showpoint;
	cout << endl << setw(22) << txtSubtotal << setw(6) << subtotal << endl;
	cout << setw(22) << txtTax << setw(6) << tax <<endl;
	cout << setw(22) << txtTotalWtax << setw(6) << totalWtax << endl;
	cout << setw(22) << txtTipAmount << setw(6) << tipAmount << endl;
	cout << setw(22) << txtTotalBill << setw(6) << totalBill << endl;

	return 0;
}
