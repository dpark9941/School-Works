//*****************
//Program Name: Lab 9-2: Stack ADT Overloading ==
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: Add to the Stack ADT by adding a method that will overload the equality operator (==)
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

	//displays stack1
	cout << "Created satck1:" << endl;
	stack1.displayStack();
	cout << endl;

	//creates stack2 using copy constructor
	stackType<int> stack2(stack1);

	//displays stack2
	cout << "Created stack2 using copy constructor:" << endl;
	stack2.displayStack();
	cout << endl;

	//displays the top of the stacks
	cout << "stack1's top: " << stack1.top() << endl;
	cout << "stack2's top: " << stack2.top() << endl;
	cout << endl;

	//checks if the two stacks are identical
	if(stack1 == stack2)
		cout << "stack1 and stack2 are identical" << endl;
	else
		cout << "stack1 and stack2 are not identical" << endl;
	cout << endl;

	//changes the value of the elements on stack2
	cout << "Pushing and popping elements on stack2..." << endl;
	stack2.pop();
	stack2.push(54321);
	stack2.displayStack();
	cout << endl;

	//displays the top of the stacks
	cout << "stack1's top: " << stack1.top() << endl;
	cout << "stack2's top: " << stack2.top() << endl;
	cout << endl;

	//checks if the stacks are still identical after the operation
	cout << "After push and pop operations on stack2:" << endl;
	if(stack1 == stack2)
		cout << "stack1 and stack2 are identical" << endl;
	else
		cout << "stack1 and stack2 are not identical" << endl;
	cout << endl;

	//changes the value of the elements on stack2
	cout << "Pushing another elements on stack2..." << endl;
	stack2.push(654321);
	stack2.displayStack();
	cout << endl;

	//displays the top of the stacks
	cout << "stack1's top: " << stack1.top() << endl;
	cout << "stack2's top: " << stack2.top() << endl;
	cout << endl;

	//checks if the stacks are still identical after the operation
	cout << "After another push operations on stack2:" << endl;
	if(stack1 == stack2)
		cout << "stack1 and stack2 are identical" << endl;
	else
		cout << "stack1 and stack2 are not identical" << endl;
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
