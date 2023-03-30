#ifndef TICKET_H
#define TICKET_H
#include "Police.h"
#include <iostream>
#include <string>
using namespace std;

/*
-----------------------
  Ticket :: Police
-----------------------
- violation: string
- ticketNumber: int
- fine: double
- paid: bool
-----------------------
+ Ticket() : Police()
+ Ticket(string, int, double, string, int) : Police(string, int)
+ getViolation() : string
+ getTicketNr() : int
+ getFine() : double
+ getStatus() : bool
+ setStatus(bool) : void
+ printTicket() : void
----------------------
*/

class Ticket : public Police {
private:
  string violation;
  int ticketNumber;
  double fine;
  bool paid;
public:
  //constructors
  Ticket() : Police(){
    violation = "";
    ticketNumber = 0;
    fine = 0.0;
    paid = false;
  }

  Ticket(string violation, int ticketNumber, double fine, string lastName, int badgeNumber) : Police(lastName, badgeNumber){
    this->violation = violation;
    this->ticketNumber = ticketNumber;
    this->fine = fine;
    this->paid = false;
  }

  //accessors
  string getViolation() {return violation;}
  int getTicketNumber() {return ticketNumber;}
  double getFine() {return fine;}
  bool getStatus() {return paid;}

  //mutators
  void setStatus(bool paid) {this->paid = paid;}

  //other methods
  void printTicket(){
    cout << "Ticket #" << ticketNumber << " (" << violation << ", "; printOfficer(); cout << "): " << (paid ? "paid" : "unpaid") << " ($ " << (paid ? 0.0 : fine) << " due)" << endl;
  }
};

#endif
