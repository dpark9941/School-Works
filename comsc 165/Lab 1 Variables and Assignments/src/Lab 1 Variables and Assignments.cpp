//============================================================================
// Lab Name    : Lab: Variables and Assignments.cpp
// Author      : Donggyu Park
// Date        : 02/09/2020
// Programming Environment : Win 10, Eclipse
//============================================================================

#include <iostream>
#include <cmath> // round()
using namespace std;
const double AREA_PER_GALLON = 350; // 1 gallon of paint covers 350 square feet

void InputValidation(double&);

int main() {

	double height, width;
	double area;
	double paintNeeded;

	cout << "Enter the wall's height (feet): ";
	cin >> height;
	InputValidation(height);
	cout << "Enter the wall's width (feet): ";
	cin >> width;
	InputValidation(width);

	area = height * width;
	paintNeeded = area / AREA_PER_GALLON;

	cout << endl;
	cout << "Wall area: " << area << " square feet" << endl;
	cout << "Paint needed: " << paintNeeded << " gallons" << endl;
	cout << "Cans needed: " << round(paintNeeded) << " can(s)" << endl;

	return 0;
}

void InputValidation(double &input){
	while (input <= 0){
		cout << "ERROR! The value has to be greater than 0. Please enter again: ";
		cin >> input;
	}
}

