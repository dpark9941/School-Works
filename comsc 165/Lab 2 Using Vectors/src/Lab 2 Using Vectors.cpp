//============================================================================
// Lab Name    : Lab: Using Vecots.cpp
// Author      : Donggyu Park
// Date        : 02/20/2020
// Programming Environment : Win 10, Eclipse
//============================================================================

#include <iostream>
#include <vector>
using namespace std;
const int PLAYERS = 12; // the number of players

void InputValidation(double&);

int main() {

	vector<double> playerWeights;
	double weight;
	double total = 0; // the total of player's weight
	double max = 0; // the max player's weight

	for (int i = 0; i < PLAYERS; i++){
		cout << "Enter weight #" << i+1 << ": ";
		cin >> weight;
		InputValidation(weight);
		playerWeights.push_back(weight);
		total += weight;
		if (weight > max){
			max = weight;
		}
	}

	cout << "You entered: ";
	for(int i = 0; i < PLAYERS; i++){
		cout << playerWeights.at(i) << ' ';
	}

	cout << endl << endl;
	cout << "Total weight: " << total << endl;
	cout << "Average weight: " << total / PLAYERS << endl;
	cout << "Max weight: " << max << endl;

	return 0;
}

void InputValidation(double &input){
	while (input <= 0){
		cout << "ERROR! The value has to be greater than 0.\n"
			 << "Please enter again: ";
		cin >> input;
	}
}

