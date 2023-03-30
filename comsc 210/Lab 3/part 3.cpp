//*****************
//Program Name: Lab 3 part 3
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: Write a simple function that reserves the order of elements in an array
//*****************

#include <iostream>
using namespace std;

void enterArrayData(int*);
void outputArrayData(int*);
void sumArray(int*);
int* reverseArrayData(int[]);
void plagiarismRequirement();

const int ARR_SIZE = 5; //the size of the array

int main(){
	//variable declarations
	int arr1[ARR_SIZE];

	//puts data into array
	enterArrayData(arr1);
	cout << endl;

	//outputs the original array
	cout << "Printing the original array" << endl;
	outputArrayData(arr1);
	cout << endl;

	//outputs the reversed array
	cout << "Printing the reversed array" << endl;
	outputArrayData(reverseArrayData(arr1));
	cout << endl;

	//outputs plagiarism Requirement
	plagiarismRequirement();

	return 0;
}

//*****************
//Function name: enterArrayData
//Purpose: allows the user to enter data into the array
//List of parameters: int *myArr
//Returns:
//Return type: void
//*****************
void enterArrayData(int *myArr){
	for (int i = 0; i < ARR_SIZE; i++){
		cout << "Enter an integer: ";
		cin >> *(myArr + i);
	}
}
//*****************
//Function name: outputArrayData
//Purpose: outputs the array elements
//List of parameters: int *myArr
//Returns:
//Return type: void
//*****************
void outputArrayData(int *myArr){
	cout << "The elements of the array: " << endl;
	for (int i = 0; i < ARR_SIZE; i++){
		cout << *(myArr + i) << ' ';
	}
	cout << endl;
}

//*****************
//Function name: sumArray
//Purpose: outputs the sum of the array elements
//List of parameters: int *myArr
//Returns:
//Return type: void
//*****************
void sumArray(int *myArr){
	int sum = 0;

	cout << "The sum of the elements of the array: " << endl;
	for (int i = 0; i < ARR_SIZE; i++){
		sum += *(myArr + i);
	}
	cout << sum << endl;
}

//*****************
//Function name: reverseArrayData
//Purpose: takes an array as an argument and then reverses the elements
//List of parameters: int *myArr
//Returns:
//Return type: void
//*****************
int* reverseArrayData(int original[ARR_SIZE]){
	static int reversed[ARR_SIZE];
	int temp;

	//reverses the elements of the original array and populates a reversed array
	for(int i = 0; i <= (ARR_SIZE / 2); i++){
		temp = original[i];
		reversed[i] = original[ARR_SIZE - 1 - i];
		reversed[ARR_SIZE - 1 - i] = temp;
	}

	//returns the pointer to the reversed array
	return reversed;
}

//*****************
//Function name: plagiarismRequirement
//Purpose: outputs Plagiarism Requirement
//List of parameters:
//Returns:
//Return type: void
//*****************
void plagiarismRequirement(){
  cout << endl;
  cout << "I attest that this code is my original programming work, and that I received" << endl;
  cout << "no help creating it. I attest that I did not copy this code or any portion of this" << endl;
  cout << "code from any source." << endl;
}
