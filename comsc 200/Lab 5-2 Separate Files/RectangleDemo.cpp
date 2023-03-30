//*****************
//Program Name: Lab 5-2: Separate Files
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: separate codes into three files: Class specification file, Class implementation file, Class demonstration file
//this file is the Class demonstration file
//*****************

#include <iostream>
#include "Rectangle.h"

using namespace std;

int main(){
  Rectangle box;     // Define an instance of the Rectangle class
  double rectWidth;  // Local variable for width
  double rectLength; // Local variable for length

  // Get the rectangle's width and length from the user.
  cout << "This program will calculate the area of a\n";
  cout << "rectangle. What is the width? ";
  cin >> rectWidth;
  cout << "What is the length? ";
  cin >> rectLength;

  // Store the width and length of the rectangle
  // in the box object.
  box.setWidth(rectWidth);
  box.setLength(rectLength);

  // Display the rectangle's data.
  cout << "Here is the rectangle's data:\n";
  cout << "Width: " << box.getWidth() << endl;
  cout << "Length: " << box.getLength() << endl;
  cout << "Area: " << box.getArea() << endl;

  cout << endl;
  cout << "I attest that this code is my original programming work, and that I received" << endl;
  cout << "no help creating it. I attest that I did not copy this code or any portion of this" << endl;
  cout << "code from any source." << endl;

  return 0;
}

