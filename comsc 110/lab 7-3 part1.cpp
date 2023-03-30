//============================================================================
// Name        : lab 7-3 part1.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : doubles the elements of an array and displays them
//============================================================================

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

const int ROWS = 10; //size of the rows of the array
const int COLS = 10; //size of the columns of the array
const int MAX = 100; //max range of rand()
const int MIN = 1; //min range of rand()
const int W1 = 3;

//function prototypes
void doubleArr(int [][COLS], int);

int main(){
	srand(time(0));
	int arr [ROWS][COLS];
	cout << "=====2D Array Processing Program===== " << endl << endl;
	cout << "This program fills an array with random numbers and then doubles them" << endl;

	//fills the array with random numbers
	cout << "Generating random numbers..." << endl;
	for (int r = 0; r < ROWS; r++){
		for (int c = 0; c < COLS; c++){
			arr[r][c] = rand() % (MAX - MIN + 1) + MIN;
		}
	}
	cout << "Done." << endl << endl;

	//prints out the undoubled array
	for (int r = 0; r < ROWS; r++){
		for (int c = 0; c < COLS; c++){
			cout << setw(W1) << arr[r][c] << " ";
		}
		cout << endl;
	}

	cout << endl << "Doubling the array..." << endl;
	doubleArr(arr,ROWS);
	cout << "Done." << endl <<endl;

	//prints out the doubled array
	for (int r = 0; r < ROWS; r++){
		for (int c = 0; c < COLS; c++){
			cout << setw(W1) << arr[r][c] << " ";
		}
		cout << endl;
	}

	return 0;
}

//doubles the elements of an array
void doubleArr(int arr[][COLS], int rows){
	for (int r = 0; r < rows; r++){
		for (int c = 0; c < COLS; c++){
			arr[r][c] *= 2;
		}
	}
}

