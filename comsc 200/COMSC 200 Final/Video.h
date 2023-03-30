#ifndef VIDEO_H
#define VIDEO_H

#include <string>
using namespace std;

/*
-----------------------
   Video
-----------------------
 - title: string
 - inventoryNumber: int
 - checkedOut: bool
 - overdue: bool
 - customer: int //represents which customer is currently renting the video
-----------------------
 + Video (string, int, bool, bool, int)
 + getTitle() : string
 + getInvNr() : int
 + getCheckedOut() : bool
 + getOverdue() : bool
 + getCustomer() : int
 + setCheckedOut(bool) : void
 + setTitle(string) : void
 + setInvNr(int) : void
 + setCustomer(int) : void
----------------------
*/

class Video {
private:
  string title;
  int inventoryNumber;
  bool checkedOut;
  bool overdue;
  int customer;
public:
  //constructors
  Video() {
    title = "";
    inventoryNumber = 0;;
    checkedOut = false;
    overdue = false;
    customer = 0;
  }

  Video(string title, int invNr, bool checkedOut, bool overdue, int customer) {
    setTitle(title);
    setInvNr(invNr);
    setCheckedOut(checkedOut);
    setOverdue(overdue);
    setCustomer(customer);
  }

  //accessors
  string getTitle() {return title;}
  int getInvNr() {return inventoryNumber;}
  bool getCheckedOut() {return checkedOut;}
  bool getOverdue() {return overdue;}
  int getCustomer() {return customer;}

  //mutators
  void setTitle(string title) {this->title = title;}
  void setInvNr(int invNr) {this->inventoryNumber = invNr;}
  void setCheckedOut(bool checkedOut) {this->checkedOut = checkedOut;}
  void setOverdue(bool overdue) {this->overdue = overdue;}
  void setCustomer(int customer) {this->customer = customer;}

  //other methods

};

#endif
