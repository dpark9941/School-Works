#ifndef MAGIC8BALL_H
#define MAGIC8BALL_H

#include <string>
using namespace std;

const int ARR_SIZE = 6;

/*
----------------------------
         Superstring
----------------------------
- MAX: const int
- MIN: const int
- selectedAns: int
- answerList: const string[]
- countAnswers: int[]
----------------------------
+ Magic8Ball()
+ setSelectedAns(int): void
+ getARR_SIZE(): const int
+ getSelectedAns(): int
+ getAnswerList(): const string *
+ getCountList(): int *
+ shake(): void
+ incrementCount(int): void
+ getAnswer(): string
----------------------------
*/

class Magic8Ball{
private:
	const int MAX = 5;
	const int MIN = 0;
	int selectedAns;
	const string answerList[ARR_SIZE] = {"By all means, yes",
							"Oh nooooooo",
							"The future is uncertain",
							"I don't know; shake again",
							"It's up to you; your choice",
							"Absolutely, positively NO"
	};
	int countAnswers[ARR_SIZE] = {0, 0, 0, 0, 0, 0};

public:
	//constructor
	Magic8Ball();

	//mutators
	void setSelectedAns(int s) {this->selectedAns = s;}

	//accessors
	const int getARR_SIZE() {return ARR_SIZE;}
	int getSelectedAns() {return selectedAns;}
	const string *getAnswerList() {return answerList;}
	int *getCountList() {return countAnswers;}

	//other methods
	void shake();
	void incrementCount(int index) {*(countAnswers + index) += 1;}
	string getAnswer() {return *(answerList + selectedAns);}
};

#endif
