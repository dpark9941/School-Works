//*****************
//Program Name: Lab 10-2: Redefining Base Functions
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: write Venue class and Theater class and practice redefining
//*****************

#include "Venue.h"
#include "Theater.h"
#include <iostream>
using namespace std;

int main() {
  Venue venue("Public venue", 2020, 140, 0);
  Theater theater("DVC Theater", "321 Golf Club Road", "Pleasant Hill, CA, 94523", 5607.83, "Commercial venue", 1999, 350, 4.99);

  cout << "Information about Venue:" << endl;
  venue.printVenue();

  cout << endl;

  cout << "Information about theater:" << endl;
  theater.printTheater();

  cout << endl;
  cout << "I attest that this code is my original programming work, and that I received" << endl;
  cout << "no help creating it. I attest that I did not copy this code or any portion of this" << endl;
  cout << "code from any source." << endl;

  return 0;
}
