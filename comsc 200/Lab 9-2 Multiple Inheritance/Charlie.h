//*****************
//Program Name: Lab 9-2: Multiple Inheritance
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: write three classes and exercise Multiple Inheritance
//*****************

#ifndef CHARLIE_H
#define CHARLIE_H

#include "Bravo.h"
#include <string>
using namespace std;

class Charlie : public Alpha, public Bravo {
private:
  string situation;
  float balance;
public:
  //constructors
  Charlie() : Alpha(), Bravo() {
    situation = "";
    balance = 0.0;
  }

  Charlie(string situtaion, float balance, bool status, float total, int number, string sentence) : Alpha(number, sentence), Bravo(status, total) {
    setSituation(situation);
    setBalance(balance);
  }

  //mutators
  void setSituation(string situation) {this->situation = situation;}
  void setBalance(float balance) {this->balance = balance;}

  //accessors
  string getSituation() {return situation;}
  float getBalance() {return balance;}
};

#endif
