//*****************
//Program Name: Lab 9-1: Operator Overloading
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: Write a demo program that exercise operator overloading
//*****************

#include "Box.h"
#include <iostream>
using namespace std;

void plagiarismRequirement();

int main(){
	Box box1(1.3, 2.2, 3.8);
	Box box2(3.5, 2.5, 4.0);
	Box box3;
	Box box4;

	cout << "The volume of box1: " << box1.getVolume() << endl;
	cout << "The volume of box2: " << box2.getVolume() << endl;
	cout << "The volume of box3: " << box3.getVolume() << endl;
	cout << "The volume of box4: " << box4.getVolume() << endl;
	cout << endl;

	cout << "Testing equality:" << endl;
	cout << "Testing if box1 = box2: " << (box1 == box2 ? "True" : "False") << endl;
	cout << "Testing if box2 = box3: " << (box2 == box3 ? "True" : "False") << endl;
	cout << "Testing if box3 = box4: " << (box3 == box4 ? "True" : "False") << endl;
	cout << "Testing if box4 = box1: " << (box4 == box1 ? "True" : "False") << endl;
	cout << endl;

	cout << "Testing (volume) greater than:" << endl;
	cout << "Testing if box1 > box2: " << (box1 > box2 ? "True" : "False") << endl;
	cout << "Testing if box2 > box3: " << (box2 > box3 ? "True" : "False") << endl;
	cout << "Testing if box3 > box4: " << (box3 > box4 ? "True" : "False") << endl;
	cout << "Testing if box4 > box1: " << (box4 > box1 ? "True" : "False") << endl;
	cout << endl;

	cout << "Testing (volume) less than:" << endl;
	cout << "Testing if box1 < box2: " << (box1 < box2 ? "True" : "False") << endl;
	cout << "Testing if box2 < box3: " << (box2 < box3 ? "True" : "False") << endl;
	cout << "Testing if box3 < box4: " << (box3 < box4 ? "True" : "False") << endl;
	cout << "Testing if box4 < box1: " << (box4 < box1 ? "True" : "False") << endl;
	cout << endl;

	cout << "Testing (all dimensions) greater than:" << endl;
	cout << "Testing if box1 >= box2: " << (box1 >= box2 ? "True" : "False") << endl;
	cout << "Testing if box2 >= box3: " << (box2 >= box3 ? "True" : "False") << endl;
	cout << "Testing if box3 >= box4: " << (box3 >= box4 ? "True" : "False") << endl;
	cout << "Testing if box4 >= box1: " << (box4 >= box1 ? "True" : "False") << endl;
	cout << endl;

	cout << "Testing (all dimensions) less than:" << endl;
	cout << "Testing if box1 <= box2: " << (box1 <= box2 ? "True" : "False") << endl;
	cout << "Testing if box2 <= box3: " << (box2 <= box3 ? "True" : "False") << endl;
	cout << "Testing if box3 <= box4: " << (box3 <= box4 ? "True" : "False") << endl;
	cout << "Testing if box4 <= box1: " << (box4 <= box1 ? "True" : "False") << endl;
	cout << endl;

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
