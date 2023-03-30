//*****************
//Program Name: Lab 6-1: An Array Class "Superstring"
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: Develop a class called "Superstring" that uses an internal array of strings
//*****************

#include "Superstring.h"
#include <iostream>
using namespace std;

void plagiarismRequirement();

int main(){
	//creates an Superstring object
	Superstring stringList;
	string input ="";

	//get the user enter the strings
	cout << "Enter " << stringList.getArrSize() << " string(s)" << endl;
	cin.ignore();
	for(int i = 0; i < stringList.getArrSize(); i++){
		cout << "\tString " << i+1 << ": ";
		getline(cin, input);
		stringList.setTemp(input);
		stringList.storeString(stringList.getMyString(), i, stringList.getTemp());
	}

	//outputs the strings that the user have entered
	stringList.outputString();

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
