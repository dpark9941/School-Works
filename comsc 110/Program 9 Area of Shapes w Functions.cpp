//============================================================================
// Name        : program 9.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : calculates the area of shapes using functions
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

const int W1 = 10;
const int W2 = 10;

//function prototypes
double getLength();
double getWidth();
double getArea(double, double);
void displayResults(double, double, double);
double inputValidation(double);

int main(){

	double length; //holds the rectangle's length
	double width; //holds the rectangle's width
	double area; //holds the rectangle's area

	length = getLength();
	width = getWidth();
	area = getArea(length, width);
	displayResults(length, width, area);

	return 0;
}

//asks the user to enter the rectangle length
double getLength(){

	double length;
	cout << "Please enter the length: ";
	cin >> length;
	length = inputValidation(length);
	return length;
}

//asks the user to enter the rectangle width
double getWidth(){

	double width;
	cout << "Please enter the width: ";
	cin >> width;
	width = inputValidation(width);
	return width;
}

//calculates the area
double getArea(double length, double width){

	double area;
	area = length * width;
	return area;
}

//displays the results
void displayResults(double length, double width, double area){

	cout << setprecision(2) << fixed << showpoint << endl;
	cout << setw(W1) << "Length: " << setw(W2) << length << endl;
	cout << setw(W1) << "Width: " << setw(W2) << width << endl;
	cout << setw(W1) << "Area: " << setw(W2) << area << endl;
}

//input validation
double inputValidation(double response){

	while (response <= 0)
	{
		cout << "ERROR! the value must be greater than 0. Please reenter: ";
		cin >> response;
	}

	return response;
}
