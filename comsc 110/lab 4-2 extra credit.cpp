//============================================================================
// Name        : lab 4-2 extra credit.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program
//============================================================================

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double PI = 3.14159;
int main() {

	int choice;

	double radius, // radius of circle
		   length, // length of rectangle
		   width, // width of rectangle
		   base, // base of triangle
		   height; // height of triangle

	double circleArea, // area of circle
		   rectArea, // area of rectangle
		   triArea; // area of triangle

	cout << "***Geometry Calculator***" << endl;
	cout << "Enter:" << endl;
	cout << "1: Calculate the area of a circle" << endl;
	cout << "2: Calculate the area of a rectangle" << endl;
	cout << "3: Calculate the area of a triangle" << endl;
	cout << "4: Quit" << endl << endl;
	cout << "Enter your choice (1-4): ";
	cin >> choice;

	cout << setprecision(2) << fixed << showpoint; // output formatting

	switch (choice)
	{
	// circle calculation
	case 1:
		cout << "***You've selected: CIRCLE***" << endl;
		cout << "Enter the circle's radius: ";
		cin >> radius;

		circleArea = PI * pow(radius,2);

		if (radius >= 0)
			cout << "The circle's area is " << circleArea << endl;
		else
			cout << "ERROR! the value must be positive" << endl;
		break;
	// rectangle calculation
	case 2:
		cout << "***You've selected: RECTANGLE***" << endl;
		cout << "Enter the length: ";
		cin >> length;
		cout << "Enter the width: ";
		cin >> width;

		rectArea = length * width;

		if (length < 0 || width < 0) // if any of the values is negative
			cout << "ERROR! the value must be positive" << endl;
		else
			cout << "The rectangle's area is: " << rectArea << endl;
		break;
	// triangle calculation
	case 3:
		cout << "***You've selected: TRIANGLE" << endl;
		cout << "Enter the base: ";
		cin >> base;
		cout << "Enter the height: ";
		cin >> height;

		triArea = base * height /2;

		if (base < 0 || height < 0) // if any of the values is negative
			cout << "ERROR! the value must be positive" << endl;
		else
			cout << "The triangle's area is: " << triArea << endl;
		break;
	// quit
	case 4:
		cout << "You've selected: QUIT" << endl;
		break;

	default:
		cout << "ERROR! Only choose between 1-4" << endl;
	} // switch (choice)

	cout << "Program ending... Have a nice day!" << endl;

	return 0;
}
