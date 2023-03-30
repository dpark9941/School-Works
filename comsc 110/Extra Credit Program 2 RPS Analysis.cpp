//============================================================================
// Name        : Extra Credit Program 2 RPS Analysis.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description :
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

const double THROWS = 1000000;
const int W1 = 15; //field width for string literals
const int W2 = 3; //field width for numbers

//function prototypes
void welcome();
void generateToss(int&);
int checkThrow(int, int);
void strat1(int&, int&, int&);
void strat2(int&, int&, int&);
void strat3(int&, int&, int&);
void strat4(int&, int&, int&);
void strat5(int&, int&, int&);
void strat6(int&, int&, int&);
void strat7(int&, int&, int&);
void strat8(int&, int&, int&);
void finalStatistics();

/* 1 represents rock, 2 represents paper and 3 represents scissors */

int main(){
	int statistics[3][8]; //holds the result of each strategy
	int tie, win, loss; //user result counter
	srand(time(0));
	welcome();
	strat1(tie, win, loss);
	for (int state = 0; state < 3; state++){
		if (state == 0){
			for (int t = 0; t < tie; t++){
				statistics[state][0]++;
			}
		}
		if (state == 1){
			for (int w = 0; w < win; w++){
				statistics[state][0]++;
			}
		}
		if (state == 2){
			for (int l = 0; l < loss; l++){
				statistics[state][0]++;
			}
		}
	}

	strat2(tie, win, loss);
	for (int state = 0; state < 3; state++){
		if (state == 0){
			for (int t = 0; t < tie; t++){
				statistics[state][1]++;
			}
		}
		if (state == 1){
			for (int w = 0; w < win; w++){
				statistics[state][1]++;
			}
		}
		if (state == 2){
			for (int l = 0; l < loss; l++){
				statistics[state][1]++;
			}
		}
	}




	cout << "Program ending... Have a nice day!" << endl;

	return 0;
}
//=======================================================
//Function name: welcome
//Purpose: displays welcome message and instructions
//List of parameters:
//Return type:
//Returns:
//=======================================================
void welcome(){
	cout << "***ROCK PAPER SCISSORS GAME***" << endl << endl;
	cout << "This program produces a statistical analysis of the rock-paper-scissors game when the user uses different strategies for their throw:" << endl;
	cout << "1. Random" << endl;
	cout << "2. Play rock until a loss; then paper; then scissors; repeat" << endl;
	cout << "3. Same as #2 just in this order: rock, scissors, paper" << endl;
	cout << "4. Play rock until a tie or loss; then paper; then scissors; repeat" << endl;
	cout << "5. Same as #4 just with this order: rock, scissors, paper" << endl;
	cout << "6. Throwing just rock." << endl;
	cout << "7. Throwing just paper." << endl;
	cout << "8. Throwing just scissors." << endl;
	cout << "This will simulate " << THROWS << " throws for each strategy and display the results." << endl;
	cout << "In general \"p1\" represents you and \"p2\" represents the computer." << endl;
	cout << "Press ENTER to start the simulations." << endl;
	cin.get();
}

//=======================================================
//Function name: generateToss
//Purpose: generates user's throw and computer's throw
//List of parameters:
//Return type: int
//Returns: rps
//=======================================================
void generateToss(int &rps){
	rps = rand() % 3 + 1;
	/*if (toss == 1)
		toss = 'r';
	if (toss == 2)
		toss = 'p';
	if (toss == 3)
		toss = 's';*/
}

//=======================================================
//Function name: checkThrow
//Purpose: compares user's throw and computer's throw
//List of parameters: int p1, int p2
//Return type: int
//Returns: result
//=======================================================
int checkThrow(int p1, int p2){
	int result;
	if (p1 == p2) //tie
		result = 0;

	else if (p1 == 1){
		if (p2 == 2)
			result = 2; //rock vs paper
		if (p2 == 3)
			result = 1; //rock vs scissors
	}

	else if (p1 == 2){
		if (p2 == 3)
			result = 2; //paper vs scissors
		if (p2 == 1)
			result = 1; //paper vs rock
	}

	else if (p1 == 3){
		if (p2 == 1)
			result = 2; //scissors vs rock
		if (p2 == 2)
			result = 1; //scissors vs paper
	}
	return result;
}

//=======================================================
//Function name: displayResults
//Purpose: display results
//List of parameters:
//Return type: void
//Returns:
//=======================================================
void displayResults(){

}

//=======================================================
//Function name: strat1
//Purpose: random throw vs random throw
//List of parameters: int &tie, int &win, int &loss
//Return type: void
//Returns:
//=======================================================
void strat1(int &tie, int &win, int &loss){
	int user, computer; //holds user and computer's throw
	int result; //result of each game
	tie = 0, win = 0, loss = 0; //user result counter
	for (int i = 0; i < THROWS; i++){
		generateToss(user);
		generateToss(computer);
		result = checkThrow(user, computer);
		if (result == 0) //tie
			tie++;
		if (result == 1) //p1 wins
			win++;
		if (result == 2) //p1 loses
			loss++;
	}
}

//=======================================================
//Function name: strat2
//Purpose: R -> P -> S (repeat until lose or tie) vs random throw
//List of parameters: int &tie, int &win, int &loss
//Return type: void
//Returns:
//=======================================================
void strat2(int &tie, int &win, int &loss){
	int user, computer; //holds user and computer's throw
	int result; //result of each game
	int toss = 1; //user's throw
	tie = 0, win = 0, loss = 0; //user result counter
	for (int i = 0; i < THROWS; i++){
		user = toss; //rock -> paper -> scissors
		generateToss(computer);
		result = checkThrow(user, computer);
		if (result == 0){ //tie
			tie++;
			toss++;
		}
		if (result == 1) //p1 wins
			win++;
		if (result == 2){ //p1 loses
			loss++;
			toss++;
		}

		if (toss == 3 && result != 1) //repeats r -> p -> s
			toss = 1;
	}
}

void strat3(int &tie, int &win, int &loss){

}

void strat4(int &tie, int &win, int &loss){

}

void strat5(int &tie, int &win, int &loss){

}

void strat6(int &tie, int &win, int &loss){

}

void strat7(int &tie, int &win, int &loss){

}

void strat8(int &tie, int &win, int &loss){

}
