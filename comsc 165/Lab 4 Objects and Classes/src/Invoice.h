/*
 * Invoice.h
 *
 *  Created on: 2020. 3. 22.
 *      Author: Donggyu Park
 */

#ifndef SRC_INVOICE_H_
#define SRC_INVOICE_H_

#include <string>
using namespace std;

class Invoice {
private:
	string part_number;
	string part_description;
	int quantity;
	int price;

public:
	//constructor
	Invoice();

	//mutator (or setter)
	void SetPartNumber(string userPartNumber);
	void SetPartDescription(string userPartDescription);
	void SetQuantity(int userQuantity);
	void SetPrice(int userPrice);

	//accessor (or getter)
	string GetPartNumber() const;
	string GetPartDescription() const;
	int GetQuantity() const;
	int GetPrice() const;

	int GetInvoiceAmount();
	void PrintInvoice();

};

#endif /* SRC_INVOICE_H_ */
