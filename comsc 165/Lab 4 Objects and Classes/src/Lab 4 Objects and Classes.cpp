//============================================================================
// Lab Name    : Lab: Objects and Classes.cpp
// Author      : Donggyu Park
// Date        : 03/22/2020
// Programming Environment : Win 10, Eclipse
//============================================================================

#include <iostream>
#include "Invoice.h"
#include "Invoice test program.h"
using namespace std;

int main() {

	Invoice invoice1;

	string userPartNumber;
	string userPartDescription;
	int userQuantity;
	int userPrice;

	cout << "Enter part number: ";
	cin >> userPartNumber;
	invoice1.SetPartNumber(userPartNumber);

	cout << "Enter part description: ";
	cin.ignore();
	getline(cin, userPartDescription);
	invoice1.SetPartDescription(userPartDescription);

	cout << "Enter quantity: ";
	cin >> userQuantity;
	invoice1.SetQuantity(userQuantity);

	cout << "Enter price per item: $ ";
	cin >> userPrice;
	invoice1.SetPrice(userPrice);

	TestClass(invoice1);

	invoice1.PrintInvoice();

	return 0;
}
