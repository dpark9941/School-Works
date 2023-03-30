#ifndef PERSON_H
#define PERSON_H

#include "Date.h"
#include <iostream>
using namespace std;

/*
-----------------------
  Person
-----------------------
- id : int
- birthday : Date
-----------------------
+ Person()
+ Person(int, int, int, int)
+ print() : void
----------------------
*/

class Person {
private:
  int id;
  Date birthday; //Person class has an instance of Date; this is where aggregation happened
public:
  //constructors
  Person() : birthday() {
    id = 0;
  }

  Person(int id, int day, int month, int year) : birthday(day, month, year) {
    this->id = id;
  }

  //print out information about Person
  void print() {
    cout << "ID: " << id << endl;
    cout << "Birthday: ";
    birthday.print();
  }
};

#endif
