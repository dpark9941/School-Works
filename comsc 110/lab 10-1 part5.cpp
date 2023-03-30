//============================================================================
// Name        : lab 10-1 part5.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : generates 1000 random characters and counts them
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 1000; //size of the char array
const int ALPHA = 26; //the number of alphabets
const int MAX = 90; //Z
const int MIN = 65; //A

int main(){
	srand(time(0));
	char alphabets[ALPHA]; //holds 26 alphabets
	char randChars[SIZE]; //holds 1000 random characters
	int counters[ALPHA] = {0}; //counts the number of each chars generated

	//assigns A-Z in the array
	for (int i = MIN; i <= MAX; i++){
		alphabets[i-65] = i;
	}

	//generates 100 rand chars
	for (int i = 0; i < SIZE; i++){
		randChars[i] = rand() % (MAX - MIN + 1) + MIN;
	}

	//counts the chars
	for (int i = 0; i < ALPHA; i++){
		for (int j = 0; j < SIZE; j++){
			if (alphabets[i] == randChars[j]){
				counters[i]++;
			}
		}
	}

	//displays the result
	for (int i = 0; i < ALPHA; i++){
		cout << alphabets[i] << ": " << counters[i] << endl;
	}

	return 0;
}
