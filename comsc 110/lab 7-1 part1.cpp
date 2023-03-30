//============================================================================
// Name        : lab 7-1 part1.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : gets numbers from user using reference variables
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

//function prototypes
void getInput(int &, int &, int &);

int main(){

	int num1, num2, num3;
	getInput(num1, num2, num3);
	cout << num1 << " " << num2 << " " << num3 << endl;

	return 0;
}

//gets numbers from user and assigns them to reference variables
void getInput(int &n1, int &n2, int &n3){

	cout << "Enter the first number: ";
	cin >> n1;
	cout << "Enter the second number: ";
	cin >> n2;
	cout << "Enter the third number: ";
	cin >> n3;
}
