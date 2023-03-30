//*****************
//Program Name: COMSC 200 SU20 Midterm
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: write Ticket class that processes ticket data files
//*****************

/* PLEASE READ ME
 * This is my COMSC 200 Mid-term
 * I've added input file validation to the program
 * Thank you
 */

#include "Ticket.h"
#include "Police.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

const int W1 = 2;

void readFile(vector<Ticket>&);
void outputDailyReport(vector<Ticket>);
double getRevenues(vector<Ticket>);
void processFile(vector<Ticket>&, double&, int&);
double getPaidFine(Ticket);
int getPaidTickets(Ticket);
void outputPostProcessFile(vector<Ticket>, double, int);
void plagiarismRequirement();

int main(){
  //declarations and housekeeping
  vector<Ticket> ticketList;

  //reads database into vector
  readFile(ticketList);

  //outputs daily ticket report
  outputDailyReport(ticketList);

  //processes payment file
  double paidFine = 0.0;
  int paidTickets = 0;
  processFile(ticketList, paidFine, paidTickets);

  //outputs the post-processing report
  cout << endl;
  outputPostProcessFile(ticketList, paidFine, paidTickets);

  //outputs plagiarism requirement
  plagiarismRequirement();

  return 0;
}

//*****************
//Function name: readFile
//Purpose: read strings from "tickets.txt" into ticketList
//List of parameters: &ticketList
//Returns:
//Return type: void
//*****************
void readFile(vector<Ticket> &ticketList){
  ifstream finTickets;
  finTickets.open("tickets.txt");
  //file validation
  if(!finTickets.good()){ //if the file is NOT properly open
    cout << "ERROR! Cannot open the tickets.txt file. Program ending" << endl;
    exit(0);
  }
  string temp;
  string violation;
  int ticketNumber;
  double fine;
  string lastName;
  int badgeNumber;
  while(getline(finTickets, temp)){
    stringstream ss(temp);
    ss >> violation >> ticketNumber >> fine >> lastName >> badgeNumber;
    Ticket tempTicket(violation, ticketNumber, fine, lastName, badgeNumber);
    ticketList.push_back(tempTicket);
  }
  finTickets.close();
}

//*****************
//Function name: outputDailyReport
//Purpose: outputs daily ticket report
//List of parameters: ticketList
//Returns:
//Return type: void
//*****************
void outputDailyReport(vector<Ticket> ticketList){
  cout << fixed << setprecision(W1);
  cout << "Daily ticket report:" << endl;
  for (Ticket ticket : ticketList){
    ticket.printTicket();
  }
  cout << "Number of tickets: " << ticketList.size() << endl;
  cout << "Revenues due: $" << getRevenues(ticketList)<< endl;
}

//*****************
//Function name: getRevenues
//Purpose: calculates revenuesDue and then returns the variable
//List of parameters: ticketList
//Returns: revenuesDue
//Return type: double
//*****************
double getRevenues(vector<Ticket> ticketList){
  double revenuesDue = 0.0;
  for (Ticket ticket : ticketList){
    revenuesDue += ticket.getFine();
  }
  return revenuesDue;
}

//*****************
//Function name: processFile
//Purpose: reads "payments.txt" and updates paid member variable in an object of ticketList, paidFine and paidTickets
//List of parameters: &ticketList, &paidFine, &paidTickets
//Returns:
//Return type: void
//*****************
void processFile(vector<Ticket> &ticketList, double &paidFine, int &paidTickets){
  ifstream finPayments;
  finPayments.open("payments.txt");
  //file validation
  if(!finPayments.good()){ //if the file is NOT properly open
    cout << "ERROR! Cannot open the payments.txt file. Program ending" << endl;
    exit(0);
  }
  bool paid;
  for (int i = 0; i < ticketList.size(); i++){
    finPayments >> paid;
    ticketList.at(i).setStatus(paid);
    paidFine += getPaidFine(ticketList.at(i));
    paidTickets += getPaidTickets(ticketList.at(i));
  }
  finPayments.close();
}

//*****************
//Function name: getPaidFine
//Purpose: calculates paidFine and then returns the variable
//List of parameters: tempTicket
//Returns: tempTicket.getFine() if paid is true, or 0.0 if paid is false
//Return type: double
//*****************
double getPaidFine(Ticket tempTicket){
  if (tempTicket.getStatus()) return tempTicket.getFine();
  else return 0.0;
}

//*****************
//Function name: getPaidTickets
//Purpose: calculates paidTickets and then returns the variable
//List of parameters: tempTicket
//Returns: 1 if _aid is true, or 0 if paid is false
//Return type: int
//*****************
int getPaidTickets(Ticket tempTicket){
  if (tempTicket.getStatus()) return 1;
  else return 0;
}

//*****************
//Function name: outputPostProcessFile
//Purpose: outputs the post-processing report
//List of parameters: ticketList, paidFine, paidTicket
//Returns:
//Return type: void
//*****************
void outputPostProcessFile(vector<Ticket> ticketList, double paidFine, int paidTickets){
  cout << "Payment processing complete; new status report:" << endl;
  for (Ticket ticket : ticketList){
    ticket.printTicket();
  }
  cout << "Number paid: " << paidTickets << " (Total: $" << paidFine << ")" << endl;
  cout << "Number unpaid: " << ticketList.size() - paidTickets << " (Total: $" << getRevenues(ticketList) - paidFine << ")" << endl;
}

//*****************
//Function name: plagiarismRequirement
//Purpose: outputs Plagiarism Requirement
//List of parameters:
//Returns:
//Return type: void
//*****************
void plagiarismRequirement(){
  cout << endl;
  cout << "I attest that this code is my original programming work, and that I received" << endl;
  cout << "no help creating it. I attest that I did not copy this code or any portion of this" << endl;
  cout << "code from any source." << endl;
}
