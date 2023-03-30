//*****************
//Program Name: Program 5: Date Class
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: write a Date class and output dates in two formats: military format and regular format
//*****************

#include "Date.h"
#include <iostream>

using namespace std;


int main(){
  Date myBirthday(9, 4, 2001);
  Date leapYear(29, 2, 2020);
  Date invalid_day(33, 5, 2018);
  Date invalid_month(10, 15, 2009);
  Date invalid_year(2, 1, -2001);

  myBirthday.inputValidation();
  myBirthday.showMilitaryDate();
  myBirthday.showRegularDate();
  cout << endl;

  leapYear.inputValidation();
  leapYear.showMilitaryDate();
  leapYear.showRegularDate();
  cout << endl;

  invalid_day.inputValidation();
  invalid_day.showMilitaryDate();
  invalid_day.showRegularDate();
  cout << endl;

  invalid_month.inputValidation();
  invalid_month.showMilitaryDate();
  invalid_month.showRegularDate();
  cout << endl;

  invalid_year.inputValidation();
  invalid_year.showMilitaryDate();
  invalid_year.showRegularDate();
  cout << endl;

  cout << endl;
  cout << "I attest that this code is my original programming work, and that I received" << endl;
  cout << "no help creating it. I attest that I did not copy this code or any portion of this" << endl;
  cout << "code from any source." << endl;

  return 0;
}
