//Car.h
#ifndef CAR_H
#define CAR_H
#include <iostream>
#include <string>
#include "BinaryTree.h"
using namespace std;

//forward declare Car class
class Car;

//overload stream operator
ostream &operator<< (ostream &, Car &);

class Car
{

private:
    string MakeModel;
    int year;

public:
    //constructor
    Car (string n = "None", int y = 0) { MakeModel = n; year = y; }

    //setters and getters
    void setMakeModel(string str)    { MakeModel = str; }
    string getMakeModel()            { return MakeModel; }

    //overloaded operators
    bool operator==(string value)
        { return this->getMakeModel() == value; }
    bool operator==(const Car& c)
        { return this->getMakeModel() == c.MakeModel; }
    bool operator< (const Car& c)
        { return this->getMakeModel() < c.MakeModel; }
    bool operator> (const Car& c)
        { return this->getMakeModel() > c.MakeModel; }

    friend ostream &operator<<(ostream &strm, Car &obj)
    {
        strm << "\tMake/Model: " << obj.MakeModel << endl;
        return strm;
    }
};
#endif
