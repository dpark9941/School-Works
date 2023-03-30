//============================================================================
// Name        : program6.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program calculates your phone bill
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

const int W1 = 30; //space for string literals
const int W2 = 10; //space for numbers

const double TAXRATE = 0.075;

//charges for 1 GB of additional data
const double ADDITIONAL_DATA_A = 10;
const double ADDITIONAL_DATA_B = 5;
const double ADDITIONAL_DATA_C = 0;

//data limits for each plan
const double DATALIMIT_A = 4;
const double DATALIMIT_B = 8;
const double DATALIMIT_C = 0;

//monthly plans
const double BASEPLAN_A = 39.99;
const double BASEPLAN_B = 59.99;
const double BASEPLAN_C = 69.99;

const string S_DATAUSED = " Data used: ";
const string S_DATALIMIT = "Data limit (0 = no limit): ";
const string S_TAXRATE = "Tax rate: ";
const string S_DATAOVERAGE= "Data overage: ";
const string S_BASEPLAN = "Base plan: $";
const string S_EXTRACHARGES = "Extra data charges: $";
const string S_SUBTOTAL = "Subtotal: $";
const string S_TAXES = "Taxes: $";
const string S_TOTAL = "Total bill: $";

int main() {

	double usage, limit, overage, basePlan, extraCharges, subtotal, taxes, total;
	char plan; // phone plan

	//program instruction
	cout << "This program will calculate your phone bill based on two pieces of data that you enter:" << endl;
	cout << "your phone plan and your data usage." << endl << endl;
	cout << "Plans:" << endl;
	cout << "\tA: $39.99/month, 4GB data limit, $10/GB additional data" << endl;
	cout << "\tB: $59.99/month, 8GB data limit, $5/GB additional data" << endl;
	cout << "\tC: $69.99/month, unlimited data" << endl << endl;

	//user input
	cout << "Please enter:" << endl;
	cout << "\t> # GB used for the month: ";
	cin >> usage;
	while (usage < 0) //input validation
	{
		cout << "ERROR! # gigs must be 0 or greater. Please reenter: ";
		cin >> usage;
	}
	cout << "\t> Phone Plan (A, B, or C): ";
	cin >> plan;
	while (toupper(plan) != 'A' && toupper(plan) != 'B' && toupper(plan) != 'C') //input validation
	{
		cout << "ERROR! Phone plan must be A, B, or C. Please reenter: ";
		cin >> plan;
	}

	switch(plan)
	{
	case 'a':
	case 'A':
		basePlan = BASEPLAN_A;
		limit = DATALIMIT_A;
		if (usage > limit)
			overage = usage - limit;
		else
			overage = 0;
		extraCharges = overage * ADDITIONAL_DATA_A;
		subtotal = basePlan + extraCharges;
		taxes = subtotal * TAXRATE;
		total = subtotal + taxes;
		break;

	case 'b':
	case 'B':
		basePlan = BASEPLAN_B;
		limit = DATALIMIT_B;
		if (usage > limit)
			overage = usage - limit;
		else
			overage = 0;
		extraCharges = overage * ADDITIONAL_DATA_B;
		subtotal = basePlan + extraCharges;
		taxes = subtotal * TAXRATE;
		total = subtotal + taxes;
		break;

	case 'c':
	case 'C':
		basePlan = BASEPLAN_C;
		limit = DATALIMIT_C;
		overage = 0;
		extraCharges = overage * ADDITIONAL_DATA_C;
		subtotal = basePlan + extraCharges;
		taxes = subtotal * TAXRATE;
		total = subtotal + taxes;
		break;
	}

	//output part
	cout << setprecision(2) << fixed << showpoint << endl << endl; //output formatting
	cout << "Your itemized monthly bill:" << endl << endl;
	cout << setw(W1) << S_DATAUSED << setw(W2) << usage << endl;
	cout << setw(W1) << S_DATALIMIT << setw(W2) << limit << endl;
	cout << setw(W1) << S_TAXRATE << setw(W2) << TAXRATE * 100 << "%" << endl;
	cout << setw(W1) << S_DATAOVERAGE << setw(W2) << overage << endl << endl;

	cout << setw(W1) << S_BASEPLAN << setw(W2) << basePlan << endl;
	cout << setw(W1) << S_EXTRACHARGES << setw(W2) << extraCharges << endl;
	cout << setw(W1) << S_SUBTOTAL << setw(W2) << subtotal << endl;
	cout << setw(W1) << S_TAXES << setw(W2) << taxes << endl;
	cout << setw(W1) << S_TOTAL << setw(W2) << total << endl;

	return 0;
}

