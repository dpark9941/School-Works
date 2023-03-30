//*****************
//Program Name: Lab 13-1: STL::Set in STL::Map
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: Write a program that reads a story and generates a word index
//*****************

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
using namespace std;

void plagiarismRequirement();
void tolower(string &);
void toalpha(string &);

int main(){

	map<string, set<int>> index;
	stringstream ss;
	string line, tempWord;
	ifstream fin("story.txt");
	if(!fin.good()){
		cout << "Cannot open the file." << endl;
		cout << "Program ending" << endl;
		exit(0);
	}

	int lineNumber = 0;
	while(getline(fin, line)){
		lineNumber++;
		ss << line;
		while(ss >> tempWord){
			tolower(tempWord);
			toalpha(tempWord);
			if(index.count(tempWord))
				index.at(tempWord).insert({lineNumber});
			else
				index.emplace(tempWord, set<int> {lineNumber});
		}
		ss.clear();
	}

	cout << "WORD INDEX" << endl;
	for(auto it_map : index){
		cout << it_map.first << ": ";
		for(auto it_set : it_map.second)
			cout << it_set << ' ';
		cout << endl;
	}

	//housekeeping
	fin.close();

	plagiarismRequirement();

	return 0;
}

//converts all characters of the string to lowercase letters
void tolower(string &temp){
	for(auto &val : temp)
		val = tolower(val);
}

//removes all the punctuation from the string
void toalpha(string &temp){
	for(int i = 0; i < temp.size(); i++)
		if(ispunct(temp.at(i)) && temp.at(i) != '\'')
			temp.erase(i--, 1);
}
//*****************
//Function name: plagiarismRequirement
//Purpose: outputs plagiarism Requirement
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
