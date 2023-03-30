//*****************
//Program Name: Program 6: Interactive Car Collection
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: write a Car class with interactive features
//*****************

#ifndef CAR_H
#define CAR_H

#include <string>
#include <vector>

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
----------------------
*/

class Car{
  private:
    string make;
    int year;
    int speed;
    short choice;

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
};

#endif
