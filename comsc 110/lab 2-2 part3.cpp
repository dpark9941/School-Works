//============================================================================
// Name        : lab 2-2 part3.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program shows the average temperature of the cities and calculates the adjusted average temperature.
//============================================================================

#include <iostream>
using namespace std;

int main() {

	float newYork=85, denver=88, phoenix=106;

	cout << "The average high temperature  for each city is"<< endl;
	cout << "New York City: " << newYork << endl;
	cout << "Denver: " << denver << endl;
	cout << "Phoenix: " << phoenix << endl << endl;

	const float RATE = 0.02;
	newYork += newYork*RATE;
	denver += denver*RATE;
	phoenix += phoenix*RATE;

	cout << "The adjusted average high temperature for each city is" << endl;
	cout << "New York City: " << newYork << endl;
	cout << "Denver: " << denver << endl;
	cout << "Phoenix: " << phoenix << endl;

	return 0;
}
