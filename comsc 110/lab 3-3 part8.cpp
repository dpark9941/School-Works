//============================================================================
// Name        : lab 3-3 part8.cpp
// Author      : Donggy Park
// IDE used    : Eclipse
// Description : This program tells if water is frozen at a given temperature
//============================================================================

#include <iostream>
using namespace std;

int main() {

	double waterTemp;

	cout << "Enter the temperature of water: ";
	cin >>waterTemp;

	if (waterTemp > 32)
		cout << "At the temperature you've entered, the water is not frozen.";
	else
		cout << "At the temperature you've entered, the water is frozen.";

	return 0;
}
