//============================================================================
// Name        : lab 2-2 part2.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program outputs the retail price from the wholesale price with 35% markup.
//============================================================================

#include <iostream>
using namespace std;

int main() {

	float price;

	cout << "Enter the wholesale price :";
	cin >> price;

	price += price*0.35;

	cout << "The retail price is " << price;

	return 0;
}
