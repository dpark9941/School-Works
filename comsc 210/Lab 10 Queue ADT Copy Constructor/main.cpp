//*****************
//Program Name: Lab 10: Queue ADT Copy Constructor
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: Write a copy constructor for the Queue ADT
//*****************

#include "queueType.h"
#include <iostream>
using namespace std;

void plagiarismRequirement();

int main(){
	//creates an empty queue
	queueType<int> queue1;

	//adds elements to the queue
	queue1.addQueue(1);
	queue1.addQueue(12);
	queue1.addQueue(123);
	queue1.addQueue(1234);
	queue1.addQueue(12345);

	//displays queue1
	cout << "Queue 1:" << endl;
	queue1.printQueue();
	cout << endl;

	//creates queue2 using copy constructor
	queueType<int> queue2(queue1);

	//displays queue2
	cout << "Queue 2: " << endl;
	queue2.printQueue();
	cout << endl;

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
