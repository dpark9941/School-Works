//============================================================================
// Name        : lab 7-4 part3.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : reads random number from a file and carries out some math tasks
//============================================================================

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

const int W1 = 8; //number field width
const int W2 = 17; //string field width

//function prototypes
void getSumAvg(int&, double&, vector<int>);
void highLow(int&, int&, vector<int>);
void oddEven(int&, int&, vector<int>);

int main(){
	ifstream inputFile;
	inputFile.open("numbers.txt");
	if(!inputFile){
		cout << "ERROR! The file doesn't exist" << endl;
		cout << "Program ending..." << endl;
		return 0;
	}

	cout << "This program reads random numbers from a file and carries out some math tasks" << endl;
	vector<int> numbers;
	int number; //hold a random number in the file
	int sum = 0; //the sum of random number in the file
	double average = 0; //the average of random number in the file
	int high = 999, low = 10000; //the highest/lowest number in the file
	int odds = 0, evens = 0; //the number of odds/evens in the file
	//inputs the numbers into the vector
	cout << "Reading the numbers from the file..." << endl;
	while (inputFile >> number)
		numbers.push_back(number);
	cout << "Done." << endl;

	cout << "Doing math..." << endl;
	double size = numbers.size(); // holds the size of the vector
	getSumAvg(sum, average, numbers);
	highLow(high, low, numbers);
	oddEven(odds, evens, numbers);
	cout << "Done." << endl;

	//displays results
	cout << setprecision(2) << fixed << showpoint << endl;
	cout << "==============RESULTS==============" << endl;
	cout << setw(W2) << "Sum: " << setw(W1) << sum << endl;
	cout << setw(W2) << "Average: " << setw(W1) << average << endl;
	cout << setw(W2) << "Highest number: " << setw(W1) << high << endl;
	cout << setw(W2) << "Lowest number: " << setw(W1) << low << endl;
	cout << setw(W2) << "Odd numbers: " << setw(W1) << odds << endl;
	cout << setw(W2) << "Even numbers: " << setw(W1) << evens << endl;
	cout << setw(W2) << "Odd percentage: " << setw(W1) << (odds / size) * 100 << "%" << endl;
	cout << setw(W2) << "Even percentage: " << setw(W1) << (evens / size) * 100 << "%" << endl;
	return 0;
}
//calculates the sum and average
void getSumAvg(int& sum, double& avg, vector<int> numbers){
	for(int val : numbers)
		sum += val;
	avg = (double)sum / numbers.size();;
}

//finds the highest/lowest number
void highLow(int& high, int& low, vector<int> numbers){
	for (int val : numbers){
		if (val > high)
			high = val;
		if (val < low)
			low = val;
	}
}

//counts the number of odds/evens
void oddEven(int& odds, int& evens, vector<int> numbers){
	for (int val : numbers){
		if (val % 2 == 0)
			evens++;
		if (val % 2 == 1)
			odds++;
	}
}

