//*****************
//Program Name: Program 9: Multiple Inheritance
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: write a program using multiple inheritance
//*****************

#ifndef READERAPP_H
#define READERAPP_H

#include "PublishedWork.h"
#include "ElectronicDevice.h"
#include <string>
using namespace std;

class ReaderApp : public PublishedWork, public ElectronicDevice {
private:
  string appName;
  float appCost;
public:
  //constructors
  ReaderApp() : PublishedWork(), ElectronicDevice() {
    appName = "";
    appCost = 0.0;
  }

  ReaderApp(string appName, float appCost, string author, int yearPublished, string type, string os, int memory) :
  PublishedWork(author, yearPublished), ElectronicDevice(type, os, memory) {
    setAppName(appName);
    setAppCost(appCost);
  }

  //mutators
  void setAppName(string appName) {this->appName = appName;}
  void setAppCost(float appCost) {this->appCost = appCost;}

  //accessors
  string getAppName() {return appName;}
  float getAppCost() {return appCost;}

  //other methods
  void printReaderApp() {
    printPublishedWork();
    printElectronicDevice();
    cout << "App name: " << getAppName() << endl;
    cout << "App cost: $ " << getAppCost() << endl;
  }
};

#endif
