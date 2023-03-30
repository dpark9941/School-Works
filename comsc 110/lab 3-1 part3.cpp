//============================================================================
// Name        : lab 3-1 part3.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program outputs the user's name and age
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

int main() {

	string fullName, txtName = "Name: ", txtAge = "Age: ";
	int age;

	cout << "Enter your full name: ";
	getline(cin,fullName);

	cout << "Enter your age: ";
	cin >> age;

	cout << endl << setw(10) << txtName << fullName << endl;
	cout << setw(10) << txtAge << age << endl;

	return 0;
}
