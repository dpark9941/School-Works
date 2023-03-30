//============================================================================
// Name        : ch2 programming quiz.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This is a program that
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

int main() {

	int lawns, //the number of total lawns
		bags; //the number of seed bags that's needed
	double length, width, totalArea;

	cout << "Hello! This is lawn seed calculator" << endl; //welcoming sentence

	//user input part
	cout << "Number of lawns in the complex: ";
	cin >> lawns;
	cout << "Average length of lawn (meters): ";
	cin >> length;
	cout << "Average width of lawn (meters): ";
	cin >> width;

	//calculation part
	totalArea = length*width*lawns;
	bags = totalArea/100;

	//result output part
	cout << setprecision(1) << fixed;
	cout << "\nYou entered " << lawns << " total lawns in the complex." << endl;
	cout << "You entered an average lawn length of " << length << " meters." << endl;
	cout << "You entered an average lawn width of " << width << " meters." << endl;
	cout << "Your total lawn area is " << totalArea << " square meters." << endl;
	cout << "You'll need to buy " << bags << " bags of grass seed." << endl;

	return 0;
}
