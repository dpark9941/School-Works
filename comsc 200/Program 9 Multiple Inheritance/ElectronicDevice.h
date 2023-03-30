//*****************
//Program Name: Program 9: Multiple Inheritance
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: write a program using multiple inheritance
//*****************

#ifndef ELECTRONICDEVICE_H
#define ELECTRONICDEVICE_H

#include <iostream>
#include <string>
using namespace std;

class ElectronicDevice {
private:
  string type;
  string os;
  int memory;
public:
  //constructors
  ElectronicDevice() {
    type = "";
    os = "";
    memory = 0;
  }

  ElectronicDevice(string type, string os, int memory) {
    setType(type);
    setOS(os);
    setMemory(memory);
  }

  //mutators
  void setType(string type) {this->type = type;}
  void setOS(string os) {this->os = os;}
  void setMemory(int memory) {this->memory = memory;}

  //accessors
  string getType() {return type;}
  string getOS() {return os;}
  int getMemory() {return memory;}

  //other methods
  void printElectronicDevice() {
    cout << "Type: " << getType() << endl;
    cout << "OS: " << getOS() << endl;
    cout << "Memory: " << getMemory() << " GB" << endl;
  }
};

#endif
