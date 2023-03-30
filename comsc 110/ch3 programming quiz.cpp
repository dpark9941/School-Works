//============================================================================
// Name        : ch3 programming quiz.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program generates 12 random numbers and shows the sum and the average
//============================================================================

#include <iostream>
#include <iomanip> // for output manipulators
#include <cstdlib> // for srand() and rand()
#include <ctime> // for time()
using namespace std;

const int W1 = 10; // space for the random numbers
const int W2 = 12; // space for the string literals

int main() {

	int minRandom, // minimum random number
		maxRandom; // maximum random number

	// program instruction
	cout << "***RANDOM NUMBER GENERATOR***" << endl << endl;
	cout << "Enter the min and max random numbers you'd like, and this program" << endl;
	cout << "will display 12 random numbers in column format, as well as some statistics." << endl << endl;

	// user input of random number's range
	cout << "Minimum random number desired: ";
	cin >> minRandom;
	cout << "Maximum random number desired: ";
	cin >> maxRandom;

	// random number generation part
	srand(time(0)); // seed value for rand()

	int num1 = rand() % (maxRandom - minRandom + 1) + minRandom;
	int num2 = rand() % (maxRandom - minRandom + 1) + minRandom;
	int num3 = rand() % (maxRandom - minRandom + 1) + minRandom;
	int num4 = rand() % (maxRandom - minRandom + 1) + minRandom;
	int num5 = rand() % (maxRandom - minRandom + 1) + minRandom;
	int num6 = rand() % (maxRandom - minRandom + 1) + minRandom;
	int num7 = rand() % (maxRandom - minRandom + 1) + minRandom;
	int num8 = rand() % (maxRandom - minRandom + 1) + minRandom;
	int num9 = rand() % (maxRandom - minRandom + 1) + minRandom;
	int num10 = rand() % (maxRandom - minRandom + 1) + minRandom;
	int num11 = rand() % (maxRandom - minRandom + 1) + minRandom;
	int num12 = rand() % (maxRandom - minRandom + 1) + minRandom;

	// calculation part
	int sum; // sum of random numbers
	double average; // average of random numbers

	sum = num1 + num2 + num3 + num4 + num5 + num6 + num7 + num8 + num9 + num10 + num11 + num12;
	average = sum / 12.0;

	// result output
	cout << "Your 12 random numbers in the range of " << minRandom << " and " << maxRandom << " are: " << endl << endl;

	cout << setw(W1) << num1;
	cout << setw(W1) << num2;
	cout << setw(W1) << num3;
	cout << setw(W1) << num4 << endl;

	cout << setw(W1) << num5;
	cout << setw(W1) << num6;
	cout << setw(W1) << num7;
	cout << setw(W1) << num8 << endl;

	cout << setw(W1) << num9;
	cout << setw(W1) << num10;
	cout << setw(W1) << num11;
	cout << setw(W1) << num12 << endl << endl;

	cout << setw(W2) << "Sum: " << sum << endl;
	cout << setprecision(2) << fixed << showpoint;
	cout << setw(W2) << "Average: " << average << endl;

	return 0;
}
