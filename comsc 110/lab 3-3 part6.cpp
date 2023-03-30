//============================================================================
// Name        : lab 3-3 part6.cpp
// Author      : Donggy Park
// IDE used    : Eclipse
// Description : This program lets the user know if it's cold outside
//============================================================================


#include <iostream>
using namespace std;

int main() {

	double temp; // outside temperature

	cout << "What's the temperature outside? ";
	cin >> temp;

	if (temp < 60)
		cout << "It's cold outside. Wear a jacket";

	cout << "\nProgram ending";

	return 0;
}
