//*****************
//Program Name: Lab 12-3 B-Tree
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: Write a simple driver program that will fully demonstrate various options on a B-Tree
//*****************

#include "bTree.h"
#include <iostream>
using namespace std;

void plagiarismRequirement();

int main(){
	bTree<int, 5> myBTree;
	srand(time(0));

	cout << "Creating 100 elements 5 way B-Tree with random numbers" << endl;
	for(int i = 0; i < 100; i++)
		myBTree.insert(rand() % 1000);
	cout << endl;

	cout << "Inorder traversal:" << endl;
	myBTree.inOrder();
	cout << endl << endl;

	for(int i = 0; i < 10; i++){
		cout << "Searching for " << i + rand() % 1000 << ": " << (myBTree.search(i) ? "found" : "not found") << endl;
		cout << endl;
	}

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
