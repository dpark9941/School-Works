#ifndef SHIP_H
#define SHIP_H

#include <string>
using namespace std;

class Ship{
private:
  string registry;
  string homeport;
  string name;
  int length;
  int displacement;

public:

  //constructors
  Ship(){
    registry = "";
    homeport = "";
    name = "";
    length = 0;
    displacement = 0;
  }

  Ship(string r, string h, string n, int l, int d){
    registry = r;
    homeport = h;
    name = n;
    length = l;
    displacement = d;
  }

  //mutaotrs
  void setRegistry(string r) {registry = r;}
  void setHomeport(string h) {homeport = h;}
  void setName(string n) {name = n;}
  void setLength(int l) {length = l;}
  void setDisplacement(int d) {displacement = d;}

  //accessors
  string getRegistry() {return registry;}
  string getHomeport() {return homeport;}
  string getName() {return name;}
  int getLength() {return length;}
  int getDisplacement() {return displacement;}
};

#endif
