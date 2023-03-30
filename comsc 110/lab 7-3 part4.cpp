//============================================================================
// Name        : lab 7-3 part4.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : gets numbers from user and multiplies them
//============================================================================

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

const int W1 = 2; //field width for numbers

//function prototype
void printVector(vector<int>);

int main(){
	vector <int> vec1;
	int num; //user input of numbers
	int mult; //user input of multiplier
	cout << "===============Vector Processing Program=============== " << endl;
	cout << "This program fills a vector with the numbers you enter" << endl;
	cout << "Please enter a number and if you're done entering please enter 0" << endl;
	while (num){
		cout << "Enter a number: ";
		cin >> num;
		vec1.push_back(num);
	}
	vec1.pop_back(); //deletes the sentinel value

	cout << "Enter a number you want to multiply the vector by: ";
	cin >> mult;
	while (mult == 0){
		cout << "ERROR! Try something else: ";
		cin >> mult;
	}

	cout << "Multiplying the vector..." << endl;
	for (int &val : vec1)
		val *= mult;
	cout << "Done." << endl;

	cout << "Here's the table!" << endl << endl;
	printVector(vec1);
	return 0;
}

//prints out a vector
void printVector(vector<int> vec1){
	int counter = 0; //counts the number of random numbers in one row
	for (int val : vec1){
		cout << setw(W1) << val << " ";
		counter++;
		if (counter == 5){
			cout << endl;
			counter = 0;
		}
	}
}
