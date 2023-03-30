//*****************
//Program Name: Lab 10-1: Aggregation
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: write Date class and Person class and practice aggregation
//*****************

#include "Date.h"
#include "Person.h"
#include <iostream>
using namespace std;

int main(){
  Person me(1758924, 9, 4, 2001);

  cout << "Information about me:" << endl;
  me.print();

  cout << endl;
  cout << "I attest that this code is my original programming work, and that I received" << endl;
  cout << "no help creating it. I attest that I did not copy this code or any portion of this" << endl;
  cout << "code from any source." << endl;

  return 0;
}
