//============================================================================
// Name        : program5.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program is a restaurant chooser
//============================================================================

#include <iostream>
using namespace std;

int main() {

	bool vegetarian = false, vegan = false, glutenFree = false;
	char vegetarianChar, veganChar, glutenFreeChar;

	// program instruction, user input part
	cout << "This program will help you select a restaurant." << endl;
	cout << "Is anyone in your party a vegetarian? Y/N : ";
	cin >> vegetarianChar;
	while (toupper(vegetarianChar) != 'Y' && toupper(vegetarianChar) !='N') // input validation
	{
		cout << "ERROR! Only enter Y or N: ";
		cin >> vegetarianChar;
	}

	cout << "Is anyone in your party a vegan? Y/N : ";
	cin >> veganChar;
	while (toupper(veganChar) != 'Y' && toupper(veganChar) !='N') // input validation
	{
		cout << "ERROR! Only enter Y or N: ";
		cin >> veganChar;
	}

	cout << "Does anyone in your party require gluten-free options? Y/N : ";
	cin >> glutenFreeChar;
	while (toupper(glutenFreeChar) != 'Y' && toupper(glutenFreeChar) !='N') // input validation
	{
		cout << "ERROR! Only enter Y or N: ";
		cin >> glutenFreeChar;
	}

	if (toupper(vegetarianChar) == 'Y')
		vegetarian = true;
	if (toupper(veganChar) == 'Y')
		vegan = true;
	if (toupper(glutenFreeChar) == 'Y')
		glutenFree = true;

	// output part
	cout << "\nHere are your restaurant choices:" << endl;
	cout << (!vegetarian && !vegan && !glutenFree ? "Mel's Diner\n" : "");
	cout << (!vegan ? "Zachary's Pizza\n" : "");
	cout << ((vegetarian + vegan + glutenFree) >= 0 ? "Corner Cafe\n" : "");
	cout << (!vegan && !glutenFree ? "Mama's Italian\n" : "");
	cout << ((vegetarian + vegan + glutenFree) >= 0 ? "Chef's Kitchen\n" : "");

	return 0;
}


