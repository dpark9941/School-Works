//============================================================================
// Name        : lab 5-2 part2.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : This program calculates grades for students
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

int main() {

	int students; // the number of students
	int tests; // the number of tests per student
	double testScore; // the score of tests
	double total; // the sum of test scores for a student
	double average; // the average of test scores for a student

	cout << "===Grade Calculator===" << endl;
	cout << "Enter the number of students: ";
	cin >> students;
	cout << "How many tests per student?: ";
	cin >> tests;

	for (int s = 1; s <= students; s++)
	{
		total = 0.0; // refreshes total score

		cout << "Enter grades for Student #" << s << ": " << endl;

		for (int t = 1; t <= tests; t++)
		{
			cout << "Test #" << t << ": ";
			cin >> testScore;
			total += testScore;
		}
		average = total / tests;
		cout << setprecision(2) << fixed << showpoint;
		cout << "Student #" << s << "\'s average: " << average << endl << endl;
	}

	return 0;
}
