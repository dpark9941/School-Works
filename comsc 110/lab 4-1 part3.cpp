//============================================================================
// Name        : lab 4-1 part3.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program tells the states of water at given temperature
//============================================================================

#include <iostream>
using namespace std;

int main() {

	double waterTemp; // the temperature of the water

	cout << "Water state calculator" << endl << endl;
	cout << "Enter a water temperature and I'll tell you the state of water at that temperature." << endl;
	cout << "Enter the temperature: ";
	cin >> waterTemp;

	if (waterTemp >= 212)
		cout << "\nAt " << waterTemp << " degrees, water is vapor." << endl;
	else if (waterTemp > 32)
		cout << "\nAt " << waterTemp << " degrees, water is liquid." << endl;
	else
		cout << "\nAt " << waterTemp << " degrees, water is solid." << endl;

	return 0;
}
