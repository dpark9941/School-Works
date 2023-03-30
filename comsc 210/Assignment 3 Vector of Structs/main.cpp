//*****************
//Program Name: Assignment 3: Vector of Structs
//Author: Your Donggyu Park
//IDE Used: Eclipse
//Program description: Write a program that will create and store a vector of structs
//*****************

#include "Color.h"
#include <iostream>
#include <iomanip> // for right & setw()
#include <cstdlib> //for rand() & srand()
#include <ctime> //for time(0)
#include <vector>
using namespace std;

const int VECTOR_MIN = 5; //minimum range of vector's size
const int VECTOR_MAX = 50; //maximun range of vector's size
const int COLOR_MIN = 0;
const int COLOR_MAX = 255;
const int W1 = 7;

Color PopulateColor();
void OutputColor(Color);
void plagiarismRequirement();

int main(){
	srand(time(0)); //seed value for rand()
	int vector_size = rand() % (VECTOR_MAX - VECTOR_MIN + 1) + VECTOR_MIN;
	vector<Color> colorList;

	//populates colorList
	for(int i = 0; i < vector_size; i++){
		colorList.push_back(PopulateColor());
	}

	//outputs colorList
	cout << "Color #\tR value\tG value\tB value" << endl;
	cout << "-------\t-------\t-------\t-------" << endl;
	for(int i = 0; i < colorList.size(); i++){
		cout << right << setw(W1) << i + 1;
		OutputColor(colorList.at(i));
	}

	plagiarismRequirement();

	return 0;
}

//*****************
//Function name: PopulateColor
//Purpose: populates a Color object and returns it
//List of parameters:
//Returns: temp
//Return type: Color
//*****************
Color PopulateColor(){
	//generates random number from 0 - 255
	int red = rand() % (COLOR_MAX - COLOR_MIN + 1) + COLOR_MIN;
	int green = rand() % (COLOR_MAX - COLOR_MIN + 1) + COLOR_MIN;
	int blue = rand() % (COLOR_MAX - COLOR_MIN + 1) + COLOR_MIN;
	Color temp = {red, green, blue};

	//returns the struct
	return temp;
}

//*****************
//Function name: OutputColor
//Purpose: outputs info about a Color object
//List of parameters: Color temp
//Returns:
//Return type: void
//*****************
void OutputColor(Color temp){
	cout << right;
	cout << '\t' << setw(W1) << temp.r << '\t' << setw(W1) << temp.g << '\t' << setw(W1) << temp.b << endl;
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
