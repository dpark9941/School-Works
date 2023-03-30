//============================================================================
// Name        : Ch8 Programming quiz part2.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : sorts the name of presidents alphabetically
//============================================================================

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;

//function prototypes
void sortVector(vector<string>&);
void swap(string&, string&);
void writeToFile(vector<string>);

int main(){
	ifstream inputFile;
	inputFile.open("presidents.txt");
	if(!inputFile){
		cout << "ERROR! The file doesn't exist" << endl;
		cout << "Program ending..." << endl;
		return 0;
	}

	cout << "This program sorts the name of presidents alphabetically" << endl;
	vector<string> president;
	string name; //holds the name of a president

	//inputs the names into the vector
	cout << "Reading the names from the file..." << endl;
	while (getline(inputFile, name)){
		president.push_back(name);
	}
	cout << "Done." << endl;
	inputFile.close();

	cout << "Sorting the names..." << endl;
	sortVector(president);
	cout << "Done." << endl;

	cout << "Writing to file..." << endl;
	writeToFile(president);
	cout << "Done." << endl;
	return 0;
}

//=======================================================
//Function name: sortVector
//Purpose: sorts vectors
//List of parameters: a vector
//Return type: void
//Returns:
//=======================================================
void sortVector(vector<string> &president){
	for (int maxElement = president.size() - 1; maxElement > 0; maxElement--){
		for (int index = 0; index < maxElement; index++){
			if (president[index] > president[index + 1]){
				swap(president[index], president[index + 1]);
			}
		}
	}
}

//=======================================================
//Function name: swap
//Purpose: swaps the order of elements of vector
//List of parameters: two elements of a vector
//Return type: void
//Returns:
//=======================================================
void swap(string &a, string &b){
	string temp = a;
	a = b;
	b = temp;
}

//=======================================================
//Function name: writeToFile
//Purpose: writes the elements of vector to a file
//List of parameters: a string vector
//Return type: void
//Returns:
//=======================================================
void writeToFile(vector<string> president){

	ofstream outputFile;
	outputFile.open("presidents_sorted.txt");
	for(int i = 0; i < president.size(); i++){
		outputFile << president[i] << endl;
	}
	outputFile.close();
}
