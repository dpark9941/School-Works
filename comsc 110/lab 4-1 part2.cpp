//============================================================================
// Name        : lab 4-1 part2.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program compares the areas of 2 rectangles
//============================================================================

#include <iostream>
using namespace std;

int main() {

	double length1, width1, // length and width of rectangle 1
		   length2, width2; // length and width of rectangle 2
	double area1, // area of rectangle 1
		   area2; // area of rectangle 2

	cout << "Enter the dimensions of 2 rectangles and I'll calculate which one has the greater area." << endl;

	cout << "\nRectangle 1" << endl << endl;
	cout << "Length: ";
	cin >> length1;
	cout << "Width: ";
	cin >> width1;

	area1 = length1 * width1;

	cout << "\nRectangle 2" << endl << endl;
	cout << "Length: ";
	cin >> length2;
	cout << "Width: ";
	cin >> width2;

	area2 = length2 * width2;

	if (area1 > area2)
		cout << "\nResults: Rectangle 1 has the greater area: " << area1 << " vs. " << area2 << endl;

	else if (area1 < area2)
		cout << "\nResults: Rectangle 2 has the greater area: " << area2 << " vs. " << area1 << endl;

	else
		cout << "\nResults: Rectangle 1 and Rectangle 2 has the same area: " << area1 << " vs. " << area2 << endl;

	return 0;
}
