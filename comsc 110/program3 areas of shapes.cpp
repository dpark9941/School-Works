//============================================================================
// Name        : program3.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program calculates the area of various shapes and maybe volumes too
//============================================================================

#include <iostream>
#include <cmath> // for pow(x,y)
#include <iomanip> // for output manipulators
using namespace std;

const double PI = 3.14159; //constant PI
const int W1 = 15, // width for the texts
		  W2 = 10; // width for the calculation results

int main() {

	double radius, //length of circle's radius
			squareLength, //length of a side of square
			height, //length of triangle's height
			base, //length of triangle's base
			length, //length of rectangle's length
			width; //length of rectangle's width

	double circleArea, //area of circle
			squareArea, //area of square
			triangleArea, //area of triangle
			rectangleArea; //area of rectangle

	cout << "This program will calculate the area of various shapes." << endl << endl;

	//circle calculation part
	cout << "=========================" << endl;
	cout << "Circle Calculation" << endl;
	cout << "Please enter the radius of the circle: ";
	cin >> radius;

	circleArea = PI*pow(radius,2);

	cout << "The area of the circle is " << circleArea << endl;
	cout << "=========================" << endl;

	//square calculation part
	cout << "Square Calculation" << endl;
	cout << "Please enter the length of the square: ";
	cin >> squareLength;

	squareArea = pow(squareLength,2);

	cout << "The area of the square is " << squareArea << endl;
	cout << "=========================" << endl;

	//triangle calculation part
	cout << "Triangle Calculation" << endl;
	cout << "Please enter the height of the triangle: ";
	cin >> height;
	cout << "Please enter the base of the triangle: ";
	cin >> base;

	triangleArea = (height*base)/2;

	cout << "The area of the triangle is " << triangleArea << endl;
	cout << "=========================" << endl;

	//rectangle calculation part
	cout << "Rectangle Calculation" << endl;
	cout << "Please enter the rectangle's length and width, separated by a space: ";
	cin >> length >> width;

	rectangleArea = length*width;

	cout << "The area of the rectangle is " << rectangleArea << endl;
	cout << "=========================" << endl;

	//summary part
	cout << "Summary of calculations of area in square units" << endl;
	cout << setprecision(2) << fixed << showpoint;
	cout << setw(W1) << "Circle: " << setw(W2) << circleArea << endl;
	cout << setw(W1) << "Square: " << setw(W2) << squareArea << endl;
	cout << setw(W1) << "Triangle: " << setw(W2) << triangleArea << endl;
	cout << setw(W1) << "Rectangle: " << setw(W2) << rectangleArea << endl;
	cout << "\nHave a nice day!" << endl;

	// secret functionality
	char key; // a secret key that starts volume calculator

	cout << "\nPress enter to end the program..." << endl;
	cout << "or something else to continue...";
	cin.ignore();
	cin.get(key);

	if (key == 'v') // if the user enter v
	{
		cout << "\nVolume calculator starting..." << endl << endl;
		cout << "This will calculate volumes of various 3D shapes using your previous 2D shapes." << endl << endl;

		double cylinderH, // height of cylinder
			   coneH, // height of cone
			   rectangularPrismH, // height of rectangular prism
			   triangularPrismH; // height of triangular prism

		double sphereV, // volume of sphere
			   cylinderV, // volume of cylinder
			   coneV, // volume of cone
			   rectPrismV, // volume of rectangular prism
			   triPrismV; // volume of triangular prism

		// sphere calculation
		sphereV = (4.0/3.0) * (PI * pow(radius,3));

		cout << "=========================" << endl;
		cout << "The volume of your sphere is " << sphereV << endl;
		cout << "=========================" << endl;

		// cylinder calculation
		cout << "Please enter the height of the cylinder: ";
		cin >> cylinderH;

		cylinderV = circleArea * cylinderH;

		cout << "The volume of your cylinder is " << cylinderV << endl;
		cout << "=========================" << endl;

		// cone calculation
		cout << "Please enter the height of the cone: ";
		cin >> coneH;

		coneV = (circleArea * coneH) / 3;

		cout << "The volume of your cone is " << coneV << endl;
		cout << "=========================" << endl;

		// rectangular prism calculation
		cout << "Please enter the height of the rectangular prism: ";
		cin >> rectangularPrismH;

		rectPrismV = rectangularPrismH * rectangleArea;

		cout << "The volume of your rectangular prism is " << rectPrismV << endl;
		cout << "=========================" << endl;

		// triangular prism calculation
		cout << "Please enter the height of the triangular prism: ";
		cin >> triangularPrismH;

		triPrismV = triangularPrismH * triangleArea;

		cout << "The volume of your triangular prism is " << triPrismV << endl;
		cout << "=========================" << endl;

		//summary part
		cout << "Summary of calculations of volume in square units" << endl;
		cout << setprecision(2) << fixed << showpoint;
		cout << setw(W1) << "sphere: " << setw(W2) << sphereV << endl;
		cout << setw(W1) << "cylinder: " << setw(W2) << cylinderV << endl;
		cout << setw(W1) << "cone: " << setw(W2) << coneV << endl;
		cout << setw(W1) << "rectangular: " << setw(W2) << rectPrismV << endl;
		cout << setw(W1) << "triangular: " << setw(W2) << triPrismV << endl;
		cout << "\nHave a nice day for real!" << endl;
		cout << "\nProgram ending..." << endl;

	} // if

	else
	{
		cout << "\n\nProgram ending..." << endl;

	} // else

	return 0;
}
