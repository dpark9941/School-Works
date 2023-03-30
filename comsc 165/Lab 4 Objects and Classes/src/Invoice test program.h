/*
 * Invoice test program.h
 *
 *  Created on: 2020. 3. 22.
 *      Author: Donggyu Park
 */

#ifndef SRC_INVOICE_TEST_PROGRAM_H_
#define SRC_INVOICE_TEST_PROGRAM_H_

#include <iostream>
#include "Invoice.h"
using namespace std;

void TestClass(Invoice &testInvoice) {
	bool negQuantity = testInvoice.GetQuantity() < 0;
	bool negPrice = testInvoice.GetPrice() < 0;

	if (negQuantity) {
		cout << "Quantity cannot be negative. Quantity set to 0." << endl;
		testInvoice.SetQuantity(0);
	}

	if (negPrice) {
		cout << "Price cannot be negative. Price set to 0." << endl;
		testInvoice.SetPrice(0);
	}

	if (negQuantity || negPrice){
		cout << "Invoice data members modified." << endl;
	}
}

#endif /* SRC_INVOICE_TEST_PROGRAM_H_ */
