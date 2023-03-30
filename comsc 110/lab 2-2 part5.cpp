//============================================================================
// Name        : lab 2-2 part5.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program calculates how much paint is needed in order to paint a fence.
//============================================================================

#include <iostream>
using namespace std;

int main() {

	float length, height, area, paint;

	cout << "Enter the length of the fence: ";
	cin >> length;
	cout << "Enter the height of the fence: ";
	cin >> height;

	area = length*height;
	paint = area/200;

	cout << "You need to paint " << area << " square feet." << endl;
	cout << "You need " << paint << " gallons of paint.";

	return 0;
}

