//============================================================================
// Name        : Program 11.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : generates 2 arrays and fills them w/ randoms and then adds them
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

const int W1 = 17; //field width for string literals
const int W2 = 5; //field width for numbers
const int ROWS = 10; //size of rows of the array
const int COLS = 10; //size of cols of the array
const int MAX = 1000; //max range of rand()
const int MIN = 1; //min range of rand()

//function prototypes
void populateArray(int [ROWS][COLS]);
void addArrays(int [ROWS][COLS], int [ROWS][COLS], int [ROWS][COLS]);
int findLargest(int [ROWS][COLS]);
int findSmallest(int [ROWS][COLS]);
void printArray(int [ROWS][COLS], int [ROWS][COLS], int [ROWS][COLS]);

int main(){
	srand(time(0));
	int arr1 [ROWS][COLS];
	int arr2 [ROWS][COLS];
	int arr3 [ROWS][COLS];

	populateArray(arr1);
	populateArray(arr2);
	addArrays(arr1, arr2, arr3);
	printArray(arr1, arr2, arr3);

	cout << "Program ending..." << endl;
	return 0;
}

//fills array with 100 random numbers
void populateArray(int arr[ROWS][COLS]){
	for (int r = 0; r < ROWS; r++){
		for (int c = 0; c < COLS; c++){
			arr[r][c] = rand() % (MAX - MIN + 1) + MIN;
		}
	}
}

//add arr1 and arr2 and assigns the total to arr3
void addArrays(int arr1[ROWS][COLS], int arr2[ROWS][COLS], int arr3[ROWS][COLS]){
	for (int r = 0; r < ROWS; r++){
		for (int c = 0; c < COLS; c++){
			arr3[r][c] = arr1[r][c] + arr2[r][c];
		}
	}
}

//finds the largest number in the array
int findLargest(int arr[ROWS][COLS]){
	int large = MIN - 1;
	for (int r = 0; r < ROWS; r++){
		for (int c = 0; c < COLS; c++){
			if (arr[r][c] > large)
			large = arr[r][c];
		}
	}
	return large;
}

//finds the smallest number in the array
int findSmallest(int arr[ROWS][COLS]){
	int small = MAX + 1;
	for (int r = 0; r < ROWS; r++){
		for (int c = 0; c < COLS; c++){
			if (arr[r][c] < small)
				small = arr[r][c];
		}
	}
	return small;
}

//prints the arrays
void printArray(int arr1[ROWS][COLS], int arr2[ROWS][COLS], int arr3[ROWS][COLS]){
	cout << "Array 1:" << endl;
	for (int r = 0; r < ROWS; r++){
		for (int c = 0; c < COLS; c++){
			cout << setw(W2) << arr1[r][c];
		}
		cout << endl;
	}
	cout << endl;

	cout << "Array 2:" << endl;
	for (int r = 0; r < ROWS; r++){
		for (int c = 0; c < COLS; c++){
			cout << setw(W2) << arr2[r][c];
		}
		cout << endl;
	}
	cout << endl;

	cout << "Array 3:" << endl;
	for (int r = 0; r < ROWS; r++){
		for (int c = 0; c < COLS; c++){
			cout << setw(W2) << arr3[r][c];
		}
		cout << endl;
	}
	cout << endl;

	cout << setw(W1) << "Array1 largest: " << setw(W2) << findLargest(arr1) << endl;
	cout << setw(W1) << "Array1 smallest: " << setw(W2) << findSmallest(arr1) << endl;
	cout << setw(W1) << "Array2 largest: " << setw(W2) << findLargest(arr2) << endl;
	cout << setw(W1) << "Array2 smallest: " << setw(W2) << findSmallest(arr2) << endl;
	cout << setw(W1) << "Array3 largest: " << setw(W2) << findLargest(arr3) << endl;
	cout << setw(W1) << "Array3 smallest: " << setw(W2) << findSmallest(arr3) << endl;
	cout << endl;
}
