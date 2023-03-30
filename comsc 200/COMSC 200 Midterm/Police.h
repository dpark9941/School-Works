#ifndef POLICE_H
#define POLICE_H
#include <iostream>
#include <string>
using namespace std;

/*
-----------------------
  Police
-----------------------
- lastName: string
- badgeNumber: int
-----------------------
+ Police()
+ Police(string, int)
+ getName() : string
+ getBadge() : int
+ printOfficer() : void
----------------------
*/

class Police {
private:
  string lastName;
  int badgeNumber;
public:
  //constructors
  Police(){
    lastName = "";
    badgeNumber = 0;
  }

  Police(string lastName, int badgeNumber){
    this->lastName = lastName;
    this->badgeNumber = badgeNumber;
  }

  //accessors
  string getName() {return lastName;}
  int getBadge() {return badgeNumber;}

  //ohter methods
  void printOfficer() {
    cout << lastName << ", " << badgeNumber;
  }
};

#endif
