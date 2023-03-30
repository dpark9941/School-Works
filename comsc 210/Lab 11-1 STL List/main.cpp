//*****************
//Program Name: Lab 11-1: STL List
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: Write a program that demonstrates various STL List operations
//*****************

#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX_ELEMENT = 100;
const int MIN_ELEMENT = 0;

void generateList(list<int> &);
void displayList(list<int>);
void plagiarismRequirement();

int main(){
	//seed value for rand()
	srand(time(0));

	cout << "Creating first list with 10 random numbers" << endl;
	list<int> list1;
	generateList(list1);
	displayList(list1);
	cout << endl;

	cout << "Sorting the first list:" << endl;
	list1.sort();
	displayList(list1);
	cout << endl;

	cout << "Creating second list with 10 random numbers:" << endl;
	list<int> list2;
	generateList(list2);
	displayList(list2);
	cout << endl;

	cout << "Sorting the second list:" << endl;
	list2.sort();
	displayList(list2);
	cout << endl;

	cout << "Merging the two lists:" << endl;
	list1.merge(list2);
	displayList(list1);
	cout << endl;

	cout << "Reversing the new list:" << endl;
	list1.reverse();
	displayList(list1);
	cout << endl;

	cout << "Resizing the list to 8:" << endl;
	list1.resize(8);
	displayList(list1);
	cout << endl;

	cout << "Resizing the list to 12; new entries are the value 125:" << endl;
	list1.resize(12, 125);
	displayList(list1);
	cout << endl;

	cout << "Adding 0s as the new 5th and 6th elements:" << endl;
	list<int>::iterator it = list1.begin();
	//advances the iterator to 5th element of the list
	for(int i = 1; i < 5; i++) it++;
	//add 0 as the new 5th element of the list
	list1.emplace(it, 0);
	//add 0 as the new 6th element of the list
	list1.emplace(it, 0);
	displayList(list1);
	cout << endl;

	plagiarismRequirement();

	return 0;
}

//*****************
//Function name: generateList
//Purpose: creates a list with 10 random numbers
//List of parameters: list<int> myList
//Returns:
//Return type: void
//*****************
void generateList(list<int> &myList){
	for(int i = 0; i < 10; i++){
		int newElement = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
		myList.push_back(newElement);
	}
}

//*****************
//Function name: displayList
//Purpose: outputs the element of list
//List of parameters: list<int> tempList
//Returns:
//Return type: void
//*****************
void displayList(list<int> tempList){
	for(auto it = tempList.begin(); it != tempList.end(); it++)
		cout << *it << ' ';
	cout << endl;
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
