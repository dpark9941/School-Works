#include <iostream>
#include "quotient.hpp"
using namespace std;


int main() {

	int input1, input2;
	int quotient;

	cout << "Enter 2 integers: ";
	cin >> input1 >> input2;

	quotient = Quotient(input1, input2);

	cout << quotient << endl;

	return 0;
}
