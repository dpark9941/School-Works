//============================================================================
// Name        : Ch6 programming quiz.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : gets 2 numbers and 1 math operator and calculates the result
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

//function prototypes
void welcome();
void getInput(float&, float&, char&);
void doMath(float, float, char);

int main(){

	char again; //repeats the whole program

	do{

		float num1, num2; //user input of numbers
		char someMath; //user input of mathematical operators

		welcome();
		getInput(num1, num2, someMath);
		doMath(num1, num2, someMath);
		cout << "Another problem? (Y/N): ";
		cin >> again;
		while (tolower(again) != 'y' && tolower(again) != 'n'){ //input validation
			cout << "ERROR! Only Y/N: ";
			cin >> again;
		}
	} while (tolower(again) == 'y');

	cout << "Program ending... Have a nice day" << endl;
	return 0;
}

//displays welcoming sentences
void welcome(){
	cout << "This program will ask you for two numbers and and operator (such as *, -) and generate the results" << endl;
}

//gets input from the user and inputvalidates it
void getInput(float& n1, float& n2, char& someMath){

	cout << "Enter two numbers separated by space: ";
	cin >> n1 >> n2;
	cout << "Enter the operator you want: ";
	cin >> someMath;
	while (someMath != '+' && someMath != '-' && someMath != '*' && someMath != '/'){ //input validation
		cout << "ERROR! The operator must be +, -, * or /." << endl;
		cout << "Please reenter: ";
		cin >> someMath;
	}
	while (n2 == 0 && someMath == '/'){ //prevents dividing by 0
		cout << "ERROR! You can't divide by 0" << endl;
		cout << "Please reenter" << endl;
		cout << "#1 and #2: ";
		cin >> n1 >> n2;
		cout << "Please reenter the operator: ";
		cin >> someMath;
	}
}

//calculates the result and outputs them
void doMath(float n1, float n2, char someMath){

	switch (someMath){
	case '+':
		cout << n1 << " + " << n2 << " = " << n1 + n2 << endl;
		break;
	case '-':
		cout << n1 << " - " << n2 << " = " << n1 - n2 << endl;
		break;
	case '*':
		cout << n1 << " * " << n2 << " = " << n1 * n2 << endl;
		break;
	case '/':
		cout << n1 << " / " << n2 << " = " << n1 / n2 << endl;
		break;
	}
}
