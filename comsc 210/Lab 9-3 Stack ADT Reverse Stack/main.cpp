//*****************
//Program Name: Lab 9-3: Stack ADT Reverse Stack
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: Add to the Stack ADT with a method that will make a reverse copy of a target stack
//*****************

#include "stackType.h"
#include <iostream>
using namespace std;

void plagiarismRequirement();

int main(){

	//creates stack1
	stackType<int> stack1;
	stack1.push(1);
	stack1.push(12);
	stack1.push(123);
	stack1.push(1234);
	stack1.push(12345);

	//displays stack1, the original stack
	cout << "The original stack:" << endl;
	stack1.displayStack();
	cout << endl;

	//creates stack2 that is empty
	stackType<int> stack2;

	//creates a reverse copy of stack1 on stack2
	stack1.reverseStack(stack2);

	//displays stack2, which is a reverse copy of stack1
	cout << "stack2 which is a reverse copy of stack1:" << endl;
	stack2.displayStack();
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
