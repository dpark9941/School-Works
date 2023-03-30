//*****************
//Program Name: Lab 11-4: STL Map
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: Write a flash card program using STL Map
//*****************

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

void plagiarismRequirement();

const int W1 = 20;

int main(){
	//creates an empty map
	map<string, string> map1;
	//created for quiz
	vector<string> states;

	//opens the text file
	ifstream fin;
	fin.open("capitols-1.txt");
	if(!fin.good())
		cerr << "ERROR! Cannot open the file. Program ending." << endl;

	//reads the file into the set
	string capitol, state;
	while(!fin.eof()){
		getline(fin, capitol);
		getline(fin, state);
		map1.emplace(state, capitol);
		states.push_back(state);
	}

	cout << "I'm going to ask you for the capitals of 5 states." << endl << endl;
	cout << left << setw(W1) << "State" << "Capitol" << endl << endl;
	//displays the contents of the map
	for(auto val : map1)
		cout << setw(W1) << val.first << val.second << endl;
	cout << endl;

	//holds the index of the state for the quiz problem
	int quizProblem = 0;
	//holds the users answer for the problem
	string answer;
	//counts the number of problems that the user got right
	int correct = 0;
	//the number of the problems of the quiz
	int numProblem = 5;
	srand(time(0));
	cout << "QUIZ TIME!" << endl << endl;
	for(int i = 0; i < numProblem; i++){
		//randomly chooses a state from the map
		quizProblem = rand() % 50;
		cout << "What is the capital of " << states.at(quizProblem) << "?: ";
		getline(cin, answer);
		if(states.at(quizProblem) == answer){
			cout << "Correct!" << endl;
			correct++;
		}
		else
			cout << "Sorry, that's incorrect; the correct answer is " << map1.at(states.at(quizProblem)) << endl;
		cout << endl;
	}

	cout << "Quiz Statistics:" << endl;
	cout << "Correct answers: " << correct << endl;
	cout << "Incorrect answers: " << numProblem - correct << endl;

	plagiarismRequirement();

	return 0;
}

//*****************
//Function name: plagiarismRequirement
//Purpose: outputs Plagiarism Requirement
//List of parameters:
//Returns:
//Return type: void
//*****************
void plagiarismRequirement(){
  cout << endl;
  cout << "I attest that this code is my original programming work, and that I received" << endl;
  cout << "no help creating it. I attest that I did not copy this code or any portion of this" << endl;
  cout << "code from any source." << endl;
}
