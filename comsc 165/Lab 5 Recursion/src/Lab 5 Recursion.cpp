//============================================================================
// Lab Name    : Lab: Recursion.cpp
// Author      : Donggyu Park
// Date        : 04/25/2020
// Programming Environment : Win 10, Eclipse
//============================================================================

#include <iostream>
using namespace std;

void GuessNumber(int, int);

int main() {

	cout << "Choose a number from 1 - 100 and I will guess the number." << endl;
	cout << "Enter H for high, L for low and any other key if the guess is correct." << endl;

	GuessNumber(1, 100);

	return 0;
}

void GuessNumber(int low, int high) {

	int mid;
	char userInput;

	mid = (low + high) / 2;

	cout << "Is it " << mid << "? (H or L): ";
	cin >> userInput;

	if (tolower(userInput) != 'h' && tolower(userInput) != 'l') {
		cout << "Your number is " << mid << "!" << endl;
		cout << "Thank you!" << endl;
	}

	else {
		if (tolower(userInput) == 'l') {
			GuessNumber(low, mid);
		}
		else {
			GuessNumber(mid + 1, high);
		}
	}
}




