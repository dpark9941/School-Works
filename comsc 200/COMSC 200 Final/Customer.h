#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;
/*
-----------------------
   Customer
-----------------------
 - customerNumber: int
 - lastName: string //last name
 - firstName: string //first name
-----------------------
 + getCustNr() : int
 + getLName() : string
 + getFName() : string
 + setFName(string) : void
 + setLName(string) : void
 + setCustNr(int) : void
----------------------
*/

class Customer {
private:
  int customerNumber;
  string lastName;
  string firstName;
public:
  //constructors
  Customer() {
    customerNumber = 0;
    lastName = "";
    firstName = "";
  }

  Customer(int custNr, string lName, string fName) {
    setCustNr(custNr);
    setLName(lName);
    setFName(fName);
  }

  //accessors
  int getCustNr() {return customerNumber;}
  string getLName() {return lastName;}
  string getFName() {return firstName;}

  //mutators
  void setCustNr(int custNr) {this->customerNumber = custNr;}
  void setLName(string lName) {this->lastName = lName;}
  void setFName(string fName) {this->firstName = fName;}

  //other methods

};


#endif
