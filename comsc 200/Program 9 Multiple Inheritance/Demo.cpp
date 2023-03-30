//*****************
//Program Name: Program 9: Multiple Inheritance
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: write a program using multiple inheritance
//*****************

#include "PublishedWork.h"
#include "ElectronicDevice.h"
#include "ReaderApp.h"
#include <iostream>
using namespace std;

int main(){
  ReaderApp ide1("xCode", 10.99, "Steve Jobs", 2003, "MacBook", "Catalina", 16);
  ReaderApp ide2("Eclipse", 9.99, "Eclipse Foundation", 2001, "DELL", "Windows 10", 16);

  ide1.printReaderApp();
  cout << endl;

  ide2.printReaderApp();
  cout << endl;

  cout << endl;
  cout << "I attest that this code is my original programming work, and that I received" << endl;
  cout << "no help creating it. I attest that I did not copy this code or any portion of this" << endl;
  cout << "code from any source." << endl;

  return 0;
}
