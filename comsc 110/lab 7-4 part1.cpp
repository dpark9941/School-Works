//============================================================================
// Name        : lab 7-4 part1.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : compares students' answer with the real answer and calculates test grades
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

const int QUESTIONS = 20; //the number of questions
const int STUDENTS = 8; //the number of students

//function prototypes

int main(){
	char testAnswers[] = {'A','D','B','B','C','B','A','B','C','D','A','C','D','B','D','C','C','A','D','B'};
	char studentAnswers[][QUESTIONS] = {{'C','D','B','B','C','B','B','B','C','D','A','C','D','B','D','C','C','A','D','B'},
								   {'A','D','B','B','C','B','A','B','B','D','A','B','D','B','D','C','D','A','D','B'},
	                               {'A','D','B','B','C','B','A','B','C','D','A','C','D','B','D','D','C','A','D','B'},
	                               {'A','D','B','B','C','B','A','B','C','D','A','C','D','B','D','C','C','A','D','B'},
	                               {'A','D','B','A','C','B','A','B','C','D','B','C','D','B','D','C','C','A','D','B'},
	                               {'A','D','B','C','C','B','D','B','C','A','A','C','A','B','D','C','B','A','C','B'},
	                               {'A','D','B','B','C','B','A','B','C','D','A','C','D','B','D','C','C','B','D','B'},
	                               {'A','D','B','A','C','C','A','B','C','C','A','C','B','B','D','C','C','B','D','B'}};
	char incorrectAnswers[STUDENTS][QUESTIONS]; //holds the incorrect answers of each student
	char letterGrade;

	//compares the answers
	for (int r = 0; r < STUDENTS; r++){

		int wrong = 0; //counts the number of incorrectly answered questions
		int right = 0; //counts the number of correctly answered questions
		double grade = 0;

		for (int c = 0; c < QUESTIONS; c++){
			if (testAnswers[c] != studentAnswers[r][c]){
				wrong++;
				incorrectAnswers[r][c] = studentAnswers[r][c];
			}
			else
				incorrectAnswers[r][c] = '0';
		}
		//outputs the grades
		right = QUESTIONS - wrong;
		grade = ((double)right / QUESTIONS) * 100;
		letterGrade = (grade >= 90 ? 'A' : (grade >= 80 ? 'B' : (grade >= 70 ? 'C' : (grade >= 60 ? 'D' : 'F'))));

		cout << setprecision(2) << fixed << showpoint;
		cout << "====================GRADES====================" << endl;
		cout << "Student #" << r+1 << endl;
		cout << "You got " << wrong << " questions wrong" << endl;
		cout << "Questions you answered incorrectly (0 means correct):" << endl;
		for (int c = 0; c < QUESTIONS; c++)
			cout << incorrectAnswers[r][c] << " ";
		cout << endl << "Your grade is " << letterGrade << " (" << grade << "%)" << endl;
	}

	return 0;
}
