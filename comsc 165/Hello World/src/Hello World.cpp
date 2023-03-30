#include <iostream> //#include "someLib.hpp" --> third-party library
#include <iomanip> //output formatting
#include <cstdlib> //srand() rand()
#include <ctime> //time()
using namespace std;

const int W1 = 8; //field width for answer keys

void practiceRand();
void generateWorksheet();

int main(){
	srand(time(0));
	generateWorksheet();
	return 0;
}


void practiceRand(){
	cout << rand() % 5 + 1 << endl;
	cout << (rand() % 9 + 1) * 2 << endl;
	cout << rand() % 2 + 1 << endl;
	cout << rand() % 100 + 1 << endl;
	cout << (rand() % 5 + 1) * 2 + 1 << endl;
	cout << rand() % 10 << endl;
	cout << rand() % 3 - 1 << endl;
	cout << 6 + (rand() % 5) * 4 << endl;
	cout << rand() % 15 - 3 << endl;
}

void generateWorksheet(){
	int questions = 10; // the number of questions
	int numerators[questions];
	int denominators[questions];

	//assigns random numbers to the array
	for (int i = 0; i < questions; i++){
		numerators[i] = rand() % 100 + 1;
		denominators[i] = rand() % 100 + 1;
	}

	//outputs the questions
	for (int i = 0; i < questions; i++){
		cout << i+1 << ") What is " << numerators[i] << " % " << denominators[i] << "?" << endl;
	}
	cout << endl;

	//outputs the answers
	cout << "ANSWER KEY" << endl;
	for (int i = 0; i < questions; i++){
		cout << i+1 << ")\t" << numerators[i] % denominators[i] << endl;
	}
}
