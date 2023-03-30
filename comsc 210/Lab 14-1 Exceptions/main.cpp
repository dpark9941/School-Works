//*****************
//Program Name: Lab 14-1: Exceptions
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: Modify the Date class such that it uses C++ exceptions
//*****************

#include <iostream>
#include "Date.h"
using namespace std;

void plagiarismRequirement();

int main(){

	//creates an instance of Date class and displays the date if there's no error;
	//otherwise, displays error messages
	try{
		Date myBDay(4, 9, 2001);
		cout << "My birthday is " << endl;
		myBDay.showDate1();
		myBDay.showDate2();
		myBDay.showDate3();
	}

	catch(Date::InvalidMonth e){
		cout << "ERROR: " << e.getValue() << " is invalid value for month" << endl;
	}

	catch(Date::InvalidDay e){
		cout << "ERROR: " << e.getValue() << " is invalid value for day" << endl;
	}
	cout << endl;

	try{
		Date invalidMonth(13, 1, 2020);
		cout << "My birthday is " << endl;
		invalidMonth.showDate1();
		invalidMonth.showDate2();
		invalidMonth.showDate3();
	}

	catch(Date::InvalidMonth e){
		cout << "ERROR: " << e.getValue() << " is invalid value for month" << endl;
	}

	catch(Date::InvalidDay e){
		cout << "ERROR: " << e.getValue() << " is invalid value for day" << endl;
	}
	cout << endl;

	try{
		Date invalidDay(5, 32, 2008);
		cout << "My birthday is " << endl;
		invalidDay.showDate1();
		invalidDay.showDate2();
		invalidDay.showDate3();
	}

	catch(Date::InvalidMonth e){
		cout << "ERROR: " << e.getValue() << " is invalid value for month" << endl;
	}

	catch(Date::InvalidDay e){
		cout << "ERROR: " << e.getValue() << " is invalid value for day" << endl;
	}
	cout << endl;

	plagiarismRequirement();


	return 0;
}

//*****************
//Function name: plagiarismRequirement
//Purpose: outputs plagiarism Requirement
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
