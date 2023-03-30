//============================================================================
// Name        : lab 3-2 part3.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program calculates the area of a trapezoid
//============================================================================

#include <iostream>
using namespace std;

int main() {

	float height, topBase, bottomBase, area;

	cout << "This program calculates the area of a trapezoid" << endl;
	cout << "Please enter" << endl;
	cout << "the height of the trapezoid: ";
	cin >> height;
	cout << "the length of the top base: ";
	cin >> topBase;
	cout << "the length of the bottom base: ";
	cin >> bottomBase;

	area = height*(topBase+bottomBase)/2;

	cout << "The area is " << area;

	return 0;
}
