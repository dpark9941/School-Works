//============================================================================
// Name        : lab 10-1 part3.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : allows a user to enter values and finds the average, the highest, the lowest and the median value
//============================================================================

#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
using namespace std;

const int SIZE = 100; //size of the array that is large enough for float type
const int W1 = 10; //string field width
const int W2 = 7; //number field width

//function prototype
void inputValidation(char[]);
void sortArray(vector<float>&, int);
void swap(int, int);

int main(){
	int counter = 0; //counts the number of numbers that user entered
	vector<float> numbers; //holds the user input number as float
	double num;
	char input[SIZE]; //holds user input
	double sum = 0; //sum of user's numbers

	cout << "This program will have you enter numbers and will find the average, the highest, the lowest and the median value." << endl;
	cout << "Enter your numbers. When you're done entering enter \'Q\' to see the result: ";
	cin.getline(input, SIZE);
	inputValidation(input);
	while (tolower(input[0]) != 'q'){
		num = stof(input);
		numbers.push_back(num);
		sum += numbers[counter];
		counter++;
		for (int i = 0; i < counter; i++){
			cout << numbers[i] << " ";
		}
		cout << endl;
		cout << "Enter your numbers. When you're done entering enter \'Q\' to see the result: ";
		cin.getline(input, SIZE);
		inputValidation(input);
	}

	sortArray(numbers, counter);

	//displays the result
	cout << setw(W1) << "Average: " << setw(W2) << sum / counter << endl;
	cout << setw(W1) << "Highest: " << setw(W2) << numbers[counter-1] << endl;
	cout << setw(W1) << "Lowest: " << setw(W2) << numbers[0] << endl;
	cout << setw(W1) << "Median: " << setw(W2) << numbers[counter/2] << endl;

	return 0;
}

//=======================================================
//Function name: inputValidation
//Purpose: input validation
//List of parameters: a char array
//Return type: void
//Returns:
//=======================================================
void inputValidation (char input[SIZE]){
	while (tolower(input[0]) != 'q' && !isdigit(input[0])){
		cout << "ERROR! Only enter 'Q' or a number: ";
		cin.getline(input, SIZE);
	}
}

//=======================================================
//Function name: sortArray
//Purpose: sorts arrays
//List of parameters: vector<float> numbers
//Return type: void
//Returns:
//=======================================================
void sortArray(vector<float> &numbers, int counter){
	for (int maxElement = counter - 1; maxElement > 0; maxElement--){
		for (int index = 0; index < maxElement; index++){
			if (numbers[index] > numbers[index + 1]){
				swap(numbers[index], numbers[index + 1]);
			}
		}
	}
}

//=======================================================
//Function name: swap
//Purpose: swaps the order of elements of array
//List of parameters: two elements of an array
//Return type: void
//Returns:
//=======================================================
void swap(int a, int b){
	int temp = a;
	a = b;
	b = temp;
}
