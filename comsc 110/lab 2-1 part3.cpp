//============================================================================
// Name        : lab 2-1 part3.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This is a program that calculates the sales tax on an item
//============================================================================

#include <iostream>
using namespace std;

int main() {

	float costWOtax, costWtax, tax;
	cout << "enter the cost of your item: ";
	cin >> costWOtax;

	tax=costWOtax*0.075;
	costWtax=costWOtax+tax;

	cout << "the tax is " << tax << " dollars" << endl;
	cout << "and the total cost is " << costWtax << " dollars";

	return 0;
}
