#ifndef CHECK_H
#define CHECK_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Check {
private:
  string payee;
  string date;
  float amount;
  string memo;
  int checkNo;
  string holderName;
  string holderAddress1;
  string holderAddress2;
  string bank;
  string amountInLetter;

  const string CUTTING_LINE = "----------------------------------------------------------------------";
public:
  //constructors
  Check() {
    payee = "";
    date = "";
    amount = 0.0;
    memo = "";
    checkNo = 0;
    holderName = "Donggyu Park";
    holderAddress1 = "1619 Ruth Drive";
    holderAddress2 = "Pleasant Hill, CA 94523";
    bank = "Wells Fargo";
    amountInLetter = "^^";
  }

  Check(string payee, string date, float amount, string memo, int checkNo) {
    this->payee = payee;
    this->date = date;
    this->amount = amount;
    this->memo = memo;
    this->checkNo = checkNo;
    holderName = "Donggyu Park";
    holderAddress1 = "1619 Ruth Drive";
    holderAddress2 = "Pleasant Hill, CA 94523";
    bank = "Wells Fargo";
    amountInLetter = "^^";
  }


  //accessors
  string getPayee() {return payee;}
  string getDate() {return date;}
  float getAmount() {return amount;}
  string getMemo() {return memo;}
  int getCheckNo() {return checkNo;}

  //other methods
  void print() {
    cout << fixed << setprecision(2) << setfill('-');
    cout << "----------------------------------------------------------------------" << endl;
    cout << holderName << "Check #" << getCheckNo() << endl;
    cout << holderAddress1 << endl;
    cout << holderAddress2 << date  << endl;
    cout << endl;
    cout << "Pay to the order of: " << payee << '$' << amount << endl;
    cout << amountInLetter << endl;
    cout << endl;
    cout << bank << endl;
    cout << "Memo: " << memo << "Signature: " << holderName << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cout << endl;
  }

};

#endif
