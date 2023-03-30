#ifndef NAVYSHIP_H
#define NAVYSHIP_H

#include "Ship.h"
#include <string>
using namespace std;

class NavyShip : public Ship{
private:
  string type;
  string designation;
  int crewMembers;
  bool nuclear;
  int maxSpeed;

public:

  //constructors
  NavyShip() : Ship(){
    type = "";
    designation = "";
    crewMembers = 0;
    nuclear = false;
    maxSpeed = 0;
  }

  NavyShip(string r, string h, string n, int l, int d, string t, string desig, int c, bool nuc, int m) : Ship(r, h, n, l, d){
    type = t;
    designation = desig;
    crewMembers = c;
    nuclear = nuc;
    maxSpeed = m;
  }
};

#endif
