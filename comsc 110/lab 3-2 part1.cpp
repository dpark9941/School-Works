//============================================================================
// Name        : lab 3-2 part1.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program outputs information the user entered
//============================================================================

#include <iostream>
using namespace std;

int main() {

	string fullName, favoriteFood;
	int age;
	float weight;

	cout << "Please enter" << endl;
	cout << "Full name: ";
	getline(cin,fullName);
	cout << "Age: ";
	cin >> age;
	cout << "Favorite Food: ";
	cin.ignore();
	getline(cin,favoriteFood);
	cout << "Current Weight: ";
	cin >> weight;

	cout << "\nYou entered" << endl;
	cout << "Name: " << fullName << endl;
	cout << "Age: " << age << endl;
	cout << "Favorite Food: " << favoriteFood << endl;
	cout << "Current weight: " << weight << endl;

	return 0;
}
