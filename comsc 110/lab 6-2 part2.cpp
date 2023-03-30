//============================================================================
// Name        : lab 6-2 part2.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : color guessing game!
//============================================================================

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAXR = 6; //max range of random numbers
const int MINR = 1; //min range of random numbers
int rounds = 10; //the number of rounds

//function prototypes
void welcome();
void displayMenu(int);
int getResponse();
bool compareGuess (int);
void result(int);

int main(){

	srand(time(0)); // seed value for rand()
	int guess; //user's guess
	int counter = 0; //counts the number of wins

	welcome();

	for (int i = 1; i <= rounds; i++)
	{
		displayMenu(i);
		guess = getResponse();
		if (compareGuess(guess))
			counter++;
	}
	result(counter);

	return 0;
}

//couts welcome message
void welcome(){
	cout << "**********COLOR GUESSING GAME**********" << endl;
	cout << "Guess a color and the computer will tell you if you're right!" << endl;
	cout << "We will be playing " << rounds << " rounds." << endl << endl;
}

//couts menu
void displayMenu(int round){

	cout << "\t> Round #" << round << "!" << endl;
	cout << "\t> Select: 1-RED 2-GREEN 3-BLUE 4-YELLOW 5-ORANGE 6-PURPLE --> ";
}

//gets the user's entry, inputvalidates them and returns the value
int getResponse(){

	int response;
	cin >> response;
	while (response < MINR || response > MAXR) //input validation
	{
		cout << "ERROR! Enter only " << MINR << " - " << MAXR;
		cin >> response;
	}

	return response;
}

//compares the user's entry with the computer's number
bool compareGuess (int color){

	int comGuess; // computer's random number
	comGuess = rand() % (MAXR-MINR+1) + MINR;

	if (color == comGuess)
	{
		cout << "\t> Correct!" << endl;
		return true;
	}

	else
	{
		cout << "\t> Wrong; the computer picked: ";
		if (comGuess == 1)
			cout << "RED" << endl;
		else if (comGuess == 2)
			cout << "GREEN" << endl;
		else if (comGuess == 3)
			cout << "BLUE" << endl;
		else if (comGuess == 4)
			cout << "YELLOW" << endl;
		else if (comGuess == 5)
			cout << "ORANGE" << endl;
		else if (comGuess == 6)
			cout << "PURPLE" << endl;
		return false;
	}
}

//outputs the result
void result(int wins){

	cout << setprecision(2) << fixed << showpoint << endl;
	cout << "\t> Game Results" << endl;
	cout << "\t> Rounds: 10" << endl;
	cout << "\t> Wins: " << wins << " (" << (wins/(double)rounds) * 100 << "%)" << endl;
}
