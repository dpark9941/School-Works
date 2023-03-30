#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;

int main() {

	ifstream infile;
	string sentence;
	string userInput;
	int sentenceNum = 0;
	int correct = 0;
	int wrongChars;
	double accuracy;

	infile.open("asdf.txt");
	if(!infile){
		cout << "ERROR! The file doesn't exist" << endl;
		cout << "Program ending..." << endl;
		return 0;
	}

	cout << "Taja practice" << endl;
	cout << endl;

	while(getline(infile, sentence)){
		sentenceNum++;
		cout << sentence << endl;
		getline(cin, userInput);
		if (sentence == userInput){
			correct++;
		}
	}

	cout << endl << "Result" << endl;
	cout << "Sentences typed: " << sentenceNum << endl;
	cout << "Correct sentences: " << correct << endl;



	return 0;
}
