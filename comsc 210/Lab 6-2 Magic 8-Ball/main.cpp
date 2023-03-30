//*****************
//Program Name: Lab 6-2: Magic 8-Ball
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: This program will simulate the child's toy, the Magic 8-Ball
//*****************

#include "Magic8Ball.h"
#include <iostream>
#include <string>
using namespace std;

void plagiarismRequirement();

int main(){
	Magic8Ball myBall;
	int shakes = 10000;

	cout << "This is Magic 8-Ball!" << endl;
	cout << "Shaking the Magic 8-Ball " << shakes << " times..." << endl;
	for(int i = 0; i < shakes; i++)
		myBall.shake();
	cout << "Done." << endl << endl;

	cout << "RESULTS" << endl << endl;
	for(int i = 0; i < myBall.getARR_SIZE(); i++)
		cout << "Answer " << i+1 << ": " << *(myBall.getCountList() + i) << "/" << shakes << " (" << (*(myBall.getCountList() + i) / (double)shakes) * 100 <<"%) " << *(myBall.getAnswerList() + i) << endl;

	plagiarismRequirement();

	return 0;
}

//*****************
//Function name: plagiarismRequirement
//Purpose: outputs Plagiarism Requirement
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
