//*****************
//Program Name: Lab 9-2: Multiple Inheritance
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: write three classes and exercise Multiple Inheritance
//*****************


#ifndef BRAVO_H
#define BRAVO_H

#include "Alpha.h"
#include <string>
using namespace std;

class Bravo {
private:
  bool status;
  float total;
public:
  //constructors
  Bravo(){
    status = false;
    total = 0.0;
  }

  Bravo(bool status, float total){
    setStatus(status);
    setTotal(total);
  }

  //mutators
  void setStatus(bool status) {this->status = status;}
  void setTotal(float total) {this->total = total;}

  //accessors
  bool getStatus() {return status;}
  float getTotal() {return total;}
};

#endif
