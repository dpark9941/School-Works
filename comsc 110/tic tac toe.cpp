//============================================================================
// Name        : tic tac toe.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : tic tac toe!
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;
const int SIZE = 3;

char welcome(char);
int displayTTT(char[SIZE*SIZE]);
void mark(char [SIZE], int);
void generateThrow(char[SIZE][SIZE]);
void convertArr(char[SIZE*SIZE], char[SIZE][SIZE]);
void convertBack(char[SIZE*SIZE], char[SIZE][SIZE]);
void checkRow(char[SIZE][SIZE]);
void checkCol(char[SIZE][SIZE]);
void checkDiag(char[SIZE][SIZE]);


int main(){
	char again; //repeats the whole program
	//do{
		char ox; //first or second
		char TTT[SIZE*SIZE];
		char TTT2[SIZE][SIZE];
		int choice;
		//assigns initial value from 1 to 9
		char value = '0';
		for (int i = 0; i < SIZE*SIZE; i++){
			value++;
			TTT[i] = value;
		}

		welcome(ox);

		while(1){
		choice = displayTTT(TTT);
		mark(TTT, choice);
		convertArr(TTT, TTT2);
		generateThrow(TTT2);
		convertBack(TTT, TTT2);
		}




		cout << "Another game? (Y/N): ";
		cin >> again;
		while (tolower(again) != 'y' && tolower(again) != 'n'){ //input validation
			cout << "ERROR! Only Y/N: ";
			cin >> again;
		}
	//} while (tolower(again) == 'y');

	cout << "Program ending... Have a nice day" << endl;
	return 0;
}

//=======================================================
//Function name: welcome
//Purpose: shows game directions
//List of parameters: char ox
//Return type: char
//Returns: ox
//=======================================================
char welcome(char ox){
	cout << "======TIC TAC TOE!======" << endl;
	cout << "Press X to start first or O to start second: ";
	cin >> ox;
	return ox;
}

//=======================================================
//Function name: displayTTT
//Purpose: shows game progress
//List of parameters: int TTT[SIZE]
//Return type: void
//Returns:
//=======================================================
int displayTTT(char TTT[SIZE*SIZE]){
	for (int i = 0; i < SIZE*SIZE; i++){
		cout << TTT[i] << ' ';
		if ((i+1) % 3 == 0){
			cout << endl;
		}
	}

	int choice;
	cout << "Your choice: ";
	cin >> choice;
	return choice;
}

//=======================================================
//Function name: mark
//Purpose: marks user's throw
//List of parameters:
//Return type: char
//Returns: ox
//=======================================================
void mark(char TTT[SIZE], int choice){
	TTT[choice-1] = 'X';
}

//=======================================================
//Function name: generateThrow
//Purpose: generate computer's throw
//List of parameters: int TTT[SIZE*SIZE]
//Return type: void
//Returns:
//=======================================================
void generateThrow(char TTT2[SIZE][SIZE]){

	checkRow(TTT2);
	checkCol(TTT2);
	checkDiag(TTT2);

}

//=======================================================
//Function name: checkRow
//Purpose: generate computer's throw
//List of parameters: int TTT[SIZE*SIZE]
//Return type: void
//Returns:
//=======================================================
void checkRow(char TTT2[SIZE][SIZE]){
	int counter = 0;
	for (int r = 0; r < SIZE; r++){
		for (int c = 0; c < SIZE; c++){
			if (TTT2[r][c] == 'X'){
				counter++;
			}
		}
		for (int c = 0; c < SIZE; c++){
			if (counter == 2 && !isupper(TTT2[r][c])){ //if the element is empty
				TTT2[r][c] = 'O';
			}
		}
	}
}

//=======================================================
//Function name: checkCol
//Purpose: generate computer's throw
//List of parameters: int TTT[SIZE*SIZE]
//Return type: void
//Returns:
//=======================================================
void checkCol(char TTT2[SIZE][SIZE]){
	int counter = 0;
	for (int c = 0; c < SIZE; c++){
		for (int r = 0; r < SIZE; r++){
			if (TTT2[r][c] == 'X'){
				counter++;
			}
		}
		for (int r = 0; r < SIZE; r++){
			if (counter == 2 && !isupper(TTT2[r][c])){ //if the element is empty
				TTT2[r][c] = 'O';
			}
		}
	}
}

//=======================================================
//Function name: checkDiag
//Purpose: generate computer's throw
//List of parameters: int TTT[SIZE*SIZE]
//Return type: void
//Returns:
//=======================================================
void checkDiag(char TTT2[SIZE][SIZE]){
	int counter = 0;
	//left top to right bottom
	for (int i = 0; i < SIZE; i++){
		if (TTT2[i][i] == 'X'){
			counter++;
		}
	}
	for (int i = 0; i < SIZE; i++){
		if (counter == 2 && !isupper(TTT2[i][i])){ //if the element is empty
			TTT2[i][i] = 'O';
		}
	}

	//right top to left bottom
	for (int i = 0; i < SIZE; i++){
		if (TTT2[i][SIZE-i] == 'X'){
			counter++;
		}
	}
	for (int i = 0; i < SIZE; i++){
		if (counter == 2 && !isupper(TTT2[i][SIZE-i])){ //if the element is empty
			TTT2[i][SIZE-i] = 'O';
		}
	}
}

//=======================================================
//Function name: convertArr
//Purpose: converts 1D array to 2D array
//List of parameters: two elements of each array
//Return type: void
//Returns:
//=======================================================
void convertArr(char arr1[SIZE*SIZE], char arr2[SIZE][SIZE]){
	int index = 0;
	for (int r = 0; r < SIZE; r++){
		for (int c = 0; c < SIZE; c++){
			arr2[r][c] = arr1[index];
			index++;
		}
	}
}

//=======================================================
//Function name: convertBack
//Purpose: converts 2D array to 1D array
//List of parameters: two elements of each array
//Return type: void
//Returns:
//=======================================================
void convertBack(char arr1[SIZE*SIZE], char arr2[SIZE][SIZE]){
	int index = 0;
	for (int r = 0; r < SIZE; r++){
		for (int c = 0; c < SIZE; c++){
			arr1[index] = arr2[r][c];
			index++;
		}
	}
}
