//*****************
//Program Name: Assignment 10: Queue ADT
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: Modify the queueType class and write a demo program that will exercise the class
//*****************

#include "queueType.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX_ELEMENT = 100;
const int MIN_ELEMENT = 0;
void plagiarismRequirement();

int main(){
	//creates an empty queue
	queueType<int> queue1;

	//adds 10 random numbers to the queue
	srand(time(0));
	for(int i = 0; i < 10; i++){
		int element = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
		queue1.addQueue(element);
	}

	//displays queue1
	cout << "Queue 1:" << endl;
	queue1.printQueue();
	cout << endl;

	char tenMore;
	do{
		//performs 10 random operations
		for(int i = 0; i < 10; i++){
			//randomly chooses which operation to perform
			int choice = rand() % (3 - 1 + 1) + 1;

			if(choice == 1){
				cout << "Add random number to the queue" << endl;
				int add = rand() % (MAX_ELEMENT - MIN_ELEMENT + 1) + MIN_ELEMENT;
				queue1.addQueue(add);
				queue1.printQueue();
				cout << endl;
			}
			else if(choice == 2){
				cout << "Delete queue front" << endl;
				queue1.deleteQueue();
				queue1.printQueue();
				cout << endl;
			}
			else if(choice == 3){
				//randomly chooses the index of the element to remove
				int index = rand() % (queue1.getCount() - 1 + 1) + 1;
				cout << "Move random element to front" << endl;
				cout << "Moving element " << index << " to front:" << endl;
				queue1.moveToFront(index);
				queue1.printQueue();
				cout << endl;
			}
		}
		cout << "Perform 10 more operations? Enter Y/N --> ";
		cin >> tenMore;

	} while(tolower(tenMore) != 'n');

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
