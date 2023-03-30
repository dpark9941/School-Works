//============================================================================
// Name        : Final Prep.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : Final Prep
//============================================================================

/* BUBBLE SORT FUNCTION

void bubbleSort(int array1[SIZE]){
	for (int maxElement = SIZE - 1; maxElement > 0; maxElement--){
		for (int index = 0; index < maxElement; index++){
			if (array1[index] > array1[index + 1]){
				swap(array1[index], array1[index + 1]);
			}
		}
	}
}

void swap(int &a, int &b){
	char temp = a;
	a = b;
	b = temp;
}
BUBBLE SORT FUNCTION */

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;
/* PROGRAM 1
void makeVec(vector<int>&);
int displayMenu(vector<int>);
void displayVec(vector<int>);
void sumElements(vector<int>);
void sumElementsSq(vector<int>);
void displaySmall(vector<int>);
void displayLarge(vector<int>);
void bubbleSort(vector<int>&);
void swap(int &, int &);

int main(){
	vector<int> numbers;
	int choice;
	makeVec(numbers);
	cout << endl;
	do{
		displayVec(numbers);
		choice = displayMenu(numbers);
		if (choice == 1)
			sumElements(numbers);
		if (choice == 2)
			sumElementsSq(numbers);
		if (choice == 3)
			displaySmall(numbers);
		if (choice == 4)
			displayLarge(numbers);
		if (choice == 5){
			numbers.clear();
			makeVec(numbers);
		}
	} 	while (choice != 6);

	cout << "Program ending." << endl;
	return 0;
}

//=======================================================
//Function name: isEmpty
//Purpose: shows directions when collection is empty
//List of parameters:
//Return type: int
//Returns: select
//=======================================================
void makeVec(vector<int> &numbers){
	int number;
	char input[100];
	cout << "Let's populate the vector. Enter a number: ";
	cin >> number;
	numbers.push_back(number);
	while(tolower(input[0]) != 'q'){
		cout << "Enter your next number or (Q)uit: ";
		cin >> input;
		if (!isdigit(input[0])){
			break;
		}
		number = stoi(input);
		numbers.push_back(number);
	}
}

int displayMenu(vector<int> numbers){
	int choice;
	cout << "What would you like to do with this vector? Enter:" << endl;
	cout << "1 | Sum elements" << endl;
	cout << "2 | Sum of each element squared" << endl;
	cout << "3 | Display smallest element" << endl;
	cout << "4 | Display largest element" << endl;
	cout << "5 | Create a new vector and start over" << endl;
	cout << "6 | End program" << endl;
	cout << "choice? --> ";
	cin >> choice;
	return choice;
}

void displayVec(vector<int> numbers){
	cout << "Your vector is: ";
	for (int i = 0; i < numbers.size(); i++){
		cout << numbers[i] << ' ';
	}
	cout << endl;
}

void sumElements(vector<int> numebrs){
	int sum = 0;
	for (int val : numebrs){
		sum += val;
	}
	cout << "Sum of the vector: " << sum << endl;
}
void sumElementsSq(vector<int> numbers){
	int sum = 0;
	for (int val : numbers){
		sum += pow(val, 2);
	}
	cout << "Sum of the square of the vector: " << sum << endl;
}
void displaySmall(vector<int> numbers){
	bubbleSort(numbers);
	cout << "Smallest number: " << numbers[0] << endl;

}
void displayLarge(vector<int> numbers){
	bubbleSort(numbers);
	cout << "Largest number: " << numbers.back() << endl;

}

void bubbleSort(vector<int> &numbers){
	int size = numbers.size();
    for (int maxElement = size - 1; maxElement > 0; maxElement--)
        for (int index = 0; index < maxElement; index++)
            if (numbers[index] > numbers[index + 1])
                swap(numbers[index], numbers[index + 1]);
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
PROGRAM 1 */

/* PROGRAM 4
void compareChar(char, char[]);
void bubbleSort(char[]);
void swap(char &, char &);

const int SIZE = 30;

int main(){
	int choice = 0;
	char compare;
	char array1[SIZE] = {'V','D','g','e','B','t','U','o','p','W','x','T','s','n','M','R','E','v','h','J','w','Q','y','I','i','N','m','d','X','c'};

	cout << "This program will compare your input letter alphabetically with a programmed array of characters," << endl
		<< "and tell you which fall before your letter alphabetically." << endl << endl;
	do {
		cout << "Press 1 to compare a character with the array of letters" << endl;
		cout << "      2 to quit" << endl;
		cout << "Choice: ";
		cin >> choice;
		if (choice == 2) continue;
		cout << "Enter a character to compare: ";
		cin >> compare;
		compareChar(compare, array1);
	} while (choice != 2);

	cout << "Program ending... have a nice day" << endl;

	return 0;
}

void compareChar(char compare, char array1[SIZE]){
	vector<char> array2;
	for (int i = 0 ; i < SIZE; i++){
		if (tolower(array1[i]) < tolower(compare)){
			array2.push_back(array1[i]);
		}
	}

	cout << "the following " << array2.size() << " letters come alphabetically before " << compare << ":" << endl;
	for (char val : array2){
		cout << val << ' ';
	}
	cout << endl;
}
PROGRAM 4 */

