//*****************
//Program Name: Lab 7-1: Constructors with Inheritance
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: write a Chair class that inherits Furniture class
//*****************

#include "Chair.h"
using namespace std;

int main(){

  Chair barstool("Sears", 1992, 4, "blue");
  barstool.printChair();

  cout << endl;
  cout << "I attest that this code is my original programming work, and that I received" << endl;
  cout << "no help creating it. I attest that I did not copy this code or any portion of this" << endl;
  cout << "code from any source." << endl;

  return 0;
}
