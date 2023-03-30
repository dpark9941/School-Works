//*****************
//Program Name: Program 5: Date Class
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: write a Date class and output dates in two formats: military format and regular format
//*****************

#ifndef DATE_H
#define DATE_H

/*
-----------------------------------
  Date
-----------------------------------
- day: int
- month: int
- year: int
-----------------------------------
+ Date(d: int, m: int, y: int)
+ setDay(d: int): void
+ setMonth(m: int): void
+ setYear(y: int): void
+ getDay(): int
+ getMonth(): int
+ getYear(): int
+ showMilitaryDate(): void
+ showRegularDate(): void
+ inputValidation(): void
-----------------------------------
*/

class Date{
private:
  int day;
  int month;
  int year;
public:
  //constructor
  Date(int d = 1, int m = 1, int y = 1970);

  //mutators
  void setDay(int);
  void setMonth(int);
  void setYear(int);

  //accessors
  int getDay();
  int getMonth();
  int getYear();

  //additional methods
  void showMilitaryDate();
  void showRegularDate();
  void inputValidation();
};

#endif
