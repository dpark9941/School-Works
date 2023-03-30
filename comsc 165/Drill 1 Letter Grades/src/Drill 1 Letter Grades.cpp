//============================================================================
// Lab Name    : Drill: Letter Grades.cpp
// Author      : Donggyu Park
// Date        : 02/12/2020
// Programming Environment : Win 10, Eclipse
//============================================================================

#include <iostream>
using namespace std;

void InputValidation(double&);


int main() {
	int userInput;
	int ones, tens, thousands, tenthousands;

	cout << "Enter a 5 digit number and I'll tell you if it's a palindrome" << endl;
	cout << "Enter a number: ";
	cin >> userInput;



	if (tenthousands == ones && thousands == tens){
		cout << userInput << " is a palindrome" << endl;
	}
	else {
		cout << userInput << " is not a palindrome" << endl;
	}



	return 0;
}

void InputValidation(double &input){

	while (input < 0 || input > 100){
		cout << "ERROR! The value has to be in a range of 0 - 100. Please enter again: ";
		cin >> input;
	}
}

/*	Drill: Letter Grades
void LetterGrades (){
	const int A = 90;
	const int B = 80;
	const int C = 70;
	const int D = 60;

	double userGrade; //the percentage grade

	cout << "Please enter the percentage and I will tell you the letter grade." << endl;
	cout << "Enter your grade: ";
	cin >> userGrade;
	InputValidation(userGrade);

	cout << "Thank you. " << userGrade << " is a ";

	if (userGrade >= A){
		cout << "A." << endl;
	}
	else if (userGrade >= B){
		cout << "B." << endl;
	}
	else if (userGrade >= C){
		cout << "C." << endl;
	}
	else if (userGrade >= D){
		cout << "D." << endl;
	}
	else {
		cout << "F." << endl;
	}

}
*/

/*	Drill: Tips
void Tips(){
	const double EXCELLENT = 0.20;
	const double GOOD = 0.15;
	const double POOR = 0.10;

	double totalBill;
	double liquorCharge;
	int serviceQuality;
	double tip;

	cout << "Enter the total bill: ";
	cin >> totalBill;
	cout << "Enter the liquor charge: ";
	cin >> liquorCharge;
	cout << "Was your service 1) excellent 2) good 3) poor: ";
	cin << serviceQuality;

	if (serviceQuality == 1){
		tip = (totalBill - liquorCharge) * EXCELLENT;
	}
	else if (serviceQuality == 2){
		tip = (totalBill - liquorCharge) * GOOD;
	}
	else if (serviceQuality == 3){
		tip = (totalBill - liquorCharge) * POOR;
	}
	else{
		cout << "Invalid input. Program ending.";
		return 0;
	}

	cout << "Tip: $" << tip << endl;
}
*/

