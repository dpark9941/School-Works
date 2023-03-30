//============================================================================
// Name        : lab 7-3 part5.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : asks user if they want to remove or insert a value to vector
//============================================================================

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

const int MAX = 100; //max range of rand()
const int MIN = 1; //min range of rand()
const int W1 = 2; //field width for numbers
const int SIZE = 10; //size of the array

//function prototype
void printVector(vector<int>);
int inputValidation();

int main(){
	srand(time(0));
	int insert; //value that gets inserted
	int where; //holds the position of the removed/added number
	vector <int> vec1(SIZE);
	cout << "===============Vector Processing Program=============== " << endl;
	cout << "This program fills a vector with 10 random numbers and then asks you to remove or insert a number" << endl;

	//fills the vector with random numbers
	cout << "Generating random numbers..." << endl;
	for (int i = 0; i < SIZE; i++)
		vec1[i] = rand() % (MAX - MIN + 1) + MIN;
	cout << "Done." << endl;
	cout << "The Original Vector:" << endl;
	printVector(vec1);

	//remove a value
	cout << "Where is the number you want to remove from the vector? : ";
	where = inputValidation();
	vec1.erase(vec1.begin() + where);
	cout << "The number has been removed." << endl;
	printVector(vec1);

	//insets a value
	cout << "Enter a number you want to add: ";
	cin >> insert;
	cout << "Where do you want to insert the number? : ";
	where = inputValidation();
	vec1.insert(vec1.begin() + where, insert);
	cout << "The number has been added." << endl;
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
	cout << endl;
}

int inputValidation(){
	int where; //holds the position of the removed/added number
	cin >> where;
	while (where < 1 || where > 10){
		cout << "ERROR! Only 1 - 10" << endl;
		cout << "Please reenter: ";
		cin >> where;
	}
	where -= 1;
	return where;
}
