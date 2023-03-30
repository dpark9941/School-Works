//*****************
//Program Name: Lab 5-3: Inline Functions
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: separate codes into TWO files, using inline functions
//*****************

#ifndef CAR_H //include guard
#define CAR_H

#include <string>
using namespace std;

/*
-----------------------------------
  Car
-----------------------------------
- make: string
- year: int
-----------------------------------
+ setMake(m: string): void
+ setYear(y: int): void
+ getMake(): string
+ getYear(): int
-----------------------------------
*/

class Car
{
  private:
    string make;
    int year;
  public:
    void setMake(string m) {make = m;}
    void setYear(int y) {year = y;}
    string getMake() {return make;}
    int getYear() {return year;}
};

#endif
