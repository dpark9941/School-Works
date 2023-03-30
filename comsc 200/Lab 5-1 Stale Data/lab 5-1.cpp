//*****************
//Program Name: Lab 5-1: Stale Data
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: modify the code so that the area member variable won't remain stale
//*****************

#include <iostream>

using namespace std;

/*
-----------------------------------
  Rectangle
-----------------------------------
- width: double
- length: double
- area: double
-----------------------------------
+ setWidth(w: double): void
+ setLength(l: double): void
+ getWidth(): double
+ getLength(): double
+ getArea(): double
-----------------------------------
*/

class Rectangle
{
  private:
    double width;
    double length;
    //the area variable might remain stale! don't do this
    double area = length * width;
  public:
    void setWidth(double);
    void setLength(double);
    double getWidth();
    double getLength();
    //instead, provide a member function that returns the result of the calculation.
    double getArea();
};

// setWidth assigns a value to the width member. *
void Rectangle::setWidth(double w)
{
  width = w;
}

// setLength assigns a value to the length member. *
void Rectangle::setLength(double len)
{
  length = len;
}

// getWidth returns the value in the width member. *
double Rectangle::getWidth()
{
  return width;
}

// getLength returns the value in the length member. *
double Rectangle::getLength()
{
  return length;
}

// getArea returns the product of width times length. *
double Rectangle::getArea()
{
  return length * width;
}

int main() {
  Rectangle box; // Define an instance of the Rectangle class
  double rectWidth = 60.5; // Local variable for width
  double rectLength = 12.3; // Local variable for length

  // Store the width and length in the object
  box.setWidth(rectWidth);
  box.setLength(rectLength);

  // Display the rectangle's data
  cout << "Here is the rectangle's data:\n";
  cout << "Width: " << box.getWidth() << endl;
  cout << "Length: " << box.getLength() << endl;
  cout << "Area: " << box.getArea() << endl;
  box.setLength(100);
  box.setWidth(15);
  cout << "New area after setting length to 100 and width to 15: " << box.getArea() << endl;

  cout << endl;
  cout << "I attest that this code is my original programming work, and that I received" << endl;
  cout << "no help creating it. I attest that I did not copy this code or any portion of this" << endl;
  cout << "code from any source." << endl;
  return 0;
}
