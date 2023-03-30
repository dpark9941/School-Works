//============================================================================
// Name        : Extra Credit Program 3.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : Magic square generator
//============================================================================

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 4; //size of the magic square (SIZE*SIZE)
const int MAX = 2; //biggest possible number
const int MIN = 0; //smallest possible number
const int MAGICNUMBER = 4; //the sum of each row, column and diagonal

void makeSquare(int[SIZE][SIZE]);
bool testSquare(int[SIZE][SIZE]);
bool checkRow(int[SIZE][SIZE]);
bool checkCol(int[SIZE][SIZE]);
bool checkDiag(int[SIZE][SIZE]);

int main(){
	srand(time(0));
	int magicSquare[SIZE][SIZE];
	char again; //repeats the program

	do {
		double counter = 0;
		bool magic = false;

		cout << "Creating your magic square..." << endl;
		while(!magic){
			makeSquare(magicSquare);
			magic = testSquare(magicSquare);
			counter++;
		}

		cout << "It took " << counter << " times but here's your magic square:" << endl << endl;
		for (int r = 0; r < SIZE; r++){
			for (int c = 0; c < SIZE; c++){
				cout << magicSquare[r][c] << ' ';
			}
			cout << endl;
		}
		cout << endl;

		cout << "Generate another square? Y/N: ";
		cin >> again;
		again = tolower(again);
		while (again != 'y' && again != 'n'){
			cout << "\t> ERROR! Only y or n: ";
			cin >> again;
			again = tolower(again);
		}
		cout << endl;
	} while (again == 'y');


	cout << "Program ending... Have a nice day!" << endl;

	return 0;
}

//=======================================================
//Function name: makeSquare
//Purpose: generates random numbers
//List of parameters: int magicSquare[SIZE][SIZE]
//Return type: void
//Returns:
//=======================================================
void makeSquare(int magicSquare[SIZE][SIZE]){
	for (int r = 0; r < SIZE; r++){
		for (int c = 0; c < SIZE; c++){
			magicSquare[r][c] = rand() % (MAX - MIN + 1) + MIN;
		}
	}
}

//=======================================================
//Function name: testSquare
//Purpose: checks if the square is a magic square
//List of parameters: int magicSquare[SIZE][SIZE]
//Return type: bool
//Returns: magic
//=======================================================
bool testSquare(int magicSquare[SIZE][SIZE]){
	bool magic = false, row = false, col = false, diag = false;

	row = checkRow(magicSquare);
	col = checkCol(magicSquare);
	diag = checkDiag(magicSquare);

	if (row && col && diag){
		magic = true;
	}

	return magic;
}

//=======================================================
//Function name: checkRow
//Purpose: checks if the sum of each row equals MAGICNUMBER
//List of parameters: int magicSquare[SIZE][SIZE]
//Return type: bool
//Returns: magicRow
//=======================================================
bool checkRow(int magicSquare[SIZE][SIZE]){
	bool magicRow = true;
	int sum[SIZE]; //holds the sum of each row
	for (int r = 0; r < SIZE; r++){
		sum[r] = 0; //initialize the array with value of 0
	}

	for (int r = 0; r < SIZE; r++){
		for (int c = 0; c < SIZE; c++){
			sum[r] += magicSquare[r][c];
		}
	}

	for (int r = 0; r < SIZE; r++){
		if (sum[r] != MAGICNUMBER)
			magicRow = false;
	}

	return magicRow;
}

//=======================================================
//Function name: checkCol
//Purpose: checks if the sum of each column equals MAGICNUMBER
//List of parameters: int magicSquare[SIZE][SIZE]
//Return type: bool
//Returns: magicCol
//=======================================================
bool checkCol(int magicSquare[SIZE][SIZE]){
	bool magicCol = true;
	int sum[SIZE]; //holds the sum of each column
	for (int c = 0; c < SIZE; c++){
		sum[c] = 0; //initialize the array with value of 0
	}

	for (int c = 0; c < SIZE; c++){
		for (int r = 0; r < SIZE; r++){
			sum[c] += magicSquare[r][c];
		}
	}

	for (int c = 0; c < SIZE; c++){
		if (sum[c] != MAGICNUMBER)
			magicCol = false;
	}

	return magicCol;
}

//=======================================================
//Function name: checkDiag
//Purpose: checks if the sum of each diagonal equals MAGICNUMBER
//List of parameters: int magicSquare[SIZE][SIZE]
//Return type: bool
//Returns: magicDiag
//=======================================================
bool checkDiag(int magicSquare[SIZE][SIZE]){
	bool magicDiag = true;
	int sum[2] = {0,0}; //holds the sum of each diagonal

	//left top to right bottom
	for (int d = 0; d < SIZE; d++){
		sum[0] += magicSquare[d][d];
	}

	//right top to left bottom
	for (int d = 0; d < SIZE; d++){
		sum[1] += magicSquare[d][SIZE-d-1];
	}

	for (int d = 0; d < 2; d++){
		if (sum[d] != MAGICNUMBER){
			magicDiag = false;
		}
	}
	return magicDiag;
}
