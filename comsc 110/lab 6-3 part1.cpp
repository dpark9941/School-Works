//============================================================================
// Name        : lab 6-3.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : calculates the average of test scores
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

//function prototypes
void getScores(double &, double &, double &);
double inputScore();
void calcAverage(double, double, double);
double findLowest(double, double, double);

int main(){

	double score1, score2, score3;

	getScores(score1, score2, score3);
	calcAverage(score1, score2, score3);

	return 0;
}

//gets the scores from user and assigns them to reference variables
void getScores(double &s1, double &s2, double &s3){

	cout << "Enter the first score: ";
	s1 = inputScore();
	cout << "Enter the second score: ";
	s2 = inputScore();
	cout << "Enter the third score: ";
	s3 = inputScore();
}

//gets scores from user and inputvalidates them
double inputScore(){

	double response;

	cin >> response;

	while (response < 0 || response > 100)
	{
		cout << "ERROR! the value must be 0 - 100. Please reenter: ";
		cin >> response;
	}

	return response;
}

//subtracts the lowest score from the total, and then calculates the average of test scores
void calcAverage(double s1, double s2, double s3){

	double sum = s1 + s2 + s3;
	double average = (sum - findLowest(s1, s2, s3)) / 2;

	cout << setprecision(2) << fixed << showpoint;
	cout << "After dropping the lowest score, the test average is " << average << endl;
}

//finds the lowest test score
double findLowest(double s1, double s2, double s3){

	double lowest = 101;

	if (s1 < s2)
	{
		lowest = s1;
		if (s3 < lowest)
			lowest = s3;
	}

	else //s1 >= s2
	{
		lowest = s2;
		if (s3 < lowest)
			lowest = s3;
	}

	return lowest;
}

