#ifndef FERRY_H
#define FERRY_H

#include "Ship.h"
#include <string>
using namespace std;

class Ferry : public Ship{
private:
  int passangerCap;
  int carCap;
  string origin;
  string destination;
  double ticketPrice;

public:

  //constructors
  Ferry() : Ship(){
    passangerCap = 0;
    carCap = 0;
    origin = "";
    destination = "";
    ticketPrice = 0.0;
  }

  Ferry(string r, string h, string n, int l, int d, int p, int c, string o, string dest, int t) : Ship(r, h, n, l, d){
    passangerCap = p;
    carCap = c;
    origin = o;
    destination = dest;
    ticketPrice = t;
  }
};

#endif
