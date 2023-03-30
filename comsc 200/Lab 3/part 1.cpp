//*****************
//Program Name: Lab 3 part 1
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: Rewrite the function such that it uses pointers rather than reference variables
//*****************

#include <iostream>
using namespace std;

int changeValues(int*, int*);
void plagiarismRequirement();

int main(){
	//variable declarations
	int a, b, sum;
	a = 6;
	b = 8;

	//outputs the values of a, b before changing
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	//changes the values of a, b
	cout << endl << "Changing the values..." << endl;
	sum = changeValues(&a, &b); //passing the address of variable since the function uses pointer
	cout << "Done" << endl << endl;

	//outputs the values of a, b after changing
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "Sum: " << sum << endl;

	//outputs plagiarism Requirement
	plagiarismRequirement();

	return 0;
}

//*****************
//Function name: changeValues
//Purpose: changes the values of two arguments
//List of parameters: int *x, int *y
//Returns: *x + *y
//Return type: int
//*****************
int changeValues(int *x, int *y)
{
    int temp = *x;
    *x = *y * 10;
    *y = temp * 10;
    return *x + *y;
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
