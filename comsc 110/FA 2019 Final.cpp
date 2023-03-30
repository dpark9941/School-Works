//============================================================================
// Name        : FA 2019 Final.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : Card flip game
//============================================================================

#include <iostream>
#include <iomanip>
#include <vector>
#include <cstring>
using namespace std;

struct Player {
		string name;
		int wins;
		int points;
		bool game;
		bool round;
		vector<char> visualWins; //visualization of player's wins
		vector<char> guess; //player's guess
};

const int WIN = 4; //if a player gets this points the player wins the game

void generatePlayer(Player [], int);
void cardFlips(vector<char>&);
void compareDeck(vector<char>, Player[], int, bool&);
void roundResult(vector<char>, Player [], int, int);
void gameResult(vector<char>, Player [], int, int);


int main(){
	srand(time(0));
	vector<char> cardFlipped; //card flipped
	bool game = false; //checks if any player has won the game

	int size; // the number of players
	cout << "How many players? (2 minimum, 5 max): ";
	cin >> size;
	while(size < 2 || size > 5){
		cout << "Only 2 - 5: ";
		cin >> size;
	}

	Player players[size];

	//initialize the array
	for (int i = 0; i < size; i++){
		string temp = "";
		temp += "p";
		temp += to_string(i+1);
		players[i].name = temp;
		players[i].wins = 0;
		players[i].points = 0;
		players[i].round = false;
		players[i].game = false;
	}

	do {

		cardFlips(cardFlipped);

		//iterates (size) times
		for (int i = 0; i < size; i++){
			generatePlayer(players, i);
		}

		for (int i = 0; i < size; i++){
			compareDeck(cardFlipped, players, i, game);
		}

	} while (!game);

	int round = cardFlipped.size();
	roundResult(cardFlipped, players, round, size);
	gameResult(cardFlipped, players, round, size);

	cout << "Program ending... Have a nice day" << endl;
	return 0;
}

//=======================================================
//Function name: generatePlayer
//Purpose: generates decks for players
//List of parameters: Player players[], int i
//Return type: void
//Returns:
//=======================================================
void generatePlayer(Player players[], int i){
	int card;
	card = rand() % 2;
	if (card == 1){
		players[i].guess.push_back('B');
	}

	if (card == 2){
		players[i].guess.push_back('R');
	}
}

//=======================================================
//Function name: cardFlips
//Purpose: generates decks card flips
//List of parameters: vector<char> &cardFlipped
//Return type: void
//Returns:
//=======================================================
void cardFlips(vector<char> &cardFlipped){
	int card;
	card = rand() % 2;
	if (card == 1){
		cardFlipped.push_back('B');
	}

	if (card == 2){
		cardFlipped.push_back('R');
	}
}

//=======================================================
//Function name: compareDeck
//Purpose: compares the player's guess with the cards flipped
//List of parameters: vector<char> cardFlipped, Player players[], int i, bool &game
//Return type: void
//Returns:
//=======================================================
void compareDeck(vector<char> cardFlipped, Player players[], int i, bool &game){
	int end = cardFlipped.size() - 1;
	//if the player's guess is right
	if (cardFlipped[end] == players[i].guess[end]){
		players[i].wins++;
		players[i].points++;
		players[i].round = true;
		players[i].visualWins.push_back('W');

	}

	//if the player's guess is wrong
	else{
		players[i].points--;
		players[i].round = false;
		players[i].visualWins.push_back('-');
	}

	//checks if any player has won the game
	if (players[i].points == WIN){
		game = true;
	}
}

//=======================================================
//Function name: roundResult
//Purpose: displays the result of each round
//List of parameters: vector<char> cardFlipped, Player players[], int round, int size
//Return type: void
//Returns:
//=======================================================
void roundResult(vector<char> cardFlipped, Player players[], int round, int size){
	for (int i = 0; i < round; i++){
		cout << "Round #" << round+1 << ": " << cardFlipped[round] << '\t';
		for(int p = 0; p < size; p++)
			cout << " | " << players[p].name << ' ' << (players[p].round ? "W" : "L") << " (" << players[p].points << ")";
	}
	cout << endl;
}

//=======================================================
//Function name: gameResult
//Purpose: displays the result of the entire game
//List of parameters: vector<char> cardFlipped, Player players[], int round, int size
//Return type: void
//Returns:
//=======================================================
void gameResult(vector<char> cardFlipped, Player players[], int round, int size){
	cout << "Flips: {";
	for (int i = 0; i < round; i++){
		cout << cardFlipped[round];
	}
	cout << "}" << endl;

	for (int i = 0; i < size; i++){
		cout << players[i].name << ": {";
		for (int val : players[i].guess){
			cout << val;
		}
		cout << "}" << endl;
		cout << "\t{";
		for (int val : players[i].visualWins){
			cout << val;
		}
		cout << "} (" << (double)(players[i].wins) / cardFlipped.size() << "%)" << endl;
	}
}
