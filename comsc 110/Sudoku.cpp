//============================================================================
// Name        : Sudoku.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : Sudoku generator
//============================================================================

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

const int W1 = 15; //field width for string literals
const int W2 = 3; //field width for numbers

//function prototypes
void welcome();
char getInput();
char generateP2toss();
int checkThrow(char, char);
void printStatistics(int, int, int, int);
void finalStatistics(int, int, int, double);

int main(){
	int sudoku[3][3][3];





	cout << "Program ending... Have a nice day!" << endl;

	return 0;
}

//displays welcome message and instructions
void welcome(){
	cout << "***ROCK PAPER SCISSORS GAME***" << endl << endl;
	cout << "Directions: enter one of these to throw down" << endl;
	cout << "r: rock" << endl;
	cout << "p: paper" << endl;
	cout << "s: scissors" << endl;
	cout << "q: quit and display statistics" << endl;
}

//gets user's throw
char getInput(){
	char input;
	cout << "\t> Rock Paper Scissors Throw! r/p/s/q > ";
	cin >> input;
	input = tolower(input);
	//input validation
	while (input != 'r' && input != 'p' && input != 's' && input != 'q'){
		cout << "\t> ERROR! Only r/p/s/q: ";
		cin >> input;
		input = tolower(input);
	}
	return input;
}

//generates computer's toss
char generateP2toss(){
	char p2; //computer's throw
	int toss = rand() % 3 + 1;
	if (toss == 1)
		p2 = 'r';
	if (toss == 2)
		p2 = 'p';
	if (toss == 3)
		p2 = 's';
	return p2;
}

//checks the throw of P1 and P2
int checkThrow(char p1, char p2){
	int result;
	if (p1 == p2) //tie
		result = 0;

	else if (p1 == 'r'){
		if (p2 == 'p')
			result = 2;
		if (p2 == 's')
			result = 1;
	}

	else if (p1 == 'p'){
		if (p2 == 's')
			result = 2;
		if (p2 == 'r')
			result = 1;
	}

	else if (p1 == 's'){
		if (p2 == 'r')
			result = 2;
		if (p2 == 'p')
			result = 1;
	}
	return result;
}

//prints the statistics for each throw
void printStatistics(int p1, int p2, int ties, int rounds){
	cout << "\t> Rounds: " << rounds << " | P1 wins: " << p1 << " | Computer wins: " << p2 << " | Ties: " << ties << endl;
}

//prints the final statistic for the game
void finalStatistics(int p1, int p2, int ties, double rounds){
	cout << setprecision(2) << fixed << showpoint << endl;
	cout << "************" << endl;
	cout << "GAME RESULTS" << endl;
	cout << "************" << endl;
	cout << setw(W1) << "Player wins: " << setw(W2) << p1 << " (" << (p1/rounds)*100 << "%)" << endl;
	cout << setw(W1) << "Computer wins: " << setw(W2) << p2 << " (" << (p2/rounds)*100 << "%)" << endl;
	cout << setw(W1) << "Ties: " << setw(W2) << ties << " (" << (ties/rounds)*100 << "%)" << endl;
	cout << setw(W1) << "Rounds: " << setw(W2) << (int)rounds << endl;

}
