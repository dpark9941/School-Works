//============================================================================
// Lab Name    : Drill: Which Data Structure Will You Use?
// Author      : Donggyu Park
// Date        : 02/19/2020
// Programming Environment : Win 10, Eclipse
//============================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int STUDENTS = 5;

int main() {
	string name;
	vector<string> names;
	double quiz1Score[STUDENTS];
	double quiz2Score[STUDENTS];
	double quiz3Score[STUDENTS];
	double avergageScore, sum;
	double max = 0;

	for (int i = 0; i < STUDENTS; i++){
		cout << "Enter the student's last name: ";
		cin >> name;
		names.push_back(name);

		cout << "Enter " << name << "'s quiz 1 score: ";
		cin >> quiz1Score[i];

		cout << "Enter " << name << "'s quiz 2 score: ";
		cin >> quiz2Score[i];

		cout << "Enter " << name << "'s quiz 3 score: ";
		cin >> quiz3Score[i];
	}

	for (int i = 0; i < STUDENTS; i++){
	}

	avergageScore = sum / STUDENTS;

	cout << "The average score is " << avergageScore << endl;
	cout << "The maximum score is " << max << endl;

	return 0;
}

/*	Which data structure will you use
	double quizScore[STUDENTS];
	double avergageScore, sum;
	double max = 0;

	for (int i = 0; i < STUDENTS; i++){
		cout << "Enter the quiz score " << i+1 << ": ";
		cin >> quizScore[i];
	}

	for (int i = 0; i < STUDENTS; i++){
		if (quizScore[i] > max){
			max = quizScore[i];
		}
		sum += quizScore[i];
	}

	avergageScore = sum / STUDENTS;

	cout << "The average score is " << avergageScore << endl;
	cout << "The maximum score is " << max << endl;
 */
