//============================================================================
// Name        : Ch4 programming quiz.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program shows if a certain substance is frozen or boiling at a given temerature
//============================================================================

#include <iostream>
using namespace std;

const double OXYGENF = -362, ETHYLALCOHOLF = -173, MERCURYF = -38, WATERF = 32; //the freezing point of the substances
const double THEHIGHEST = 32; // the highest freezing point among the substances given
const double OXYGENB = -306, EHTHYLALCOHOLB = 172, MERCURYB = 676, WATERB = 212; // the boiling point of the substances
const double THELOWEST = -306; // the lowest boiling point among the substances given

int main() {

	int temp; // user input of temperature

	cout << "===FREEZING AND BOILING POINTS===" << endl;
	cout << "Enter a temperature (F), and you'll find which substances are frozen and which are boiling." << endl << endl;
	cout << "Enter a temperature: ";
	cin >> temp;

	cout << "At a temperature of " << temp << " these substances are frozen: " << endl;
	cout << (temp <= OXYGENF ? "Oxygen\n" : "");
	cout << (temp <= ETHYLALCOHOLF ? "Ethyl Alcohol\n" : "");
	cout << (temp <= MERCURYF ? "Mercury\n" : "");
	cout << (temp <= WATERF ? "Water\n" : "");
	cout << (temp > THEHIGHEST ? "None\n" : "");

	cout << "\nAt a temperature of " << temp << " these substances are boiling: " << endl;
	cout << (temp >= OXYGENB ? "Oxygen\n" : "");
	cout << (temp >= EHTHYLALCOHOLB ? "Ethyl Alcohol\n" : "");
	cout << (temp >= MERCURYB ? "Mercury\n" : "");
	cout << (temp >= WATERB ? "Water\n" : "");
	cout << (temp < THELOWEST ? "None\n" : "");

	cout << "\nProgram ending..." << endl;

	return 0;
}
