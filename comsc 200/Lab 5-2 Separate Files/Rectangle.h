//*****************
//Program Name: Lab 5-2: Separate Files
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: separate codes into three files: Class specification file, Class implementation file, Class demonstration file
//this file is the Class specification file
//*****************

#ifndef RECTANGLE_H //include guard
#define RECTANGLE_H

/*
-----------------------------------
  Rectangle
-----------------------------------
- width: double
- length: double
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
  public:
    void setWidth(double);
    void setLength(double);
    double getWidth() const;
    double getLength() const;
    double getArea() const;
};

#endif
