//*****************
//Program Name: Lab 5-4: Constructors
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: write a Car class with constructors and initialize objects using those constructors
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
+ Car()
+ Car(m: string)
+ Car(y: int)
+ Car(m: string, y: int)
+ setMake(m: string): void
+ setYear(y: int): void
+ getMake(): string
+ getYear(): int
-----------------------------------
*/

class Car{
  private:
    string make;
    int year;

  public:
    Car();
    Car(string);
    Car(int);
    Car(string, int);
    void setMake(string);
    void setYear(int);
    string getMake();
    int getYear();
};

#endif
