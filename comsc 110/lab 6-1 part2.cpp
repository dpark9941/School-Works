//============================================================================
// Name        : lab 6-1 part2.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : asks wholesale cost and then displays retail price
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

void calculateRetail(double, double);

int main(){

	double wholesale; //wholesale price
	double markup; //markup percentage

	cout << "Enter the wholesale price: ";
	cin >> wholesale;
	while (wholesale < 0)
	{
		cout << "ERROR! Enter a positive number: ";
		cin >> wholesale;
	}
	cout << "Enter the markup percentage: ";
	cin >> markup;

	calculateRetail(wholesale, markup);
	return 0;
}

void calculateRetail(double cost, double percentage){

	double rate = percentage / 100;
	double retailPrice = cost + cost * rate;

	cout << setprecision(2) << fixed << showpoint;
	cout << "Wholesale cost: $ " << cost << endl;
	cout << "Markup percentage: " << percentage << "%" << endl;
	cout << "Retail price: $ " << retailPrice << endl;
}
