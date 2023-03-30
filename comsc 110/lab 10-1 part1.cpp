//============================================================================
// Name        : lab 10-1 part1.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : determines if the user's sentence is a proper sentence
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

int main(){

	string sentence; //user input sentence
	cout << "This program determines if your sentence is a proper sentence" << endl;
	cout << "It determines if:" << endl;
	cout << "Sentence starts with a capital letter" << endl;
	cout << "Sentence ends with either a period or a question mark" << endl;
	cout << "Please enter your sentence: ";
	getline(cin, sentence);

	if (!isupper(sentence[0]))
		cout << "Your sentence doesn't start with a capital letter." << endl;
	if (!ispunct(sentence[sentence.length()-1]))
		cout << "Your sentence dosen't end with punctuation" << endl;
	if (isupper(sentence[0]) && ispunct(sentence[sentence.length()-1]))
		cout << "Your sentence is perfect!" << endl;

	return 0;
}
