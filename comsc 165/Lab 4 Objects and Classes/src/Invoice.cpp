/*
 * Invoice.cpp
 *
 *  Created on: 2020. 3. 22.
 *      Author: Donggyu Park
 */

#include <iostream>
#include "Invoice.h"
using namespace std;

Invoice::Invoice() {
	part_number = "PART_NUMBER";
	part_description = "PART_DESCRIPTION";
	quantity = 0;
	price = 0;
}

void Invoice::SetPartNumber(string userPartNumber) {
	part_number = userPartNumber;
}

void Invoice::SetPartDescription(string userPartDescription) {
	part_description = userPartDescription;
}

void Invoice::SetQuantity(int userQuantity) {
	quantity = userQuantity;
}

void Invoice::SetPrice(int userPrice) {
	price = userPrice;
}

string Invoice::GetPartNumber() const {
	return part_number;
}

string Invoice::GetPartDescription() const {
	return part_description;
}

int Invoice::GetQuantity() const {
	return quantity;
}

int Invoice::GetPrice() const {
	return price;
}

int Invoice::GetInvoiceAmount() {
	return quantity * price;
}

void Invoice::PrintInvoice() {
	cout << endl << "=========Invoice=========" << endl;
	cout << "Part number: " << GetPartNumber() << endl;
	cout << "Part description: " << GetPartDescription() << endl;
	cout << "Quantity: " << GetQuantity() << endl;
	cout << "Price per item: " << GetPrice() << endl;
	cout << "Invoice amount: $ " << GetInvoiceAmount() << endl;
}
