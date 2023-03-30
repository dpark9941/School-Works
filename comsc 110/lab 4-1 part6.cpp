//============================================================================
// Name        : lab 4-1 part6.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program converts the number of seconds to either the number of days, hours, or minutes.
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

int main() {

	double second, // the number of seconds
		   minute, // the number of minutes
		   hour, // the number of hours
		   day; // the number of days

	cout << "Enter the number of seconds, and this program will output either the number of days, hours, or minutes that will fit your input." << endl << endl;
	cout << "Enter the number of seconds: ";
	cin >> second;
	cout << setprecision(2) << showpoint << fixed << endl;

	if (second >= 86400)
	{
		day = second / 86400;
		cout << "Results:" << endl;
		cout << second << "seconds is " << day << " days.";
	}

	else if (second >= 3600)
	{
		hour = second / 3600;
		cout << "Results:" << endl;
		cout << second << "seconds is " << hour << " hours.";
	}

	else if (second >= 60)
	{
			minute = second / 60;
			cout << "Results:" << endl;
			cout << second << "seconds is " << minute << " minute.";
	}

	else if (second >= 0)
	{
		cout << "Results: " << endl;
		cout << second << " seconds is less than one minute.";
	}

	else
	{
		cout << "ERROR: Invalid value! Please re-run the program.";
		return 0;
	}

	return 0;
}
