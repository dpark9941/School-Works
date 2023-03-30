//*****************
//Program Name: Lab 7-1
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: write a demo program using a class template
//*****************

#include "Collection.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int VECTOR_SIZE = 5;


template <typename T>
void populateVector(Collection<T> &);
//template <>
void populateVector(Collection<string> &);
void plagiarismRequirement();

int main(){

	//creates the Collection objects
	Collection<int> myInts(VECTOR_SIZE, 0);
	Collection<double> myDoubles(VECTOR_SIZE, 0.0);
	Collection<char> myChars(VECTOR_SIZE, 'a');
	Collection<string> myStrings(VECTOR_SIZE, "");

	//populates the myVector member variable of myInts
	cout << "Enter " << VECTOR_SIZE << " integers" << endl;
	populateVector(myInts);

	//populates the myVector member variable of myDoubles
	cout << "Enter " << VECTOR_SIZE << " numbers" << endl;
	populateVector(myDoubles);

	//populates the myVector member variable of myChars
	cout << "Enter " << VECTOR_SIZE << " characters" << endl;
	populateVector(myChars);

	//populates the myVector member variable of myStrings
	cin.ignore();
	cout << "Enter " << VECTOR_SIZE << " sentences" << endl;
	populateVector(myStrings);

	cout << endl;

	//prints out the elements of the vector
	cout << "The contents of myInts: " << endl;
	myInts.print();

	cout << "The contents of myDoubles: " << endl;
	myDoubles.print();

	cout << "The contents of myChars: " << endl;
	myChars.print();

	cout << "The contents of myStrings: " << endl;
	myStrings.print();

	plagiarismRequirement();

	return 0;
}

//populateVector(): populates the myVector member of Collection
//Arguments: myCollection (Collection<T> &) | Returns: (void)
template <typename T>
void populateVector(Collection<T> &myCollection){
	T userInput;
	for(int i = 0; i < VECTOR_SIZE; i++){
		cout << i + 1 << ": ";
		cin >> userInput;
		myCollection.setValue(userInput, i);
	}
}

//populateVector(): populates the myVector member of Collection
//Arguments: myCollection (Collection<string> &) | Returns: (void)
//template <>
void populateVector(Collection<string> &myCollection){
	string userInput;
	for(int i = 0; i < VECTOR_SIZE; i++){
		cout << i + 1 << ": ";
		getline(cin, userInput);
		myCollection.setValue(userInput, i);
	}
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
