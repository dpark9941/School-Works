//============================================================================
// Name        : lab 10-1 part2.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : allows a user to enter values and averages them
//============================================================================

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

const int SIZE = 100; //size of the array that is large enough for int type

//function prototype
void inputValidation (char[]);

int main(){
	int counter = 0; //counts the number of numbers that user entered
	int num; //holds the user input number as integer
	char input[SIZE]; //holds user input
	double sum = 0; //sum of user's numbers

	cout << "This program will have you enter numbers and average them." << endl;
	cout << "Enter your numbers. When you're done entering enter \'Q\' to see the result: ";
	cin.getline(input, SIZE);
	inputValidation(input);
	while (tolower(input[0]) != 'q'){
		num = stoi(input);
		sum += num;
		counter++;
		cout << "Enter your numbers. When you're done entering enter \'Q\' to see the result: ";
		cin.getline(input, SIZE);
		inputValidation(input);
	}
	cout << "Average: " << sum / counter << endl;
	return 0;
}

//=======================================================
//Function name: inputValidation
//Purpose: input validation
//List of parameters: a char array
//Return type: void
//Returns:
//=======================================================
void inputValidation (char input[]){
	while (tolower(input[0]) != 'q' && !isdigit(input[0])){
		cout << "ERROR! Only enter 'Q' or a number: ";
		cin.getline(input, SIZE);
	}
}
