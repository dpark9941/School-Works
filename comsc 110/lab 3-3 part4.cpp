//============================================================================
// Name        : lab 3-3 part4.cpp
// Author      : Donggy Park
// IDE used    : Eclipse
// Description : This program converts five sentences into a paragraph
//============================================================================


#include <iostream>
#include <iomanip>
using namespace std;

int main() {

	string sentence1, sentence2, sentence3, sentence4, sentence5;
	string paragraph;

	cout << "Enter five sentences:" << endl;

	cout << "Sentence 1: ";
	getline (cin, sentence1);

	cout << "Sentence 2: ";
	getline (cin, sentence2);

	cout << "Sentence 3: ";
	getline (cin, sentence3);

	cout << "Sentence 4: ";
	getline (cin, sentence4);

	cout << "Sentence 5: ";
	getline (cin, sentence5);

	paragraph = sentence1 + " " + sentence2 + " " + sentence3 + " " + sentence4 + " " + sentence5;

	cout << "Here is your paragraph: " << paragraph;

	return 0;
}
