//*****************
//Program Name: Lab 9-1: Multi-Layer Inheritance
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: write three classes and exercise Multi-Layer Inheritance
//*****************

#ifndef CHARLIE_H
#define CHARLIE_H

#include "Bravo.h"
#include <string>
using namespace std;

class Charlie : public Bravo {
private:
  string situation;
  float balance;
public:
  //constructors
  Charlie() : Bravo() {
    situation = "";
    balance = 0.0;
  }

  Charlie(string situtaion, float balance, bool stat, float t, int n, string s) : Bravo(stat, t, n, s) {
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
