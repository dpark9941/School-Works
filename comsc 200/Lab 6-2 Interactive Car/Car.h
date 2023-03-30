//*****************
//Program Name: Lab 6-2: Interactive Car
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: write a Car class with interactive features
//*****************

#ifndef CAR_H //include guard
#define CAR_H

#include <string>
using namespace std;

/*
-----------------------
  Car
-----------------------
- make: string
- year : int
- speed: int
- choice: short
- ACC_RATE: const double
- BRK_RATE: const double
-----------------------
+ Car(string, int)
+ setMake(m: string) : void
+ getMake() : string
+ setYear(y: int) : void
+ getYear() : int
+ setSpeed(s: int) : void
+ getSpeed() : int
+ setChoice(c: short): void
+ getChoice(): short
+ accelerate() : void
+ brake() : void
+ displayStat(): void
+ displayMenu(); void
----------------------
*/

class Car{
  private:
    string make;
    int year;
    int speed;
    short choice;

    const double ACC_RATE = 5;
    const double BRK_RATE = -5;

  public:
    Car(string, int);

    void setMake(string);
    void setYear(int);
    void setSpeed(int);
    void setChoice(short);

    string getMake();
    int getYear();
    int getSpeed();
    short getChoice();

    void accelerate();
    void brake();
    void displayStat();
    void displayMenu();
};

#endif
