//*****************
//Program Name: Lab 11-2: STL Set
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: Write a program that reads an input file of words, and outputs the unique, sorted set of words using STL Set
//*****************

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
using namespace std;

const vector<string> CHECKFORTHESE = {"certain", "wait", "yardstick", "capitol", "cry"};

void plagiarismRequirement();

int main(){
	//creates an empty set
	set<string> set1;

	//opens the text file
	ifstream fin;
	fin.open("words.txt");
	if(!fin.good())
		cerr << "ERROR! Cannot open the file. Program ending." << endl;

	//reads the file into the set
	string tempWord;
	while(!fin.eof()){
		fin >> tempWord;
		set1.insert(tempWord);
	}

	//displays the elements of the set using RBFL
	cout << "Unique words in the list (using RBFL):" << endl;
	for(auto it : set1)
		cout << it << endl;
	cout << endl;

	//displays the elements of the set using iterator
	cout << "Unique words in the list (using iterator):" << endl;
	set<string>::iterator iter;
	for(iter = set1.begin(); iter != set1.end(); iter++)
		cout << *iter << endl;
	cout << endl;

	//checks if there are certain words in the set
	cout << "Checking for specific values:" << endl;
	for(int i = 0; i < CHECKFORTHESE.size(); i++){
		bool isFound = false;
		for(auto it : set1)
			if(it == CHECKFORTHESE.at(i))
				isFound = true;
		cout << '\t' << CHECKFORTHESE.at(i) << (isFound ? ": found" : ": not found") << endl;
	}

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
