//============================================================================
// Lab Name    : Drill: Tic-Tac-Toe
// Author      : Donggyu Park
// Date        : 02/26/2020
// Programming Environment : Win 10, Eclipse
//============================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int ROWS = 3;
const int COLS = 3;

int main() {

	int numWords;
	char searchChar;
	string word;
	vector<string> words;

	cout << "Please enter how many words you will ask me to look at: ";
	cin >> numWords;
	for (int i = 0; i < numWords; i++){
		cout << "Please enter the word you want me to parse: ";
		cin >> word;
		words.push_back(word);
	}
	cout << "Which character do you want me to look for: ";
	cin >> searchChar;


	return 0;
}

/* Tic Tac Toe
	char TTT[ROWS][COLS];
	char *pTTT = &TTT[0][0];
	char index = '0';
	int move;
	for (int i = 0; i < ROWS; i++){
		for(int j = 0; j < COLS; j++){
			index++;
			TTT[i][j] = index;
		}
	}

	cout << "Tic Tac Toe!!!" << endl;
	for (int i = 0; i < ROWS; i++){
		for(int j = 0; j < COLS; j++){
			cout << TTT[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "Press the number in the board where you would like to move: ";
	cin >> move;
	*(pTTT + move - 1) = 'X';

	for (int i = 0; i < ROWS; i++){
		for(int j = 0; j < COLS; j++){
			cout << TTT[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "Press the number in the board where you would like to move: ";
	cin >> move;
	*(pTTT + move - 1) = 'O';

	for (int i = 0; i < ROWS; i++){
		for(int j = 0; j < COLS; j++){
			cout << TTT[i][j] << ' ';
		}
		cout << endl;
	}
 */
