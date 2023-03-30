//*****************
//Program Name: Program 5: Date Class
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: write a Date class and output dates in two formats: military format and regular format
//*****************

#include "Date.h"
#include <iostream>
#include <iomanip> //setw() and setfill()
#include <string>
#include <cstdlib> //exit(0)

using namespace std;

const int W1 = 2; //width for setw()
int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const string mil_months[12] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
const string reg_months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

//constructor
Date::Date(int d, int m, int y){
  day = d;
  month = m;
  year = y;
}

//assigns a value to day
void Date::setDay(int d){
  day = d;
}

//assigns a value to month
void Date::setMonth(int m){
  month = m;
}

//assigns a value to year
void Date::setYear(int y){
  year = y;
}

//returns the value of day
int Date::getDay(){
  return day;
}

//returns the value of month
int Date::getMonth(){
  return month;
}

//returns the value of year
int Date::getYear(){
  return year;
}

//displays the date in military format
void Date::showMilitaryDate(){
  string month;
   switch (getMonth()){
     case 1:
       month = mil_months[getMonth() - 1];
       break;
     case 2:
       month = mil_months[getMonth() - 1];
       break;
     case 3:
       month = mil_months[getMonth() - 1];
       break;
     case 4:
       month = mil_months[getMonth() - 1];
       break;
     case 5:
       month = mil_months[getMonth() - 1];
       break;
     case 6:
       month = mil_months[getMonth() - 1];
       break;
     case 7:
       month = mil_months[getMonth() - 1];
       break;
     case 8:
       month = mil_months[getMonth() - 1];
       break;
     case 9:
       month = mil_months[getMonth() - 1];
       break;
     case 10:
       month = mil_months[getMonth() - 1];
       break;
     case 11:
       month = mil_months[getMonth() - 1];
       break;
     case 12:
       month = mil_months[getMonth() - 1];
       break;
     default:
       month = to_string(getMonth());
       break;
   }
   cout << setw(W1) << setfill('0');
   cout << getDay() << month << getYear() << endl;
}

//displays the date in regular format
void Date::showRegularDate(){
  string month;
  switch (getMonth()){
    case 1:
      month = reg_months[getMonth() - 1];
      break;
    case 2:
      month = reg_months[getMonth() - 1];
      break;
    case 3:
      month = reg_months[getMonth() - 1];
      break;
    case 4:
      month = reg_months[getMonth() - 1];
      break;
    case 5:
      month = reg_months[getMonth() - 1];
      break;
    case 6:
      month = reg_months[getMonth() - 1];
      break;
    case 7:
      month = reg_months[getMonth() - 1];
      break;
    case 8:
      month = reg_months[getMonth() - 1];
      break;
    case 9:
      month = reg_months[getMonth() - 1];
      break;
    case 10:
      month = reg_months[getMonth() - 1];
      break;
    case 11:
      month = reg_months[getMonth() - 1];
      break;
    case 12:
      month = reg_months[getMonth() - 1];
      break;
    default:
      month = to_string(getMonth());
      break;
  }
  cout << month << ' ' << getDay() << ", " << getYear() << endl;
}

void Date::inputValidation(){
  //checks if year member variable is in the right range
  if (getYear() <= 0){
    cout << "ERROR! Invalid year" << endl;
    //cout << "Program ending" << endl;
    //exit(0);
  }

  //checks if month member variable is in the right range
  if (getMonth() < 1 || getMonth() > 12){
    cout << "ERROR! Invalid month" << endl;
    //cout << "Program ending" << endl;
    //exit(0);
  }

  //checks if the year is a leap year. if it is, there should be 29 days in February
  if (getYear() % 4 == 0 && getYear() % 100 != 0){
    days[1] = 29;
  } else {
    days[1] = 28;
  }

  //checks if day member variable is in the right range
  if (getDay() > days[getMonth() - 1] || getDay() <= 0){
    cout << "ERROR! Invalid day" << endl;
    //cout << "Program ending" << endl;
    //exit(0);
  }
}

