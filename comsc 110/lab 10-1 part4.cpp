//============================================================================
// Name        : lab 10-1 part4.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : converts a sentence that has been run together
//============================================================================

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

const int SIZE = 1000; //size of the char array that is large enough

int main(){
	char sentence[SIZE];
	int length;

	cout << "Enter a sentence like this: TheHillsAreAliveWithTheSoundOfMusic, and I will convert the sentence" << endl;
	cout << "Enter your sentence: ";
	cin.getline(sentence, SIZE);
	length = strlen(sentence);

	for (int i = 0; i < length; i++){
		if (i != 0 && isupper(sentence[i])){
			sentence[i] = tolower(sentence[i]);
			cout << ' ' << sentence[i];
		}
		else{
			cout << sentence[i];
		}
	}
	return 0;
}
