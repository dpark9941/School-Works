//============================================================================
// Name        : lab 3-3 part7.cpp
// Author      : Donggy Park
// IDE used    : Eclipse
// Description : This program lets the user know if they're eligible for AARP
//============================================================================

#include <iostream>
using namespace std;

int main() {

	int age;

	cout << "Please enter your age: ";
	cin >> age;

	if (age >= 50)
	{
		cout << "You are eligible for AARP!" << endl;
		cout << "Don't forget the dinner at the Denny's restaurant at 4:30pm.";
	} // if

	else
	{
		cout << "You are not eligible for AARP yet." << endl;
		cout << "You can eat at Denny's whenever you want!";
	} // else

	return 0;
}
