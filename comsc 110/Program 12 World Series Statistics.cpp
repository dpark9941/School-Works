//============================================================================
// Name        : Program 12.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : shows statistics about World Series
//============================================================================

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int W1 = 2; //number field width
const int W2 = 25; //string field width

int main(){

	cout << "Loading..." << endl;
	char again; //allows user to look up another team
	int counter = 0; //counts the number of teams
	string name; //holds a certain team's name
	int choice; //holds the user's choice of team
	ifstream inteams;
	ifstream inwinners;
	inteams.open("teams.txt");
	if (!inteams){
		cout << "Error! The file doesn't exist." << endl;
		cout << "Program ending..." << endl;
		return 0;
	}
	//counts the number of team names
	while (getline(inteams, name))
		counter++;
	inteams.close();

	//writes team names into the array
	inteams.open("teams.txt");
	string teams[counter]; //holds the team names
	int wins[counter] = {0}; //holds the number of wins of a certain team

	for (int i = 0; i < counter; i++){
		getline(inteams, name);
		teams[i] = name;
	}
	inteams.close();

	inwinners.open("winners.txt");
	if (!inwinners){
		cout << "Error! The file doesn't exist." << endl;
		cout << "Program ending..." << endl;
		return 0;
	}
	//counts the number of wins of each team
	while (getline(inwinners, name)){
		for (int i = 0; i < counter; i++){
			if (teams[i] == name){
				wins[i]++;
			}
		}
	}
	inwinners.close();

	//displays the menu
	do{
		cout << "Enter one of the following teams to look up; press:" << endl;
		for (int i = 0; i < counter; i++){
			cout << right << setw(W1) << i+1 << " for " << left << setw(W2) << teams[i];
			if ((i+1) % 3 == 0)
				cout << endl;
		}
		cout << endl << "Your choice? --> ";
		cin >> choice;
		while (choice < 1 || choice > counter){
			cout << "ERROR! Only enter 1 - " << counter << endl;
			cout << "Please reenter: ";
			cin >> choice;
		}
		cout << teams[choice-1] << " have won the World Series " << wins[choice-1] << " time(s)" << endl;
		cout << "Would you like to look up another team? (Y)es or (N)o: ";
		cin >> again;
		again = tolower(again);
		while (again != 'y' && again != 'n'){
			cout << "Only y or n: ";
			cin >> again;
			again = tolower(again);
		}
	} while (again == 'y');

	cout << "Program ending... Have a nice day" << endl;
	return 0;
}
