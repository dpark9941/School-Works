//*****************
//Program Name: Lab 6-1: Accelerate and Brake That Car
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: write a Car class and accelerate or brake the car
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

    const double ACC_RATE = 5;
    const double BRK_RATE = -5;

  public:
    Car(string, int);
    void setMake(string);
    void setYear(int);
    void setSpeed(int);

    string getMake();
    int getYear();
    int getSpeed();

    void accelerate();
    void brake();
    void displayStat();
};

#endif


