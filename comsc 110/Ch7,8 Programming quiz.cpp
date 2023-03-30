//============================================================================
// Name        : Ch8 Programming quiz part1.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : sorts 2-D array
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

const int ROWS = 10; //the size of the rows of array
const int COLS = 10; //the size of the cols of array
const int SIZE = ROWS*COLS; //the size of the 1-D array
const int W1 = 4; //field width for numbers
const int MAX = 999; //max random number
const int MIN = 1; //min random number

//function prototypes
void sortArray(int[]);
void swap(int&, int&);
void convertArr(int[], int[][COLS]);
void convertBack(int[], int[][COLS]);
void displayArr(int [][COLS]);

int main(){

	srand(time(0));
	int arr1[SIZE];
	int arr2[ROWS][COLS];
	//fills the 2D array w/ random numbers
	for (int r = 0; r < ROWS; r++){
		for (int c = 0; c < COLS; c++){
			arr2[r][c] = rand() % (MAX - MIN + 1) +MIN;
		}
	}
	cout << "This program sorts 2D array" << endl;

	cout << "Before sorting:" << endl << endl;
	displayArr(arr2);

	cout << "Sorting the array..." << endl;
	//converts 2D array to 1D array
	convertArr(arr1, arr2);
	//sorts the array
	sortArray(arr1);
	//converts 1D array to 2D array
	convertBack(arr1, arr2);
	cout << "Done." << endl;


	cout << "After sorting:" << endl << endl;
	displayArr(arr2);

	return 0;
}

//=======================================================
//Function name: sortArray
//Purpose: sorts arrays
//List of parameters: arr1{SIZE]
//Return type: void
//Returns:
//=======================================================
void sortArray(int arr1[SIZE]){
	for (int maxElement = SIZE - 1; maxElement > 0; maxElement--){
		for (int index = 0; index < maxElement; index++){
			if (arr1[index] > arr1[index + 1]){
				swap(arr1[index], arr1[index + 1]);
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
void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

//=======================================================
//Function name: convertArr
//Purpose: converts 2D array to 1D array
//List of parameters: two elements of each array
//Return type: void
//Returns:
//=======================================================
void convertArr(int arr1[SIZE], int arr2[ROWS][COLS]){
	int index = 0;
	for (int r = 0; r < ROWS; r++){
		for (int c = 0; c < COLS; c++){
			arr1[index] = arr2[r][c];
			index++;
		}
	}
}

//=======================================================
//Function name: convertBack
//Purpose: converts 1D array to 2D array
//List of parameters: two elements of each array
//Return type: void
//Returns:
//=======================================================
void convertBack(int arr1[SIZE], int arr2[ROWS][COLS]){
	int index = 0;
	for (int r = 0; r < ROWS; r++){
		for (int c = 0; c < COLS; c++){
			arr2[r][c] = arr1[index];
			index++;
		}
	}
}

//=======================================================
//Function name: displayArr
//Purpose: displays the elements of array
//List of parameters: a 2D array
//Return type: void
//Returns:
//=======================================================
void displayArr(int arr2[ROWS][COLS]){
	for (int r = 0; r < ROWS; r++){
		for (int c = 0; c < COLS; c++){
			cout << setw(W1) << arr2[r][c];
		}
		cout << endl;
	}
}
